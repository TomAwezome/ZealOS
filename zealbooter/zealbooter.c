#include <stdint.h>
#include <stddef.h>
#include <limine.h>
#include <lib.h>

static volatile struct limine_module_request module_request = {
    .id = LIMINE_MODULE_REQUEST,
    .revision = 0
};

static volatile struct limine_hhdm_request hhdm_request = {
    .id = LIMINE_HHDM_REQUEST,
    .revision = 0
};

static volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

static volatile struct limine_smbios_request smbios_request = {
    .id = LIMINE_SMBIOS_REQUEST,
    .revision = 0
};

struct CZXE {
    uint16_t jmp;
    uint8_t module_align_bits;
    uint8_t reserved;
    uint32_t signature;
    int64_t org;
    int64_t patch_table_offset;
    int64_t file_size;
} __attribute__((packed));

struct CDate {
    uint32_t time;
    int32_t date;
} __attribute__((packed));

#define MEM_E820_ENTRIES_NUM 48

#define MEM_E820T_USABLE 1
#define MEM_E820T_RESERVED 2
#define MEM_E820T_ACPI 3
#define MEM_E820T_ACPI_NVS 4
#define MEM_E820T_BAD_MEM 5
#define MEM_E820T_PERM_MEM 7

struct CMemE820 {
    uint8_t *base;
    int64_t len;
    uint8_t type, pad[3];
} __attribute__((packed));

struct CGDTEntry {
    uint64_t lo, hi;
} __attribute__((packed));

#define MP_PROCESSORS_NUM 128

struct CGDT {
    struct CGDTEntry null;
    struct CGDTEntry boot_ds;
    struct CGDTEntry boot_cs;
    struct CGDTEntry cs32;
    struct CGDTEntry cs64;
    struct CGDTEntry cs64_ring3;
    struct CGDTEntry ds;
    struct CGDTEntry ds_ring3;
    struct CGDTEntry tr[MP_PROCESSORS_NUM];
    struct CGDTEntry tr_ring3[MP_PROCESSORS_NUM];
} __attribute__((packed));

struct CSysLimitBase {
    uint16_t limit;
    uint8_t *base;
};

struct CKernel {
    struct CZXE h;
    uint32_t jmp;
    uint32_t boot_src;
    uint32_t boot_blk;
    uint32_t boot_patch_table_base;
    uint32_t sys_run_level;
    struct CDate compile_time;
    // U0 start
    uint32_t boot_base;
    uint16_t mem_E801[2];
    struct CMemE820 mem_E820[MEM_E820_ENTRIES_NUM];
    uint64_t mem_physical_space;
    struct {
        uint16_t limit;
        uint8_t *base;
    } __attribute__((packed)) sys_gdt_ptr;
    uint16_t sys_pci_buses;
    struct CGDT sys_gdt __attribute__((aligned(16)));
    uint64_t sys_framebuffer_addr;
    uint64_t sys_framebuffer_width;
    uint64_t sys_framebuffer_height;
    uint64_t sys_framebuffer_pitch;
    uint8_t sys_framebuffer_bpp;
    uint64_t sys_smbios_entry;
	uint32_t sys_disk_uuid_a;
	uint16_t sys_disk_uuid_b;
	uint16_t sys_disk_uuid_c;
	uint8_t sys_disk_uuid_d[8];
} __attribute__((packed));

#define BOOT_SRC_RAM 2
#define BOOT_SRC_HDD 3
#define BOOT_SRC_DVD 4
#define RLF_16BIT 0b01
#define RLF_VESA  0b10

extern symbol trampoline, trampoline_end;

struct E801 {
    size_t lowermem;
    size_t uppermem;
};

static struct E801 get_E801(void) {
    struct E801 E801 = {0};

    for (size_t i = 0; i < memmap_request.response->entry_count; i++) {
        struct limine_memmap_entry *entry = memmap_request.response->entries[i];

        if (entry->type == LIMINE_MEMMAP_USABLE) {
            if (entry->base == 0x100000) {
                if (entry->length > 0xf00000) {
                    E801.lowermem = 0x3c00;
                } else {
                    E801.lowermem = entry->length / 1024;
                }
            }
            if (entry->base <= 0x1000000 && entry->base + entry->length > 0x1000000) {
                E801.uppermem = ((entry->length - (0x1000000 - entry->base)) / 1024) / 64;
            }
        }
    }

    return E801;
}

void _start(void) {
    struct limine_file *kernel = module_request.response->modules[0];
    struct CKernel *CKernel = kernel->address;

    size_t trampoline_size = (uintptr_t)trampoline_end - (uintptr_t)trampoline;

    size_t boot_stack_size = 32768;

    uintptr_t final_address = (uintptr_t)-1;
    for (size_t i = 0; i < memmap_request.response->entry_count; i++) {
        struct limine_memmap_entry *entry = memmap_request.response->entries[i];

        if (entry->type != LIMINE_MEMMAP_USABLE) {
            continue;
        }

        if (entry->length >= ALIGN_UP(kernel->size + trampoline_size, 16) + boot_stack_size) {
            final_address = entry->base;
            break;
        }
    }
    if (final_address == (uintptr_t)-1) {
        // TODO: Panic. Show something?
        for (;;);
    }

    struct limine_framebuffer *fb = framebuffer_request.response->framebuffers[0];
    CKernel->sys_framebuffer_pitch = fb->pitch;
    CKernel->sys_framebuffer_width = fb->width;
    CKernel->sys_framebuffer_height = fb->height;
    CKernel->sys_framebuffer_bpp = fb->bpp;
    CKernel->sys_framebuffer_addr = (uintptr_t)fb->address - hhdm_request.response->offset;

    void *CORE0_32BIT_INIT;
    for (uint64_t *p = (uint64_t *)CKernel; ; p++) {
        if (*p != 0xaa23c08ed10bd4d7) {
            continue;
        }
        p++;
        if (*p != 0xf6ceba7d4b74179a) {
            continue;
        }
        p++;
        CORE0_32BIT_INIT = p;
        break;
    }

    CORE0_32BIT_INIT -= (uintptr_t)kernel->address;
    CORE0_32BIT_INIT += final_address;

    if (kernel->media_type == LIMINE_MEDIA_TYPE_OPTICAL)
        CKernel->boot_src = BOOT_SRC_DVD;
    else if (kernel->media_type == LIMINE_MEDIA_TYPE_GENERIC)
        CKernel->boot_src = BOOT_SRC_HDD;
    else
        CKernel->boot_src = BOOT_SRC_RAM;
    CKernel->boot_blk = 0;
    CKernel->boot_patch_table_base = (uintptr_t)CKernel + CKernel->h.patch_table_offset;
    CKernel->boot_patch_table_base -= (uintptr_t)kernel->address;
    CKernel->boot_patch_table_base += final_address;

    CKernel->sys_run_level = RLF_VESA | RLF_16BIT;

    CKernel->boot_base = (uintptr_t)&CKernel->jmp - (uintptr_t)kernel->address;
    CKernel->boot_base += final_address;

    CKernel->sys_gdt_ptr.limit = sizeof(CKernel->sys_gdt) - 1;
    CKernel->sys_gdt_ptr.base = (void *)&CKernel->sys_gdt - (uintptr_t)kernel->address;
    CKernel->sys_gdt_ptr.base += final_address;

    CKernel->sys_pci_buses = 256;

    struct E801 E801 = get_E801();
    CKernel->mem_E801[0] = E801.lowermem;
    CKernel->mem_E801[1] = E801.uppermem;

    for (size_t i = 0; i < memmap_request.response->entry_count; i++) {
        struct limine_memmap_entry *entry = memmap_request.response->entries[i];

        int our_type;
        switch (entry->type) {
            case LIMINE_MEMMAP_BOOTLOADER_RECLAIMABLE:
            case LIMINE_MEMMAP_KERNEL_AND_MODULES:
            case LIMINE_MEMMAP_USABLE:
                our_type = MEM_E820T_USABLE; break;
            case LIMINE_MEMMAP_ACPI_RECLAIMABLE:
                our_type = MEM_E820T_ACPI; break;
            case LIMINE_MEMMAP_ACPI_NVS:
                our_type = MEM_E820T_ACPI_NVS; break;
            case LIMINE_MEMMAP_BAD_MEMORY:
                our_type = MEM_E820T_BAD_MEM; break;
            case LIMINE_MEMMAP_RESERVED:
            default:
                our_type = MEM_E820T_RESERVED; break;
        }

        CKernel->mem_E820[i].base = (void *)entry->base;
        CKernel->mem_E820[i].len = entry->length;
        CKernel->mem_E820[i].type = our_type;
    }

    void *sys_gdt_ptr = (void *)&CKernel->sys_gdt_ptr - (uintptr_t)kernel->address;
    sys_gdt_ptr += final_address;

    void *sys_smbios_entry = smbios_request.response->entry_32;
    CKernel->sys_smbios_entry = (uintptr_t)sys_smbios_entry - hhdm_request.response->offset;

	CKernel->sys_disk_uuid_a = kernel->gpt_disk_uuid.a;
	CKernel->sys_disk_uuid_b = kernel->gpt_disk_uuid.b;
	CKernel->sys_disk_uuid_c = kernel->gpt_disk_uuid.c;
	memcpy(CKernel->sys_disk_uuid_d, kernel->gpt_disk_uuid.d, 8);

    void *trampoline_phys = (void *)final_address + kernel->size;

    uintptr_t boot_stack = ALIGN_UP(final_address + kernel->size + trampoline_size, 16) + boot_stack_size;

    memcpy(trampoline_phys, trampoline, trampoline_size);
    memcpy((void *)final_address, CKernel, kernel->size);

    asm volatile (
        "mov %5, %%rsp;"
        "jmp *%0"
        :
        : "a"(trampoline_phys), "b"(CORE0_32BIT_INIT),
          "c"(sys_gdt_ptr), "S"(CKernel->boot_patch_table_base),
          "D"(CKernel->boot_base), "r"(boot_stack)
        : "memory");

    __builtin_unreachable();
}