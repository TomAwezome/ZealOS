// Main ZealOS header

#help_index ""
extern class CAOT;
extern class CAOTHeapGlobal;
extern class CAOTImportExport;
extern class CCPU;
extern class CDC;
extern class CDirContext;
extern class CDoc;
extern class CFile;
extern class CHashClass;
extern class CHashFun;
extern class CHeapCtrl;
extern class CIntermediateCode;
extern class CJobCtrl;
extern class CTask;

#define NULL		0
#define TRUE		1
#define FALSE 		0
#define ON			1
#define OFF 		0
#define NONE		0 //for use in default arguments
#define I8_MIN		(-0x80)
#define I8_MAX		0x7F
#define U8_MIN		0
#define U8_MAX		0xFF
#define I16_MIN		(-0x8000)
#define I16_MAX		0x7FFF
#define U16_MIN		0
#define U16_MAX		0xFFFF
#define I32_MIN		(-0x80000000)
#define I32_MAX		0x7FFFFFFF
#define U32_MIN		0
#define U32_MAX		0xFFFFFFFF
#define I64_MIN		(-0x8000000000000000)
#define I64_MAX		0x7FFFFFFFFFFFFFFF
#define U64_MIN		0
#define U64_MAX		0xFFFFFFFFFFFFFFFF
#define INVALID_PTR	I64_MAX
#define STR_LEN 	144

//(Int to F64 conversion is signed)
//Turn off 80-bit float constants with $LK,"OPTf_NO_BUILTIN_CONST",A="MN:OPTf_NO_BUILTIN_CONST"$.
#define U64_F64_MAX (0x43F0000000000000(F64))
#define F64_MAX 	(0x7FEFFFFFFFFFFFFF(F64))
#define F64_MIN 	(0xFFEFFFFFFFFFFFFF(F64))
#define inf 		(0x7FF0000000000000(F64))
#define ∞ 			(0x7FF0000000000000(F64))
#define pi			(0x400921FB54442D18(F64))
#define π 			(0x400921FB54442D18(F64))
#define exp_1 		(0x4005BF0A8B145769(F64)) //The number "e"
#define log2_10 	(0x400A934F0979A371(F64))
#define log2_e		(0x3FF71547652B82FE(F64))
#define log10_2 	(0x3FD34413509F79FF(F64))
#define loge_2		(0x3FE62E42FEFA39EF(F64))
#define sqrt2 		(0x3FF6A09E667F3BCD(F64))
#define eps 		(0x3CB0000000000000(F64))

#help_index "Data Types/Simple"
//ZealC union structure is treated as a whole if no member is specified, similar to bit fields.
//See $LK,"::/Demo/SubIntAccess.ZC"$.

U16i union U16
{
	I8i	i8[2];
	U8i	u8[2];
};

I16i union I16
{
	I8i	i8[2];
	U8i	u8[2];
};

U32i union U32
{
	I8i	i8[4];
	U8i	u8[4];
	I16	i16[2];
	U16	u16[2];
};

I32i union I32
{
	I8i	i8[4];
	U8i	u8[4];
	I16	i16[2];
	U16	u16[2];
};

U64i union U64
{
	I8i	i8[8];
	U8i	u8[8];
	I16	i16[4];
	U16	u16[4];
	I32	i32[2];
	U32	u32[2];
};

I64i union I64
{
	I8i	i8[8];
	U8i	u8[8];
	I16	i16[4];
	U16	u16[4];
	I32	i32[2];
	U32	u32[2];
};

#help_index "Math/Complex;Data Types/Complex"
public class Complex
{
	F64 x, y;
};

#help_index "Data Types/Circular Queue"
public class CQueue
{
	CQueue	*next, *last;
};

#help_index "Graphics/Data Types/D3I32;Math/Data Types/D3I32;Data Types/D3I32"
public class CD3I32 //Three dimensional I32 pt
{
	I32	x, y, z;
};
public class CQueueD3I32 //Queue of three dimensional I32 pts
{
	CQueueD3I32 *next, *last;
	CD3I32		 p;
};
#help_index "Math/Data Types;Data Types"
public class CD2I32 //Two dimensional I32 pt
{
	I32 x, y;
};
public class CD2I64 //Two dimensional I64 pt
{
	I64 x, y;
};
public class CD3I64 //Three dimensional I64 pt
{
	I64	x, y, z;
};
public class CD2 //Two dimensional F64 pt
{
	F64	x, y;
};

#help_index "Math/CD3;Data Types/CD3"
public class CD3 //Three dimensional F64 pt
{
	F64 x, y, z;
};

#help_index "Data Types/Queue Vector"
#define QUE_VECT_U8_COUNT	512
public class CQueueVectU8
{
	CQueueVectU8	*next,
					*last;
	I64 			 total_count,
					 node_count,
					 min_idx;
	U8				 body[QUE_VECT_U8_COUNT];
};

#help_index "Data Types/Fifo"
public class CFifoU8
{
	U8	*buf;
	I64  mask,
		 in_ptr,
		 out_ptr;
};
public class CFifoI64
{
	I64 *buf,
		 mask,
		 in_ptr,
		 out_ptr;
};
#help_index "Date/CMOS"
#define CMOS_SEL	0x70 //select which register to access using this port
#define CMOS_DATA 	0x71 //read from or write to register using this port

//CMOS registers
#define CMOSR_SEC 			0x0
#define CMOSR_MIN 			0x2
#define CMOSR_HOUR			0x4
#define CMOSR_DAY_OF_WEEK 	0x6
#define CMOSR_DAY_OF_MONTH	0x7
#define CMOSR_MONTH 		0x8
#define CMOSR_YEAR			0x9
#define CMOSR_STATUS_A		0xA
#define CMOSR_STATUS_B		0xB

//CMOS status flags
#define CMOSF_BINARY		(1 << 2)
#define CMOSF_UPDATING		(1 << 7)

#help_index "Date/CDate"
#define CDATE_YEAR_DAYS 		365.24225
#define CDATE_YEAR_DAYS_INT 	36524225
#define CDATE_BASE_DAY_OF_WEEK	0
public I64 class CDate
{
	U32	time;
	I32	date;
};

#help_index "Date;Date/CDate"
public class CDateStruct
{
	U8	sec10000,
		sec100,
		sec,
		min,
		hour,
		day_of_week,
		day_of_mon,
		mon;
	I32 year;
};

#help_index "Math/ODE"
public class COrder2D3
{
	F64	x, y, z,
		DxDt, DyDt, DzDt;
};

#define MSF_INACTIVE	1
#define MSF_FIXED 		2
public class CMass
{
	CMass		*next, *last;
	COrder2D3	*state, 	//Point to entries in $LK,"CMathODE",A="MN:CMathODE"$.state[]
				*DstateDt;	//Point to entries in $LK,"CMathODE",A="MN:CMathODE"$.DstateDt[]

	U0			 start;
	U32 		 flags,
				 num;
	F64 		 mass,
				 drag_profile_factor;
	U0			 saved_state;
	F64 		 x, y, z,
				 DxDt, DyDt, DzDt;
	U0			 end;
};

#define SSF_INACTIVE		1
#define SSF_NO_COMPRESSION	2
#define SSF_NO_TENSION		4
public class CSpring
{
	CSpring	*next, *last;
	CMass	*end1, *end2;
	F64 	 f, displacement; //set for you to check

	U0		 start;
	U32 	 flags, num, end1_num, end2_num;
	F64 	 const, rest_len;
	U0		 end;
};

//Ordinary Differential Equations
#define ODEF_HAS_MASSES		1
#define ODEF_PAUSED 		2
#define ODEF_STARTED		4
#define ODEF_BUSY 			8

#define ODEf_HAS_MASSES		0
#define ODEf_PAUSED 		1
#define ODEf_STARTED		2
#define ODEf_BUSY 			3

public class CMathODE
{
	CMathODE	*next, *last;
	I64			 flags, n, n_internal;
	CMass		*next_mass,   *last_mass;
	CSpring		*next_spring, *last_spring;
	F64			 drag_v,  //drag proportional to velocity
				 drag_v2, //drag proportional to velocity squared
				 drag_v3, //drag proportional to velocity cubed
				 acceleration_limit, //This clips acceleration
				 base_t,
				 t, t_scale,
				 h, h_min, h_max;

	//This is not precise, just a ballpark.
	//ZealOS CMathODE's are for video games
	//not science.	It bails if it takes
	//too long.
	F64			 min_tolerance, max_tolerance;

	F64			 tolerance_internal,
				*array_base,
				*state,
				*state_internal,
				*DstateDt,
				*state_scale,
				*initial_state,
				*tmp0, *tmp1, *tmp2, *tmp3, *tmp4, *tmp5, *tmp6, *tmp7;
	CTask		*mem_task, *win_task;
	U0		   (*derive)(   CMathODE *o, F64 t, F64 *state, F64 *DstateDt);
	U0		   (*mp_derive)(CMathODE *o, F64 t, I64 cpu_num, F64 *state, F64 *DstateDt);  //If break into parallel pieces.
	CTask	   **slave_tasks;
	I64			 mp_not_done_flags;
	F64			 mp_t, *mp_state, *mp_DstateDt;

	I64			 user_data;
};

#help_index "Processor"
//IDT entry types
#define IDTET_TASK		0x05
#define IDTET_IRQ 		0x0E
#define IDTET_TRAP		0x0F //Same as IRQ but doesnt do CLI.

//Interrupts
//0x00-0x1F are reserved by Intel
#define I_DIV_ZERO		0x00
#define I_SINGLE_STEP 	0x01
#define I_NMI 			0x02
#define I_BPT 			0x03
#define I_PAGE_FAULT	0x0E
//0x20-0x2F are used for hardware
#define I_TIMER 		0x20
//Software Interrupts
#define I_MP_CRASH		0x30
#define I_WAKE			0x31
#define I_DEBUG 		0x32
//See $LK,"ST_INT_NAMES",A="MN:ST_INT_NAMES"$

//You might want to start backward from
//0xFF for your own interrupts.
//See $LK+PU,"IntEntryAlloc",A="MN:IntEntryAlloc"$.
#define I_USER			0x40

#define MP_PROCESSORS_NUM 	128

//Control register flag bits
#define CR0f_PE		0 //Protection Enable (Protected mode)
#define CR0f_MP		1 //Monitor coprocessor
#define CR0f_EM		2 //Emulation of coprocessor
#define CR0f_TS		3 //Task switched, some irrelevant x87 task management stuff
#define CR0f_NE		5 //Numeric error
#define CR0f_PG		31//Enable paging

#define CR0F_PE		(1 << CR0f_PE)
#define CR0F_NE		(1 << CR0f_NE)

#define CR4f_PAE	5 //Physical Address Extension, required by long mode
#define CR4f_PGE	7 //Page-Global Enable
#define CR4f_OSFXSR 9 //FXSAVE/FXRSTOR support enabled

#define CR4F_PAE	(1 << CR4f_PAE)
#define CR4F_PGE	(1 << CR4f_PGE)
#define CR4F_OSFXSR (1 << CR4f_OSFXSR)

#define SYS_START_CR0	(CR0F_PE | CR0F_NE)

#define RFLAGf_CARRY		0
#define RFLAGf_PARITY 		2
#define RFLAGf_AUX_CARRY	4
#define RFLAGf_ZERO 		6
#define RFLAGf_SIGN 		7
#define RFLAGf_TRAP 		8 //Single Step
#define RFLAGf_INT			9
#define RFLAGf_DIR			10
#define RFLAGf_OVERFLOW 	11
#define RFLAGf_IOPL0		12 // I/O Privilege Level
#define RFLAGf_IOPL1		13
#define RFLAGf_NESTED_TASK	14
#define RFLAGf_RESUME 		16
#define RFLAGf_V8086		17
#define RFLAGf_ALIGN_CHECK	18
#define RFLAGf_VINT 		19 //Virtual Interrupt
#define RFLAGf_VINT_PENDING 20
#define RFLAGf_ID 			21

#define RFLAGG_START	0x0000
#define RFLAGG_NORMAL 	(1 << RFLAGf_INT)

//Global Descriptor Table
class CGDTEntry
{
	U64 lo, hi;
};

class CGDT
{
	CGDTEntry null,
			  boot_ds,
			  boot_cs,
			  cs32,
			  cs64, 			//The $LK,"Charter",A="FI:::/Doc/Charter.DD"$ says just ring-0.
			  cs64_ring3, //$LK,"Ring3",A="FI:::/Demo/Lectures/Ring3.ZC"$, in case you want to play around.
			  ds,
			  ds_ring3,
			  tr[MP_PROCESSORS_NUM],
			  tr_ring3[MP_PROCESSORS_NUM];
};

//Interrupt Descriptor Table
class CIDTEntry
{
	U16	offset_low,
		seg_select;
	U8	ist,
		type_attr;
	U16	offset_mid;
	U32	offset_hi,
		zero;
};
#assert sizeof(CIDTEntry) == 16

class CSysLimitBase
{
	U16		 limit;	//Offset of last byte, not size.
	U8		*base;	//&GDT or &IDT
};

#help_index "Memory/Info"
#define MEM_E820_ENTRIES_NUM	256
#define MEM_E820t_USABLE		1
#define MEM_E820t_RESERVED		2
#define MEM_E820t_ACPI			3
#define MEM_E820t_ACPI_NVS		4
#define MEM_E820t_BAD_MEM 		5
#define MEM_E820t_PERM_MEM		7

class CMemE820
{
	U8		*base;
	I64 	 len;
	U8		 type, pad[3];
};

#help_index "Compiler/Internal"
//Loader flags
#define LDF_NO_ABSS 	1
#define LDF_JUST_LOAD 	2
#define LDF_SILENT		4

#define ZXE_SIGNATURE_VAL 	'ZXE' // Zeal Executable
class CZXE
{// $LK,"ZXE Header Generation",A="FF:::/Compiler/CMain.ZC,16 ALIGN"$ by compiler.
	U16 jmp;
	U8	module_align_bits,
		reserved;
	U32 signature;
	I64 org,
		patch_table_offset, //$LK,"Patch Table Generation",A="FF:::/Compiler/CMain.ZC,IET_ABS_ADDR"$
		file_size;
};

class CPatchTableAbsAddr
{
	U8	eit_abs_addr; 	//$LK,"IET_ABS_ADDR",A="MN:IET_ABS_ADDR"$
	U32 abs_address_count;
	U8	zero;
	U32 abs_address[1];
};

//$LK,"CAOTImportExport",A="MN:CAOTImportExport"$ Types. Used in PatchTable.
#define IET_END 			0
//reserved
#define IET_REL_I0			2 //Fictitious
#define IET_IMM_U0			3 //Fictitious
#define IET_REL_I8			4
#define IET_IMM_U8			5
#define IET_REL_I16 		6
#define IET_IMM_U16 		7
#define IET_REL_I32 		8
#define IET_IMM_U32 		9
#define IET_REL_I64 		10
#define IET_IMM_I64 		11
#define IEF_IMM_NOT_REL		1
//reserved
#define IET_REL32_EXPORT		16
#define IET_IMM32_EXPORT		17
#define IET_REL64_EXPORT		18 //Not implemented
#define IET_IMM64_EXPORT		19 //Not implemented
#define IET_ABS_ADDR			20
#define IET_CODE_HEAP 			21 //Not really used
#define IET_ZEROED_CODE_HEAP	22 //Not really used
#define IET_DATA_HEAP 			23
#define IET_ZEROED_DATA_HEAP	24 //Not really used
#define IET_MAIN				25

#help_index "Graphics/VBE"

#define BLACK32			0x000000
#define WHITE32			0xFFFFFF
#define VBE_MODES_NUM	32

class CVBEInfo
{
	U8	signature[4];
	U16 version;
	U32 oem,
		capabilities,
		video_modes;
	U16 total_memory,
		software_revision;
	U32 vendor,
		product_name,
		product_revision;
	U8	reserved[222],
		oem_data[256];
};
#assert sizeof(CVBEInfo) == 512

class CVBEMode
{
	U16 attributes,
		pad[7],
		pitch,
		width,
		height;
	U8	pad[3],
		bpp,
		pad,
		memory_model,
		pad[12];
	U32	framebuffer;
	U16	pad[9];
	U32 max_pixel_clock;
	U8	reserved[190];
};
#assert sizeof(CVBEMode) == 256

class CVideoInfo
{
	U16 width;
	U16 height;
};

#define ZEALBOOTER_LIMINE_SIGNATURE_1	0xaa23c08ed10bd4d7; // See $LK+PU,"CORE0_32BIT_INIT",A="FF:::/Kernel/KStart32.ZC,JMP @@"$
#define ZEALBOOTER_LIMINE_SIGNATURE_2	0xf6ceba7d4b74179a; //

#help_index "Boot"
class CKernel
{//Must match $LK,"OSStartUp",A="FF:::/Kernel/KStart16.ZC,MEM_BOOT_BASE"$
	CZXE			h;
	U32				jmp,
					boot_src,
					boot_blk,
					boot_patch_table_base,
					sys_run_level;
	CDate			compile_time;

	U0				start;
	U32				boot_base;
	U16				mem_E801[2];
	CMemE820		mem_E820[MEM_E820_ENTRIES_NUM];
	U64				mem_physical_space;
	CSysLimitBase	sys_gdt_ptr;
	U16				sys_pci_buses;
	;$$ = ($$ + 15) & -16;
	CGDT			sys_gdt;
	U64				sys_framebuffer_addr;
	U64				sys_framebuffer_width;
	U64				sys_framebuffer_height;
	U64				sys_framebuffer_pitch;
	U8				sys_framebuffer_bpp;
	U64				sys_smbios_entry;
	U64				sys_disk_uuid[2];
	U32				sys_boot_stack;
	Bool			sys_is_uefi_booted;
	U8				sys_bootloader_id;
	CVideoInfo		sys_framebuffer_list[VBE_MODES_NUM];
};

// Bootloader IDs
#define BL_ZEAL		0
#define BL_LIMINE	1

//Run-Levels
#define RLf_16BIT 					0
#define RLf_VESA					1
#define RLf_32BIT 					2
#define RLf_PATCHED 				3
#define RLf_16MEG_SYS_CODE_BP 		4
#define RLf_64BIT 					5
#define RLf_16MEG_SYSTEM_HEAP_CTRL	6
#define RLf_FULL_HEAPS				7
#define RLf_RAW 					8
#define RLf_INTERRUPTS				9
#define RLf_BLKDEV					10
#define RLf_MP						11
#define RLf_COMPILER				12
#define RLf_DOC 					13
#define RLf_WINMGR					14
#define RLf_REGISTRY				15
#define RLf_HOME					16
#define RLf_AUTOCOMPLETE			17
#define RLf_SYSTEM_SERVER 			18
#define RLf_ONCE_SYSTEM 			19
#define RLf_ONCE_USER 				20

#define RLF_16BIT 					(1 << RLf_16BIT)
#define RLF_VESA					(1 << RLf_VESA)
#define RLF_32BIT 					(1 << RLf_32BIT)
#define RLF_PATCHED 				(1 << RLf_PATCHED)
#define RLF_16MEG_SYS_CODE_BP 		(1 << RLf_16MEG_SYS_CODE_BP)
#define RLF_64BIT 					(1 << RLf_64BIT)
#define RLF_16MEG_SYSTEM_HEAP_CTRL	(1 << RLf_16MEG_SYSTEM_HEAP_CTRL)
#define RLF_FULL_HEAPS				(1 << RLf_FULL_HEAPS)
#define RLF_RAW 					(1 << RLf_RAW)
#define RLF_INTERRUPTS				(1 << RLf_INTERRUPTS)
#define RLF_BLKDEV					(1 << RLf_BLKDEV)
#define RLF_MP						(1 << RLf_MP)
#define RLF_COMPILER				(1 << RLf_COMPILER)
#define RLF_DOC 					(1 << RLf_DOC)
#define RLF_WINMGR					(1 << RLf_WINMGR)
#define RLF_REGISTRY				(1 << RLf_REGISTRY)
#define RLF_HOME					(1 << RLf_HOME)
#define RLF_AUTOCOMPLETE			(1 << RLf_AUTOCOMPLETE)
#define RLF_SYSTEM_SERVER 			(1 << RLf_SYSTEM_SERVER)
#define RLF_ONCE_SYSTEM 			(1 << RLf_ONCE_SYSTEM)
#define RLF_ONCE_USER 				(1 << RLf_ONCE_USER)

#help_index "Processor"

//Model specific registers.
#define IA32F_SCE 		0x001
#define IA32F_LME 		0x100
#define IA32_LAPIC_BASE 0x01B
#define IA32_EFER 		0xC0000080
#define IA32_FS_BASE	0xC0000100
#define IA32_GS_BASE	0xC0000101

//Programmable Interrupt Controller
#define PIC_1		0x20
#define PIC_1_DATA 	0x21
#define PIC_2		0xA0
#define PIC_2_DATA 	0xA1
#define PIC_INIT	0x11
#define PIC_EOI 	0x20 //End of interrupt

//Local Advanced Programmable Interrupt Controller
#define LAPIC_BASE					0xFEE00000
#define LAPIC_APIC_ID 				(LAPIC_BASE + 0x020)
#define LAPIC_APIC_VERSION			(LAPIC_BASE + 0x030)
#define LAPIC_TASK_PRIORITY 		(LAPIC_BASE + 0x080)
#define LAPIC_ARBITRATION_PRIORITY	(LAPIC_BASE + 0x090)
#define LAPIC_PROCESSOR_PRIORITY 	(LAPIC_BASE + 0x0A0)
#define LAPIC_EOI 					(LAPIC_BASE + 0x0B0)
#define LAPIC_LOG_DST 				(LAPIC_BASE + 0x0D0)
#define LAPIC_DFR 					(LAPIC_BASE + 0x0E0)
#define LAPIC_LDR 					(LAPIC_BASE + 0x0D0)

#define LAPICF_APIC_ENABLED 		0x100
#define LAPIC_SVR 					(LAPIC_BASE + 0x0F0)

#define LAPIC_ISR 					(LAPIC_BASE + 0x100)
#define LAPIC_TMR 					(LAPIC_BASE + 0x180)
#define LAPIC_IRR 					(LAPIC_BASE + 0x200)
#define LAPIC_ICR_LOW 				(LAPIC_BASE + 0x300)
#define LAPIC_ICR_HIGH				(LAPIC_BASE + 0x310)

#define LAPIC_LVT_TIMER 			(LAPIC_BASE + 0x320)
#define LAPIC_LVT_THERMAL 			(LAPIC_BASE + 0x330)
#define LAPIC_LVT_PERF				(LAPIC_BASE + 0x340)
#define LAPIC_LVT_LINT0 			(LAPIC_BASE + 0x350)
#define LAPIC_LVT_LINT1 			(LAPIC_BASE + 0x360)
#define LAPIC_LVT_ERR 				(LAPIC_BASE + 0x370)

#define MPN_VECT					0x97
#define MP_VECT_ADDR				(MPN_VECT * 0x1000)

//I/O APIC Memory mapped window
#define IOAPIC_REG	0xFEC00000 //U8
#define IOAPIC_DATA 0xFEC00010 //U32
//I/O APIC Registers
#define IOAPICID	0x00
#define IOAPICVER 	0x01
#define IOAPICARB 	0x02
#define IOREDTAB	0x10

class CAP16BitInit
{//AP Multicore
	U32				jmp;
	CSysLimitBase	ap_gdt_ptr;
};

#help_index "Time/PIT"
#help_file "::/Doc/PIT.DD"
//Programmable Interval Timer
#define PIT_0		0x40
#define PIT_2		0x42
#define PIT_CMD 	0x43

#define PIT_CMDF_OPMODE_RATE_GEN	0x04
#define PIT_CMDF_OPMODE_SQUARE_WAVE 0x06
#define PIT_CMDF_ACCESS_WORD		0x30
#define PIT_CMDF_CHANNEL0 			0x00
#define PIT_CMDF_CHANNEL2 			0x80

public class CCountsGlobals
{
	I64 	jiffies,				//$LK,"JIFFY_FREQ",A="MN:JIFFY_FREQ"$
			timer,					//$LK,"SYS_TIMER_FREQ",A="MN:SYS_TIMER_FREQ"$. Use $LK,"SysTimerRead",A="MN:SysTimerRead"$().
			time_stamp_freq,
			time_stamp_kHz_freq,
			time_stamp_freq_initial; //Initial freq, sampled once at boot time.
	Bool	time_stamp_calibrated;
};

#define JIFFY_FREQ			1000  // Hz
#define CDATE_FREQ			49710 // Hz
#define SYS_TIMER_FREQ		(18333 * 65536 / 1000) //Hz
#define SYS_TIMER0_PERIOD	(65536 * 182 / 10 / JIFFY_FREQ)

#help_index "Call"
//Function Stack Frame
#define SF_RBP	0x00
#define SF_RIP	0x08
#define SF_ARG1 0x10
#define SF_ARG2 0x18
#define SF_ARG3 0x20
#define SF_ARG4 0x28
#define SF_ARG5 0x30
#define SF_ARG6 0x38
#define SF_ARG7 0x40
#define SF_ARG8 0x48

class CRAXRBXRCXRDX
{
	I64 rax, rbx, rcx, rdx;
};

//Asm callable function pointers.
//They work with $LK,"CallExtNum",A="MN:CallExtNum"$() when calling from ZealC.
#define EXT_WIN_TO_TOP		0
#define EXT_WIN_FOCUS 		1
#define EXT_HEAPLOG_MALLOC	2
#define EXT_HEAPLOG_FREE	3
#define EXT_DEBUG_RESUME	4
#define EXT_EXTS_NUM		5

#help_index "Processor"
#define DEFAULT_CACHE_LINE_WIDTH	128

//Semaphores
class CSema
{
	Bool val, pad[DEFAULT_CACHE_LINE_WIDTH - 1];
};
#define SEMA_DEBUG					0
#define SEMA_RECORD_MACRO 			1
#define SEMA_SYS_TIMER				2
#define SEMA_SYS_DATE 				3
#define SEMA_DEBUG_MODE 			4
#define SEMA_SOUND					5
#define SEMA_HEAPLOG_ACTIVE 		6
#define SEMA_HEAPLOG_LOCK 			7
#define SEMA_REFRESH_IN_PROGRESS	8
#define SEMA_FLUSH_VBE_IMAGE		9
#define SEMA_SINGLE_USER			10
#define SEMA_DISK_CACHE 			11
#define SEMA_FAR_CALL32 			12
#define SEMA_DEV_MEM				13
#define SEMA_VGA					14
#define SEMA_UPDATE_WIN_Z_BUF		15
#define SEMA_TT 					16
#define SEMA_MUTE 					17
#define SEMA_JUST_PUMP_MESSAGES		18
#define SEMA_TMBEAT 				19
#define SEMA_FIX					20
#define SEMA_SEMAS_NUM				21

#define CTRL_ALT_DEL	0
#define CTRL_ALT_C		1
#define CTRL_ALT_X		2
#define CTRL_ALT_N		3

#help_index "Hash"
public class CHash
{//See $LK,"Hash",A="HI:Hash"$
	CHash	*next;
	U8		*str;
	U32		 type,
			 use_count; // inc'ed every time search found, never dec'ed.
};

public class CHashTable
{
	CHashTable	*next;
	I64			 mask, locked_flags;
	CHash	   **body;
};

#help_index "Hash/System"
//Hash table types: $LK,"ST_HTT_TYPES",A="FF:::/Kernel/KDefine.ZC,ST_HTT_TYPES"$
#define HTt_EXPORT_SYS_SYM	0
#define HTt_IMPORT_SYS_SYM	1
#define HTt_DEFINE_STR		2
#define HTt_GLOBAL_VAR		3
#define HTt_CLASS 			4
#define HTt_INTERNAL_TYPE 	5
#define HTt_FUN 			6
#define HTt_WORD			7
#define HTt_DICT_WORD 		8
#define HTt_KEYWORD 		9
#define HTt_ASM_KEYWORD 	10
#define HTt_OPCODE			11
#define HTt_REG 			12
#define HTt_FILE			13
#define HTt_MODULE			14
#define HTt_HELP_FILE 		15
#define HTt_FRAME_PTR 		16
#define HTt_TYPES_NUM 		17

#define HTf_PRIVATE 		23
#define HTf_PUBLIC			24
#define HTf_EXPORT			25
#define HTf_IMPORT			26
#define HTf_IMM 			27
#define HTf_GOTO_LABEL		28
#define HTf_RESOLVED		29
#define HTf_UNRESOLVED		30
#define HTf_LOCAL 			31

#define HTT_INVALID 		0
#define HTT_EXPORT_SYS_SYM	0x00001 //CHashExport
#define HTT_IMPORT_SYS_SYM	0x00002 //CHashImport
#define HTT_DEFINE_STR		0x00004 //CHashDefineStr
#define HTT_GLOBAL_VAR		0x00008 //CHashGlobalVar
#define HTT_CLASS 			0x00010 //CHashClass
#define HTT_INTERNAL_TYPE 	0x00020 //CHashClass
#define HTT_FUN 			0x00040 //CHashFun
#define HTT_WORD			0x00080 //CHashAC only in AutoComplete table
#define HTT_DICT_WORD 		0x00100 //CHashGeneric only in AutoComplete tbl
#define HTT_KEYWORD 		0x00200 //CHashGeneric $LK,"KEYWORD",A="FF:::/Compiler/OpCodes.DD,KEYWORD"$
#define HTT_ASM_KEYWORD 	0x00400 //CHashGeneric $LK,"ASM_KEYWORD",A="FF:::/Compiler/OpCodes.DD,ASM_KEYWORD"$
#define HTT_OPCODE			0x00800 //CHashOpcode
#define HTT_REG 			0x01000 //CHashReg
#define HTT_FILE			0x02000 //CHashGeneric
#define HTT_MODULE			0x04000 //CHashGeneric
#define HTT_HELP_FILE 		0x08000 //CHashSrcSym
#define HTT_FRAME_PTR 		0x10000 //CHashGeneric
#define HTG_TYPE_MASK 		0x1FFFF

#define HTF_PRIVATE 		0x00800000
#define HTF_PUBLIC			0x01000000
#define HTF_EXPORT			0x02000000
#define HTF_IMPORT			0x04000000
#define HTF_IMM 			0x08000000
#define HTF_GOTO_LABEL		0x10000000
#define HTF_RESOLVE 		0x20000000
#define HTF_UNRESOLVED		0x40000000
#define HTF_LOCAL 			0x80000000
#define HTG_FLAGS_MASK		0xFF000000

#define HTG_SRC_SYM 		(HTT_DEFINE_STR | HTT_GLOBAL_VAR | HTT_FUN | HTT_CLASS | HTT_EXPORT_SYS_SYM | HTT_HELP_FILE)
#define HTG_ALL 			-1

#define KERNEL_MODULE_NAME	"/Kernel/Kernel"

class CDebugInfo
{
	U32 	min_line, max_line;
	U32 	body[1]; //Code heap is 32-bit value
};

public class CHashSrcSym:CHash
{
	U8					*src_link,
						*idx;
	CDebugInfo			*debug_info;
	U8					*import_name;
	CAOTImportExport	*ie_list;
};

public class CHashGeneric:CHash
{
	I64	user_data0, user_data1, user_data2;
};

#define REGT_NONE 	0
#define REGT_R8 	1
#define REGT_R16	2
#define REGT_R32	3
#define REGT_R64	4
#define REGT_SEG	5
#define REGT_FSTACK	6
#define REGT_MM 	7
#define REGT_XMM	8

public class CHashReg:CHash
{
	U8	reg_num, reg_type;
};

public class CHashAC:CHash
{
	I32	num;
	U32 hits;
};

public class CHashExport:CHashSrcSym
{
	I64	val;
};

public class CHashImport:CHashSrcSym
{
	U8	*module_base,
		*module_header_entry;
};

#help_index "Compiler/Internal"
#define PTR_STARS_NUM 	3

//Member List Flags
#define MLF_DEFAULT_AVAILABLE 		1
#define MLF_LASTCLASS 				2
#define MLF_STR_DEFAULT_AVAILABLE 	4
#define MLF_FUN 					8
#define MLF_DOT_DOT_DOT 			16
#define MLF_NO_UNUSED_WARN			32
#define MLF_STATIC					64

public class CArrayDim
{
	CArrayDim	*next;
	I64			 count, total_count;
};

#define MLMF_IS_STR 	1
public class CMemberListMeta
{
	CMemberListMeta	*next;
	U8				*str;
	I64				 flags,
					 user_data;
};

public class CMemberList
{
	CMemberList		*next, *left, *right,
					*left_class_base, *right_class_base; //For finding duplicate class local variables.
	U8				*str;
	CHashClass		*member_class, *member_class_base;
	CMemberListMeta	*meta;
	U32				 use_count;
	U16				 flags;
	I8				 reg, pad;
	I64				 offset, size;
	CArrayDim		 dim;
	U8				*static_data;
	union
	{
		I64 static_data_rip;
		I64 default_val;
	}
	CHashFun		*fun_ptr;
};

class CExternUsage
{
	CExternUsage	*next;
	I64				 rip;
};

#help_index "Hash/System;Compiler/Internal"
public class CHashDefineStr:CHashSrcSym
{
	U8		*data, **sub_idx;
	I64 	 count;
};

#define Cf_EXTERN 						0
#define Cf_INTERNAL_TYPE				1

public class CHashClass:CHashSrcSym
{//See $LK,"ParseClassNew",A="MN:ParseClassNew"$(). base_class of $LK,"CHashFun",A="MN:CHashFun"$
	I64 		 size, neg_offset;
	U32 		 member_count;
	U8			 ptr_stars_count, raw_type;
	U16 		 flags;
	CMemberList	*member_list_and_root, //Head of linked list and head of tree.
				*member_class_base_root, //For finding duplicate class local variables.
				*last_in_member_list;
	CHashClass	*base_class,
				*fwd_class;
};

//Function flags
#define Ff_INTERRUPT		8
#define Ff_HASERRCODE 		9
#define Ff_ARGPOP 			10
#define Ff_NOARGPOP 		11
#define Ff_INTERNAL 		12
#define Ff__EXTERN			13
#define Ff_DOT_DOT_DOT		14
#define Ff_RET1 			15

public class CHashFun:CHashClass
{//See $LK,"ParseFunNew",A="MN:ParseFunNew"$().
	CHashClass		*return_class;
	U32				 arg_count, pad,
					 used_reg_mask, clobbered_reg_mask;
	U8				*exe_addr;
	CExternUsage	*ext_list;
};

//Global Var Flags
#define GVF_FUN 		1
#define GVF_IMPORT		2
#define GVF_EXTERN		4
#define GVF_DATA_HEAP 	8
#define GVF_ALIAS 		16
#define GVF_ARRAY 		32

public class CHashGlobalVar:CHashSrcSym
{
	I64 		 size, flags;
	CHashClass	*var_class;
	CHashFun	*fun_ptr;
	CArrayDim	 dim;
	U8			*data_addr;
	union
	{
		I64				 data_addr_rip;
		CAOTHeapGlobal	*heap_global;
	}
};
#assert offset(CHashClass.size) == offset(CHashGlobalVar.size)

#help_index "DolDoc"
//See $LK,"TextBase Layer",A="HI:TextBase Layer"$.
#define ATTRF_BLINK 		0x10000000
#define ATTRF_INVERT		0x20000000
#define ATTRF_SEL 			0x40000000
#define ATTRF_UNDERLINE		0x80000000

#define ATTRf_BLINK 		28
#define ATTRf_INVERT		29
#define ATTRf_SEL 			30
#define ATTRf_UNDERLINE 	31

//CDocEntry.type codes (Low 8 bits)
#define DOCT_TEXT 				0
#define DOCT_NEW_LINE 			1
#define DOCT_SOFT_NEW_LINE		2
#define DOCT_TAB				3
#define DOCT_PAGE_BREAK 		4
#define DOCT_CURSOR 			5
#define DOCT_MARKER 			6
#define DOCT_PROMPT 			7
#define DOCT_CLEAR				8
#define DOCT_PAGE_LEN 			9
#define DOCT_LEFT_MARGIN		10
#define DOCT_RIGHT_MARGIN 		11
#define DOCT_HEADER 			12
#define DOCT_FOOTER 			13
#define DOCT_INDENT 			14
#define DOCT_FOREGROUND 		15
#define DOCT_BACKGROUND 		16
#define DOCT_DEFAULT_FOREGROUND 17
#define DOCT_DEFAULT_BACKGROUND 18
#define DOCT_WORD_WRAP			19
#define DOCT_HIGHLIGHT			20
#define DOCT_BLINK				21
#define DOCT_INVERT 			22
#define DOCT_UNDERLINE			23
#define DOCT_SHIFTED_X			24
#define DOCT_SHIFTED_Y			25
#define DOCT_CURSOR_MOVEMENT	26
#define DOCT_ANCHOR 			27
#define DOCT_LINK 				28
#define DOCT_BTTN 				29
#define DOCT_DATA 				30
#define DOCT_CHECK_BOX			31
#define DOCT_LIST 				32
#define DOCT_MACRO				33
#define DOCT_MENU_VAL 			34
#define DOCT_HEX_ED 			35
#define DOCT_TREE 				36
#define DOCT_SPRITE 			37
#define DOCT_INS_BIN			38
#define DOCT_INS_BIN_SIZE 		39
#define DOCT_SONG 				40
#define DOCT_HTML_CODE			41
#define DOCT_ERROR				42

#define DOCT_TYPES_NUM			43

//CDocEntry.type flags upper bits
#define DOCET_BLINK 		ATTRF_BLINK
#define DOCET_INVERT		ATTRF_INVERT
#define DOCET_SEL 			ATTRF_SEL
#define DOCET_UNDERLINE 	ATTRF_UNDERLINE
#define DOCG_BL_IV_UL 		0xB0000000

#define DOCEt_BLINK 		ATTRf_BLINK
#define DOCEt_INVERT		ATTRf_INVERT
#define DOCEt_SEL 			ATTRf_SEL
#define DOCEt_UNDERLINE 	ATTRf_UNDERLINE

#define DOCG_DBL_BUF_FLAGS	(DOCF_OVERSTRIKE | DOCF_PLAIN_TEXT | DOCF_PLAIN_TEXT_TABS | DOCF_SIZE_MIN | DOCF_NO_CURSOR | \
							 DOCF_FORM | DOCF_DBL_DOLLARS | DOCF_DONT_SWAP_OUT | DOCF_DO_FULL_REFRESH | DOCF_BORDER_DOC | \
							 DOCF_HIDE_CURSOR | DOCF_DONT_HIGHLIGHT_CURSOR | DOCF_CARRIAGE_RETURN)

//CDocEntry.de_flags.  These first 16 are arg=
#define DOCEF_TAG 				1
#define DOCEF_LEN 				2
#define DOCEF_AUX_STR 			4
#define DOCEF_DEFINE			8
#define DOCEF_HTML_LINK 		0x10
#define DOCEF_LEFT_EXP			0x20
#define DOCEF_LEFT_MACRO		0x40
#define DOCEF_RIGHT_EXP 		0x80
#define DOCEF_RIGHT_MACRO 		0x100
#define DOCEF_HAS_BIN 			0x200
#define DOCEF_BIN_PTR_LINK		0x400
#define DOCEF_RAW_TYPE			0x800
#define DOCEF_SHIFTED_X 		0x1000
#define DOCEF_SHIFTED_Y 		0x2000
#define DOCEF_SCROLLING_X 		0x4000
#define DOCEF_USER_DATA 		0x8000

//CDocEntry.de_flags.  These are +/- flags
#define DOCEF_LEFT_CB 			0x10000
#define DOCEF_LEFT_IN_STR 		0x20000
#define DOCEF_RIGHT_CB			0x40000
#define DOCEF_RIGHT_IN_STR		0x80000
#define DOCEF_LEFT_X			0x100000
#define DOCEF_CENTER_X			0x200000
#define DOCEF_RIGHT_X 			0x400000
#define DOCEF_TOP_Y 			0x800000
#define DOCEF_CENTER_Y			0x1000000
#define DOCEF_BOTTOM_Y			0x2000000
//HL...UL
#define DOCEF_TAG_CB			0x100000000
#define DOCEF_PAGE_REL_Y		0x200000000
#define DOCEF_MARGIN_REL_X		0x400000000
#define DOCEF_WIN_REL 			0x800000000
#define DOCEF_LINK				0x1000000000
#define DOCEF_ESC 				0x2000000000 //Send <ESC> (Exit and Save)
#define DOCEF_QUIT				0x4000000000 //Send <SHIFT-ESC> (Abort)
#define DOCEF_FROM_START		0x8000000000
#define DOCEF_HAS_BORDER		0x10000000000
#define DOCEF_SOLID_BORDER		0x20000000000
#define DOCEF_BORDER_PLOT 		0x40000000000
#define DOCEF_CHECKED_COLLAPSED	0x80000000000 //Checked or Collapsed
#define DOCEF_CHECK_COLLAPSABLE	0x100000000000
#define DOCEF_REFRESH_DATA		0x200000000000
#define DOCEF_UPDATE_DATA 		0x400000000000
//$LK,"DOCEF_DEREF_DATA",A="MN:DOCEF_DEREF_DATA"$ is confusing. $LK,"DocForm",A="MN:DocForm"$() makes doc_e->data point to members
//of class. For ints, it derefs doc_e->data as a ptr.  For strings, it doesn't.
#define DOCEF_DEREF_DATA		0x800000000000
#define DOCEF_REMALLOC_DATA 	0x1000000000000
#define DOCEF_HAS_TERMINATOR	0x2000000000000
#define DOCEF_ZERO_BASED		0x4000000000000
#define DOCEF_HOLD				0x8000000000000
#define DOCEF_TREE				0x10000000000000
#define DOCEF_LIST				0x20000000000000
#define DOCEF_SKIP				0x40000000000000
#define DOCEF_POPUP 			0x80000000000000
#define DOCEF_SKIP_IN_FORM		0x100000000000000
#define DOCEF_FILTER_SKIP 		0x200000000000000
#define DOCEF_NO_CLICK_ON 		0x400000000000000
#define DOCEF_DONT_DRAW 		0x800000000000000 //only works on sprites
#define DOCEF_DEFAULT_LEN 		0x1000000000000000
#define DOCEF_DEFAULT_RAW_TYPE	0x2000000000000000

#define DOCEG_HAS_ALLOC		(DOCEF_TAG | DOCEF_AUX_STR | DOCEF_DEFINE | DOCEF_HTML_LINK | \
							 DOCEF_LEFT_MACRO | DOCEF_RIGHT_MACRO | DOCEF_BIN_PTR_LINK | DOCEF_REMALLOC_DATA)

#define DOCEG_HAS_ARG 		((DOCEG_HAS_ALLOC & ~DOCEF_REMALLOC_DATA) | \
							  DOCEF_LEN | DOCEF_LEFT_EXP | DOCEF_RIGHT_EXP | DOCEF_HAS_BIN | DOCEF_RAW_TYPE | \
							  DOCEF_SHIFTED_X | DOCEF_SHIFTED_Y | DOCEF_SCROLLING_X | DOCEF_USER_DATA)

#define DOCEG_DONT_EDIT		(DOCEF_DEFINE | DOCEF_HTML_LINK | DOCEF_AUX_STR | DOCEF_BIN_PTR_LINK | \
							 DOCEF_SCROLLING_X | DOCEF_TAG_CB)

//These are ident to Doc flags
#define DOCEF_HIGHLIGHT 		0x4000000
#define DOCEF_WORD_WRAP 		0x8000000
#define DOCEF_BLINK 			ATTRF_BLINK
#define DOCEF_INVERT			ATTRF_INVERT
#define DOCEF_SEL 				ATTRF_SEL
#define DOCEF_UNDERLINE 		ATTRF_UNDERLINE
#define DOCEf_HIGHLIGHT 		26
#define DOCEf_WORD_WRAP 		27
#define DOCEf_BLINK 			ATTRf_BLINK
#define DOCEf_INVERT			ATTRf_INVERT
#define DOCEf_SEL 				ATTRf_SEL
#define DOCEf_UNDERLINE 		ATTRf_UNDERLINE

//CDocEntry.de_flags.  These first 16 are arg=
#define DOCEf_TAG 				0
#define DOCEf_LEN 				1
#define DOCEf_AUX_STR 			2
#define DOCEf_DEFINE			3
#define DOCEf_HTML_LINK 		4
#define DOCEf_LEFT_EXP			5
#define DOCEf_LEFT_MACRO		6
#define DOCEf_RIGHT_EXP 		7
#define DOCEf_RIGHT_MACRO 		8
#define DOCEf_HAS_BIN 			9
#define DOCEf_BIN_PTR_LINK		10
#define DOCEf_RAW_TYPE			11
#define DOCEf_SHIFTED_X 		12
#define DOCEf_SHIFTED_Y 		13
#define DOCEf_SCROLLING_X 		14
#define DOCEf_USER_DATA 		15

//CDocEntry.de_flags.  These are +/- flags
#define DOCEf_LEFT_CB 			16
#define DOCEf_LEFT_IN_STR 		17
#define DOCEf_RIGHT_CB			18
#define DOCEf_RIGHT_IN_STR		19
#define DOCEf_LEFT_X			20
#define DOCEf_CENTER_X			21
#define DOCEf_RIGHT_X 			22
#define DOCEf_TOP_Y 			23
#define DOCEf_CENTER_Y			24
#define DOCEf_BOTTOM_Y			25
//HL...UL
#define DOCEf_TAG_CB			32
#define DOCEf_PAGE_REL_Y		33
#define DOCEf_MARGIN_REL_X		34
#define DOCEf_WIN_REL 			35
#define DOCEf_LINK				36
#define DOCEf_ESC 				37 //Send <ESC> (Exit and Save)
#define DOCEf_QUIT				38 //Send <SHIFT-ESC> (Abort)
#define DOCEf_FROM_START		39
#define DOCEf_HAS_BORDER		40
#define DOCEf_SOLID_BORDER		41
#define DOCEf_BORDER_PLOT 		42
#define DOCEf_CHECKED_COLLAPSED	43 //Checked or Collapsed
#define DOCEf_CHECK_COLLAPSABLE	44
#define DOCEf_REFRESH_DATA		45
#define DOCEf_UPDATE_DATA 		46
#define DOCEf_DEREF_DATA		47
#define DOCEf_REMALLOC_DATA 	48
#define DOCEf_HAS_TERMINATOR	49
#define DOCEf_ZERO_BASED		50
#define DOCEf_HOLD				51
#define DOCEf_TREE				52
#define DOCEf_LIST				53
#define DOCEf_SKIP				54
#define DOCEf_POPUP 			55
#define DOCEf_SKIP_IN_FORM		56
#define DOCEf_FILTER_SKIP 		57
#define DOCEf_NO_CLICK_ON 		58
#define DOCEf_DONT_DRAW 		59 //only works on sprites
#define DOCEf_DEFAULT_LEN 		60
#define DOCEf_DEFAULT_RAW_TYPE	61
#define DOCEf_FLAGS_NUM 		62

public class CDocBin
{
	CDocBin *next, *last;
	I32 	 tmp_use_count, renum_num;
	U8		*tag;
	U0		 start;
	U32 	 num, flags, size, use_count;
	U0		 end;
	U8		*data;
#assert !($$ & 7)
};

#define DOC_SCROLL_SPEED	6

#define DOCSS_NORMAL			0
#define DOCSS_SINGLE_QUOTE		1
#define DOCSS_DBL_QUOTE 		2
#define DOCSS_COMMENT 			3
#define DOCSS_CPP_Z_COMMENT 	4

#define DOC_ATTR_DEFAULT_TEXT		WHITE << 4 + BLACK
#define DOC_COLOR_ALT_TEXT			LTGRAY
#define DOC_COLOR_LINK				RED
#define DOC_COLOR_MACRO 			LTBLUE
#define DOC_COLOR_ANCHOR			DKGRAY
#define DOC_COLOR_TREE				PURPLE
#define DOC_COLOR_PROMPT			GREEN
#define DOC_COLOR_COMMENT 			GREEN
#define DOC_COLOR_BIN 				LTGREEN
#define DOC_COLOR_STR 				BROWN
#define DOC_COLOR_CHAR_CONST		BROWN
#define DOC_COLOR_EXPORT_SYS_SYM	LTPURPLE
#define DOC_COLOR_DEFINE_STR		CYAN
#define DOC_COLOR_GLOBAL_VAR		LTCYAN
#define DOC_COLOR_CLASS 			LTBLUE
#define DOC_COLOR_FUN 				PURPLE
#define DOC_COLOR_KEYWORD 			BLUE
#define DOC_COLOR_REG 				LTRED
#define DOC_COLOR_NUMBER			YELLOW

public class CDocSettings
{
	U32 	final_u32_attr;
	I16 	left_margin, right_margin, indent;
	U16 	page_len, header, footer;
	I8		shifted_x, shifted_y;
	U8		state, comment_depth, paren_depth, brace_depth, cur_text_attr, default_text_attr;
};

#define DOC_DEFAULT 						I32_MIN

public class CDocEntryBase
{
//This is a shortened structure for
	//cmds like the text cmd which
	//don't require the full CDocEntry structure.
	CDocEntryBase	*next, *last;
	U8				*tag;
	union
	{
		U8	type_u8; //this stores the code
		U32 type; //these store attr flags
	};
	I32				 page_line_num;
	I64				 de_flags;
	I32				 x, y;
	U32				 min_col, max_col;
	CDocSettings	 settings;
	I64				 user_data;
#assert !($$&7)
};

#define DOCE_LEN_DEFAULT				64

public class CDocEntry:CDocEntryBase
{
	union
	{
		I64   attr;
		I64   cursor_x_offset;
		I64 (*left_cb)(CDoc *doc, CDocEntry *doc_e);
		I64   left_exp;
	};
	U8		  *left_macro;

	union
	{
		I64   cursor_y_offset;
		I64 (*right_cb)(CDoc *doc, CDocEntry *doc_e);
		I64   right_exp;
	};
	U8		  *right_macro;

	U8		*(*tag_cb)(CDoc *doc, CDocEntry *doc_e, CTask *mem_task);
	U8		  *define_str,
			  *aux_str,
			  *bin_ptr_link,
			  *html_link,
			  *my_format_data;
	I64 	   hex_ed_width;
	I32 	   scroll_len,
			   len, //$LK,"DOCE_LEN_DEFAULT",A="MN:DOCE_LEN_DEFAULT"$
			   bin_num;
	U8		   raw_type, pad[3];
	CDocBin	  *bin_data;
	U8		  *data;
#assert !($$ & 7)
};

//$LK,"DocForm",A="MN:DocForm"$() $LK,"DocMenu",A="MN:DocMenu"$() $LK,"DocEd",A="MN:DocEd"$() $LK,"PopUpMenu",A="MN:PopUpMenu"$()
#define DOF_SIZE_MIN			0x01
#define DOF_INTERCEPT_TASK_END	0x02
#define DOF_DONT_HOME 			0x04
#define DOF_WIN_MAX 			0x08
#define DOF_DONT_TEXT_ATTR		0x10
#define DOF_DONT_WINMGR_SYNC	0x20
#define DOF_DONT_SHOW 			0x40
//Combines with  $LK,"Editor Flags",A="MN:EDF_BAIL"$

class CEdFindText
{
	U8		find_text[STR_LEN]		format "$$DA-P,A=\"Find        :%s\"$$\n",
			replace_text[STR_LEN]	format "$$DA-P,A=\"Replace     :%s\"$$\n";
	Bool	replace 				format "$$CB,\"Replace\"$$\n",
			scan_fwd				format "$$CB,\"Fwd\"$$\n",
			scan_sel_text 			format "$$CB,\"Selection\"$$\n",
			match_case				format "$$CB,\"Match Case\"$$\n",
			whole_labels			format "$$CB,\"Whole Labels\"$$\n",
			local_var 				format "$$CB,\"Rename Local Var\"$$\n",
			prompt, pad;
	I64 	filter_lines			format "$$DA,A=\"Filter Lines:%d\"$$\n";
};

class CEdFileName
{
	CDirContext	*dirc;
	U8			name[256] format "$$DA-P,LEN=255,A=\"FileName:%s\"$$";
};

//$LK,"Ed",A="MN:Ed"$()
#define EDF_BAIL		0x100
#define EDF_COLLAPSE	0x200
#define EDF_UNCOLLAPSE	0x400
#define EDF_WAS_WRITE 	0x800 //Was exit ESC or SHIFT_ESC?
//Combines with $LK,"Document Flags",A="MN:DOF_SIZE_MIN"$

#define EDf_BAIL		8
#define EDf_COLLAPSE	9
#define EDf_UNCOLLAPSE	10
#define EDf_WAS_WRITE 	11

// DOC header flags
#define DOCF_PLAIN_TEXT 			0x1
#define DOCF_PLAIN_TEXT_TABS		0x2 //has '\t', not DOCT_TAB
#define DOCF_AUTO_SAVE				0x4
#define DOCF_NO_CURSOR				0x8
#define DOCF_CARRIAGE_RETURN		0x10
#define DOCF_DBL_DOLLARS			0x20
#define DOCF_COLOR_NAMES			0x40
//Reserved x1
#define DOCF_BORDER_DOC 			0x100
#define DOCF_FORM 					0x200
#define DOCF_SIZE_MIN 				0x400
#define DOCF_HIDE_CURSOR			0x800  //use $LK,"DocCursor",A="MN:DocCursor"$
#define DOCF_DONT_HIGHLIGHT_CURSOR	0x1000 //use $LK,"DocHighlightCursor",A="MN:DocHighlightCursor"$
#define DOCF_NO_SCROLL_BARS 		0x2000 //use $LK,"DocScroll",A="MN:DocScroll"$
#define DOCF_ALLOW_UNDO 			0x4000
#define DOCF_DONT_SHOW				0x8000
#define DOCF_HAS_SONG 				0x10000
#define DOCF_MORE 					0x20000
#define DOCF_BWD_MOVEMENT 			0x40000
#define DOCF_NULL_GRAB_SCROLL 		0x80000
#define DOCF_DONT_SWAP_OUT			0x100000
#define DOCF_DO_FULL_REFRESH		0x200000
#define DOCF_BREAK_UNLOCKED 		0x400000
//Reserved x1
#define DOCF_HIGHLIGHT				DOCEF_HIGHLIGHT
#define DOCF_WORD_WRAP				DOCEF_WORD_WRAP
#define DOCF_BLINK					DOCEF_BLINK
#define DOCF_INVERT 				DOCEF_INVERT
#define DOCF_SEL					DOCEF_SEL
#define DOCF_UNDERLINE				DOCEF_UNDERLINE

#define DOCF_OVERSTRIKE 			0x100000000
#define DOCF_IN_DOLLAR				0x200000000
#define DOCF_SUPERSCRIPT_MODE 		0x400000000
#define DOCF_SUBSCRIPT_MODE 		0x800000000
#define DOCF_UNDO_DIRTY 			0x1000000000

#define DOCf_PLAIN_TEXT 			0
#define DOCf_PLAIN_TEXT_TABS		1 //has '\t', not DOCT_TAB
#define DOCf_AUTO_SAVE				2
#define DOCf_NO_CURSOR				3
#define DOCf_CARRIAGE_RETURN		4
#define DOCf_DBL_DOLLARS			5
#define DOCf_COLOR_NAMES			6
//Reserved x1
#define DOCf_BORDER_DOC 			8
#define DOCf_FORM 					9
#define DOCf_SIZE_MIN 				10
#define DOCf_HIDE_CURSOR			11	//use $LK,"DocCursor",A="MN:DocCursor"$
#define DOCf_DONT_HIGHLIGHT_CURSOR	12  //use $LK,"DocHighlightCursor",A="MN:DocHighlightCursor"$
#define DOCf_NO_SCROLL_BARS 		13	//use $LK,"DocScroll",A="MN:DocScroll"$
#define DOCf_ALLOW_UNDO 			14
#define DOCf_DONT_SHOW				15
#define DOCf_HAS_SONG 				16
#define DOCf_MORE 					17
#define DOCf_BWD_MOVEMENT 			18
#define DOCf_NULL_GRAB_SCROLL 		19
#define DOCf_DONT_SWAP_OUT			20
#define DOCf_DO_FULL_REFRESH		21
#define DOCf_BREAK_UNLOCKED 		22
//Reserved x1

#define DOCf_HIGHLIGHT				DOCEf_HIGHLIGHT
#define DOCf_WORD_WRAP				DOCEf_WORD_WRAP
#define DOCf_BLINK					DOCEf_BLINK
#define DOCf_INVERT 				DOCEf_INVERT
#define DOCf_SEL					DOCEf_SEL
#define DOCf_UNDERLINE				DOCEf_UNDERLINE

#define DOCf_OVERSTRIKE 			32
#define DOCf_IN_DOLLAR				33
#define DOCf_SUPERSCRIPT_MODE		34
#define DOCf_SUBSCRIPT_MODE 		35
#define DOCf_UNDO_DIRTY 			36

//locked flags
#define DOClf_LOCKED				0
class CDocUndo
{
	CDocUndo	*next, *last;
	I64			 size, doc_flags, time_stamp;
	U8			*body;
};

//See $LK,"DocMenu",A="MN:DocMenu"$()
#define DOCM_CANCEL 			(-1)

#define DOC_SIGNATURE_VAL 		'DocS'

#define RECALCt_NORMAL			0x00
#define RECALCt_FIND_CURSOR 	0x01
#define RECALCt_TO_SCREEN 		0x02
#define RECALCG_MASK			0xFF

#define RECALCF_HAS_CURSOR		0x100
#define RECALCF_ADD_CURSOR		0x200
#define RECALCF_TO_HTML 		0x400

public class CDoc //Linked Text File header
{//See $LK,"Doc",A="HI:Doc"$ for documentation.
	CDocEntryBase	 head;
	I64				 flags, locked_flags;
	CDocEntry		*cur_entry, *old_cur_entry;
	I32				 cur_col, old_cur_col, line_start_col, top_line_num, dollar_buf_size, dollar_buf_ptr;
	U8				*dollar_buf; //When entering $$ cmds, it buffers them until the end $$.

	CTask			*win_task, *mem_task, *owning_task;
	I32				 page_line_num, undo_count,
					 x, y, min_x, max_x, min_y, max_y;
	I64				 line, col, best_d,
					 old_win_top, old_win_bottom, old_win_left, old_win_right,
					 cmd_U8;
	U32				 doc_signature, cur_bin_num;
	I64 			 max_entries, updates_count;
	CEdFindText		*find_replace;

	CEdFileName		 filename;
	I64				 file_attr;
	I64			   (*left_click_link)(CDoc *doc, CDocEntry *doc_e);
	I64 		   (*right_click_link)(CDoc *doc, CDocEntry *doc_e);

	//See $LK,"::/Apps/Psalmody/JukeBox.ZC"$
	U8				*user_put_data; //Passed to user_put_key() and user_put_s()
	Bool		   (*user_put_key)(CDoc *doc, U8 *data, I64 ch, I64 sc);
	Bool		   (*user_put_s)(CDoc *doc, U8 *data, U8 *st);

	CDoc			*parent_doc; //(When browsing deeper, opening deeper docs.)
	U64				 desc; //8 characters. See $LK,"DocBorderListDraw",A="MN:DocBorderListDraw"$().

	CDocBin			 bin_head;
	CDocSettings	 settings_head;
	CDocUndo		 undo_head;

	I64				 user_data;
#assert !($$&7)
};

#help_index "Windows"
/*
Fs->win_inhibit mask

Some inhibit actions on the task itself.
Some inhibit actions if the focus task
tries to do something.
*/
#define WIF_SELF_FOCUS				0x0001 //If active this task cannot have focus
//MENU								0x0002
#define WIF_SELF_CTRLS				0x0004
#define WIF_SELF_MS_L 				0x0008
//MS_L_D							0x0010
#define WIF_SELF_MS_R 				0x0020
//MS_R_D							0x0040
#define WIF_SELF_MS_WHEEL 			0x0080 //Does nothing, yet
#define WIF_SELF_BORDER 			0x0100
#define WIF_SELF_GRAB_SCROLL		0x0200
#define WIF_SELF_DOC				0x0400
#define WIF_SELF_ODE				0x0800
#define WIF_SELF_KEY_DESC			0x1000
//FOCUS 							0x00010000
#define WIF_FOCUS_TASK_MENU 		0x00020000
#define WIF_FOCUS_TASK_CTRLS		0x00040000
#define WIF_FOCUS_TASK_MS_L 		0x00080000
#define WIF_FOCUS_TASK_MS_L_D		0x00100000
#define WIF_FOCUS_TASK_MS_R 		0x00200000
#define WIF_FOCUS_TASK_MS_R_D		0x00400000
#define WIF_FOCUS_TASK_MS_WHEEL		0x00800000 //Does nothing, yet
#define WIF_FOCUS_TASK_BORDER		0x01000000
#define WIF_FOCUS_TASK_GRAB_SCROLL	0x02000000

#define WIG_DBL_CLICK 				(WIF_FOCUS_TASK_MS_L_D | WIF_FOCUS_TASK_MS_R_D)
#define WIG_TASK_DEFAULT			(WIF_FOCUS_TASK_MENU | WIG_DBL_CLICK | 0xFFFF - WIF_SELF_DOC - WIF_SELF_ODE)
#define WIG_NO_FOCUS_TASK_DEFAULT 	(WIG_TASK_DEFAULT - WIF_SELF_BORDER - WIF_SELF_MS_L - WIF_SELF_MS_R - WIG_DBL_CLICK)
#define WIG_USER_TASK_DEFAULT		 WIF_SELF_KEY_DESC

#define WIf_SELF_FOCUS				0
#define WIf_SELF_CTRLS				2
#define WIf_SELF_MS_L 				3
#define WIf_SELF_MS_R 				5
#define WIf_SELF_MS_WHEEL 			7
#define WIf_SELF_BORDER 			8
#define WIf_SELF_GRAB_SCROLL		9
#define WIf_SELF_DOC				10
#define WIf_SELF_ODE				11
#define WIf_SELF_KEY_DESC 			12
#define WIf_FOCUS_TASK_MENU 		17
#define WIf_FOCUS_TASK_CTRLS		18
#define WIf_FOCUS_TASK_MS_L 		19
#define WIf_FOCUS_TASK_MS_L_D		20
#define WIf_FOCUS_TASK_MS_R 		21
#define WIf_FOCUS_TASK_MS_R_D		22
#define WIf_FOCUS_TASK_MS_WHEEL		23
#define WIf_FOCUS_TASK_BORDER		24
#define WIf_FOCUS_TASK_GRAB_SCROLL	25
#define WIf_FLAGS_NUM				26

class CWinMgrTimingGlobals
{
	I64 	last_total_jiffies,
			last_idle_pt_hits[MP_PROCESSORS_NUM],
			last_swap_counter[MP_PROCESSORS_NUM];
	F64 	last_calc_idle_time, calc_idle_delta_time;
	I64 	calc_idle_count;
};

#define WINMGR_FPS		(60000.0 / 1001)
#define WINMGR_PERIOD 	(1001 / 60000.0)

public class CWinMgrGlobals
{
	I64						 updates;
	F64						 ode_time,
							 last_ode_time,
							 fps,	//You can read but not write this. You have no control.
							 ideal_refresh_tS,
							 last_refresh_tS;
	CWinMgrTimingGlobals	*t;
	Bool					 show_menu, grab_scroll, grab_scroll_closed;
};

#help_index "AutoComplete"
#define ACf_INIT_IN_PROGRESS		0
#define ACf_LAST_WAS_KEYMAP 		1

#define AC_FILLINS_NUM				12
public class CAutoCompleteGlobals
{
	I64			 col, row, old_col, old_row, num_words;
	CHashTable	*hash_table;
	U8			*cur_word;
	I64 		 flags;
	CTask		*task;
	I64 		 partial_len, num_fillins,
				 fillin_hits   [AC_FILLINS_NUM + 1];
	CHashAC		*fillin_matches[AC_FILLINS_NUM + 1];
};

#help_index "AutoComplete/Dictionary"
#define ACD_WORD_FILENAME 	"/System/AutoComplete/ACWords.DATA"
#define ACD_DEF_FILENAME	"/System/AutoComplete/ACDefs.DATA"

#define ACD_H1					0
#define ACD_H1_END				1
#define ACD_DEF 				2
#define ACD_DEF_END 			3
#define ACD_PRONUNCIATION 		4
#define ACD_PRONUNCIATION_END 	5
#define ACD_POS 				6
#define ACD_POS_END 			7
#define ACD_EXTRA 				8
#define ACD_EXTRA_END 			9
#define ACD_BLK_SIZE			0x4000

#define ACD_END_CHAR			0x00
#define ACD_WORD_CHAR 			0x01
#define ACD_DEF_CHAR			0x02
#define ACD_PRONUNCIATION_CHAR	0x03
#define ACD_POS_CHAR			0x04
#define ACD_EXTRA_CHAR			0x05

#define ACD_FILLINS_NUM		10
public class CAutoCompleteDictGlobals
{
	U8		*word_list;
	I64 	word_list_size, num_words, num_fillins;
	U8		*fillins[ACD_FILLINS_NUM];
	Bool	has_words, has_defs;
};

#help_index "Compiler/Directive"
//Compiler $LK,"Option",A="MN:Option"$()s
//You might need to do #exe {Option();}
//Note: The #exe statement is lexed-ahead,
//so it takes effect earlier than you might expect.
#define OPTf_ECHO 					0
#define OPTf_TRACE					1
#define OPTf_WARN_UNUSED_VAR		2	//Applied to functions, not statements
#define OPTf_WARN_PAREN 			3	//Warn unnecessary parens
#define OPTf_WARN_DUP_TYPES 		4	//Warn duplicate local variable type statements
#define OPTf_WARN_HEADER_MISMATCH	5
#define OPTf_EXTERNS_TO_IMPORTS 	6
#define OPTf_KEEP_PRIVATE 			7
#define OPTf_NO_REG_VAR 			8	//Applied to functions, not statements
#define OPTf_GLOBALS_ON_DATA_HEAP 	9
//Disable 10-byte float consts for π,log2_10,log10_2,loge_2
#define OPTf_NO_BUILTIN_CONST 		10	//Applied to functions, not statements
#define OPTf_USE_IMM64				11	//Not completely implemented
#define OPTf_DECIMAL_ONLY			12	//Only allow decimal numbers (no 0x or 0b prefixed numbers)
#define OPTf_NO_FLOATS				13	//No floating point numbers allowed

#define OPTF_ECHO 					(1 << OPTf_ECHO)

#help_index "Compiler/Intermediate Code"
//See $LK,"ST_RAW_TYPES",A="MN:ST_RAW_TYPES"$
#define RT_I0 			2
#define RT_U0 			3
#define RT_I8 			4
#define RT_U8 			5
#define RT_I16			6
#define RT_U16			7
#define RT_I32			8
#define RT_U32			9
#define RT_I64			10
#define RT_PTR			10 //Signed to allow negative error codes. $LK,"DOCM_CANCEL",A="MN:DOCM_CANCEL"$
#define RT_U64			11
#define RT_F32			12 //Not implemented
#define RT_UF32 		13 //Not implemented, Fictitious
#define RT_F64			14
#define RT_UF64 		15 //Fictitious
#define RT_RTS_NUM		16
#define RTF_UNSIGNED	1
#define RTG_MASK		0xFF

#define MDf_STACK 		8
#define MDf_IMM 		9
#define MDf_REG 		10
#define MDf_DISP		11
#define MDf_SIB 		12
#define MDf_RIP_DISP32	13

#define MDF_NULL				0x0000
#define MDF_STACK 				0x0100
#define MDF_IMM 				0x0200
#define MDF_REG 				0x0400
#define MDF_DISP				0x0800
#define MDF_SIB 				0x1000
#define MDF_RIP_DISP32			0x2000
#define MDG_MASK				0xFF00
#define MDG_REG_DISP_SIB		(MDF_REG  | MDF_DISP | MDF_SIB)
#define MDG_DISP_SIB_RIP		(MDF_DISP | MDF_SIB  | MDF_RIP_DISP32)
#define MDG_REG_DISP_SIB_RIP	(MDF_REG  | MDG_DISP_SIB_RIP)

#define ICF_RES_TO_F64			0x000000001
#define ICF_RES_TO_INT			0x000000002
#define ICF_ARG1_TO_F64 		0x000000004
#define ICF_ARG1_TO_INT 		0x000000008
#define ICF_ARG2_TO_F64 		0x000000010
#define ICF_ARG2_TO_INT 		0x000000020
#define ICF_USE_F64 			0x000000040
#define ICF_USE_UNSIGNED		0x000000080
#define ICF_USE_INT 			0x000000100 //highest priority
#define ICF_RES_NOT_USED		0x000000200
#define ICF_CODE_FINAL			0x000000400
#define ICF_BY_VAL				0x000000800 //By value, not ref.
#define ICF_SHORT_JMP 			0x000001000
#define ICF_PUSH_RES			0x000002000
#define ICF_PASS_TRACE			0x000004000
#define ICF_RES_WAS_STACK 		0x000008000
#define ICF_ARG1_WAS_STACK		0x000010000
#define ICF_ARG2_WAS_STACK		0x000020000
#define ICF_PUSH_CMP			0x000040000 //for 50<i<j<=100 exps
#define ICF_POP_CMP 			0x000080000 //for 50<i<j<=100 exps
#define ICF_SWAP				0x000100000
#define ICf_DONT_PUSH_FLOAT0	21 // 3bits
#define ICf_DONT_POP_FLOAT0 	24 // 3bits
#define ICF_ALT_TEMPLATE		0x008000000
#define ICF_LOCK				0x010000000
#define ICf_LOCK				28
#define ICF_NO_RIP				0x020000000
#define ICF_DEL_PREV_INS		0x040000000
#define ICF_PREV_DELETED		0x080000000
#define ICF_DONT_RESTORE		0x100000000
#define ICG_NO_CONVERT_MASK 	0x1FFFFFF00

#define IC_BODY_SIZE	0x83

#define ECF_HAS_PUSH_CMP	0x01 //for 50<i<j<=100 exps

U16 class CICType
{
	U8		raw_type, mode;
};

class CICArg
{
	CICType type;
	U16 	reg; //low is reg, high is index_reg+scale<<6
	I64 	disp;
};

class CICTreeLinks
{
	CHashClass			*arg1_class, *arg2_class;
	CIntermediateCode	*arg1_tree, *arg2_tree;
	CHashClass			*class2;
};

class CIntermediateCodeBase
{
	CIntermediateCode	*next, *last;
	U16 				 ic_code,
						 ic_precedence;
	I16 				 ic_count,
						 ic_last_start;
};

class CIntermediateCode:CIntermediateCodeBase
{
	I64			 ic_flags,
				 ic_data,
				 ic_line;
	CHashClass	*ic_class, *ic_class2;
	CICArg		 arg1, arg2, res;
	U8			 arg1_type_pointed_to; //Used for $LK,"IST_ASSIGN",A="MN:IST_ASSIGN"$ and $LK,"IST_DEREF",A="MN:IST_DEREF"$ $LK,"ic_codes",A="MN:intermediate_code_table"$.
	union
	{
		U8 ic_body[IC_BODY_SIZE];
		//Tree Links are created in OptPass012.  An ADD opcode, for example,
		//points back to its two earlier arg CIntermediateCode's.

		//Tree links get destroyed during Pass789A when they get overwrites
		//by machine code.	(Saves room to union the output machine code buffer
		//with these links, since they are not needed after pass4.

		//Tree links are used during passes 012 and 3 for determining types.
		CICTreeLinks t;
	};
#assert !($$ & 7)
};

class CParseStack
{
	I64	ptr,
		stack[255],
		ptr2,
		stack2[255];
};

#define CMT_LABEL 			0
#define CMT_ASM_LABEL 		1
#define CMT_GOTO_LABEL		2
#define CMT_STR_CONST 		3
#define CMT_JMP_TABLE 		4
#define CMT_FLOAT_CONSTS	5
#define CMT_ARRAY_DIM 		6
#define CMT_HASH_ENTRY		7

#define CMF_POP_CMP 		0x01
#define CMF_DEFINED 		0x02
#define CMF_I8_JMP_TABLE	0x04
#define CMF_U8_JMP_TABLE	0x08
#define CMF_I16_JMP_TABLE	0x10
#define CMF_U16_JMP_TABLE	0x20

#define CM_CONSTS_NUM		16

class CCodeMisc
{
	CCodeMisc	*next, *last, *forward, *default, *begin;
	U8			*str;
	U32 		 type, flags;
	I64 		 use_count;
	U8			*addr;
	union
	{
		I64 st_len; 	//STR_CONST
		I64 num_consts; //FLOAT_CONSTS
		I64 range;
		I64 rip;		//ASM_LABEL
	}
	union
	{
		CCodeMisc	**jmp_table;
		F64			 *float_consts;
		CArrayDim	 *dim;
		CHash		 *h;
	};
};

#help_index "Compiler/Assembler"
#define IEF_OP_SIZE16 			0x001
#define IEF_OP_SIZE32 			0x002
#define IEF_PLUS_OPCODE 		0x004
#define IEF_DONT_SWITCH_MODES 	0x008
#define IEF_DEFAULT 			0x010
#define IEF_NOT_IN_64_BIT 		0x020
#define IEF_48_REX				0x040
#define IEF_REX_ONLY_R8_R15 	0x080
#define IEF_REX_XOR_LIKE		0x100
#define IEF_STI_LIKE			0x200
#define IEF_ENDING_ZERO 		0x400

//Slash value
#define SV_R_REG		8
#define SV_I_REG		9
#define SV_STI_LIKE 	10 //$LK,"uasm_slash_val",A="FF:::/Compiler/AsmInit.ZC,uasm_slash_val"$ only.
#define SV_NONE 		11
class CInst
{
	U8	ins_entry_num, //This entry num in opcode hash entry
		opcode_count,
		opcode[8];
	U16	flags;
	U8	slash_val, uasm_slash_val, opcode_modifier,
		arg1, arg2, arg3,
		size1, size2, size3, //Size in bits
		pad;
};

//x86 opcodes
#define OC_OP_SIZE_PREFIX 		0x66
#define OC_ADDR_SIZE_PREFIX 	0x67
#define OC_LOCK_PREFIX			0xF0
#define OC_NOP					0x90
#define OC_BPT					0xCC
#define OC_CALL 				0xE8
#define OC_JMP_REL8 			0xEB
#define OC_NOP2 				(OC_NOP << 8 + OC_OP_SIZE_PREFIX)

#define PUSH_C_REGS		PUSH RAX PUSH RCX PUSH RDX PUSH RBX PUSH R8 PUSH R9
#define POP_C_REGS		POP R9 POP R8 POP RBX POP RDX POP RCX POP RAX

#define PUSH_REGS	PUSH RAX PUSH RCX PUSH RDX PUSH RBX PUSH RBP PUSH RSI \
					PUSH RDI PUSH R8 PUSH R9 PUSH R10 PUSH R11 PUSH R12 PUSH R13 PUSH R14 PUSH R15
#define POP_REGS	POP R15 POP R14 POP R13 POP R12 POP R11 POP R10 POP R9 \
					POP R8 POP RDI POP RSI POP RBP POP RBX POP RDX POP RCX POP RAX

#define REG_RAX 		0
#define REG_RCX 		1
#define REG_RDX 		2
#define REG_RBX 		3
#define REG_RSP 		4
#define REG_RBP 		5
#define REG_RSI 		6
#define REG_RDI 		7
#define REG_R8			8
#define REG_REGS_NUM	16

#define REG_RIP 		16			//Used by compiler, not really it's num
//Be careful: RBPu8, RSPu8, RSIu8, RDIu8 are 20-24
#define REG_NONE		32			//noreg flag sets it to this
#define REG_ALLOC 		33			//reg flag sets it to this
#define REG_UNDEF 		I8_MIN

#define REGG_CLOBBERED			0x013F //RAX,RCX,RDX,RBX,R8
#define REGG_SAVED				0x0030 //RBP,RSP
#define REGG_STACK_TMP			0x0200 //R9
#define REGG_LOCAL_VARS 		0xCCC0 //RSI,RDI,R10,R11,R14,R15
#define REGG_LOCAL_NON_PTR_VARS	0x3000 //R12,R13

#define AOT_BIN_BLK_BITS	16
#define AOT_BIN_BLK_SIZE	(1 << AOT_BIN_BLK_BITS)

class CAOTBinBlk
{
	CAOTBinBlk	*next;
	U8			 body[AOT_BIN_BLK_SIZE];
};

I64 class CAbsCountsI64
{
	U16 abs_address,	//Only odd/even matters. Count of absolute address in an expression.
		c_address;	//Only odd/even matters. Count of C address in an expression.
	U32 externs;	//Only nonzero matters. Some regions have externs banned.
};

class CAsmUndefHash
{//Only place created is $LK,"Exp Parser",A="FF:::/Compiler/ParseExp.ZC,sizeof(CAsmUndefHash)"$ when an undef is found in an ASM expression.
	CAsmUndefHash	*next;
	CHashExport 	*hash;
};

class CAsmNum
{
	I64				 i;
	U8				*machine_code;
	CAsmUndefHash	*local_asm_undef_hash, *global_asm_undef_hash;
	CAbsCountsI64	 abs_counts;
};

class CAsmNum2
{
	CAsmNum num;
	I64 	U8_count, rel;
	Bool	imm_flag;
};

class CAsmIns
{
	CInst		*tmpins;
	CAsmNum2	 imm, disp;
	I64			 U8_count, last_opcode_U8,
				 REX, ModrM, SIB;
	Bool		 has_REX, has_ModrM, has_SIB,
				 has_addr_prefix,
				 has_operand_prefix,
				 is_default, pad[2];
};

class CAsmArg
{
	CAsmNum num;
	I64 	seg, size, //Size in bytes
			reg1, reg2,
			reg1_type, reg2_type,
			scale;
	Bool	indirect, imm_or_off_present, just_seg, pad[5];
};

class CAsmUnresolvedRef
{
	CAsmUnresolvedRef	*next;
	I64					 type, line_num;
	U8					*machine_code;
	I64					 rip, rel_rip;
	CAOT				*aot;
	U8					*str; 	//Only for import globals
	CAsmUndefHash		*asm_undef_hash;
	Bool				 U8_avail,
						 imm_flag;//Only for import globals
};

//Opcode Modifier
#define OM_NO 0
#define OM_CB 1
#define OM_CW 2
#define OM_CD 3
#define OM_CP 4
#define OM_IB 5
#define OM_IW 6
#define OM_ID 7

#define ARGT_NONE		0
#define ARGT_REL8		1
#define ARGT_REL16		2
#define ARGT_REL32		3

#define ARGT_IMM8 		4
#define ARGT_IMM16		5
#define ARGT_IMM32		6
#define ARGT_IMM64		7

#define ARGT_UIMM8		8
#define ARGT_UIMM16 	9
#define ARGT_UIMM32 	10
#define ARGT_UIMM64 	11

#define ARGT_R8 		12
#define ARGT_R16		13
#define ARGT_R32		14
#define ARGT_R64		15

#define ARGT_RM8		16
#define ARGT_RM16 		17
#define ARGT_RM32 		18
#define ARGT_RM64 		19

#define ARGT_M8 		20
#define ARGT_M16		21
#define ARGT_M32		22
#define ARGT_M64		23

#define ARGT_M1632		24 // Not implemented
#define ARGT_M16N32 	25 // Not implemented
#define ARGT_M16N16 	26 // Not implemented
#define ARGT_M32N32 	27 // Not implemented

#define ARGT_MOFFS8 	28
#define ARGT_MOFFS16	29
#define ARGT_MOFFS32	30
#define ARGT_MOFFS64	31

#define ARGT_AL 		32
#define ARGT_AX 		33
#define ARGT_EAX		34
#define ARGT_RAX		35

#define ARGT_CL 		36
#define ARGT_DX 		37
#define ARGT_SREG 		39

#define ARGT_SS 		40
#define ARGT_DS 		41
#define ARGT_ES 		42
#define ARGT_FS 		43

#define ARGT_GS 		44
#define ARGT_CS 		45
#define ARGT_ST0		46
#define ARGT_STI		47

#define ARGT_MM 		48 // Not implemented
#define ARGT_MM32 		49 // Not implemented
#define ARGT_MM64 		50 // Not implemented
#define ARGT_XMM		51

#define ARGT_XMM32		52
#define ARGT_XMM64		53
#define ARGT_XMM128 	54
#define ARGT_XMM0 		55

#help_index "Compiler/Internal;Hash/System"
#define OCF_ALIAS 			1
public class CHashOpcode:CHash
{
	U16 	inst_entry_count,
			oc_flags, pad[2];
	CInst	ins[1];
};

#help_index "Compiler/Intermediate Code"
#define IEF_GOTO_LABEL	1
class CAOTImportExport
{
	CAOTImportExport	*next, *last;
	I64					 rip, flags;
	CAOT				*aot;
	U8					*str,
						*src_link,
						 type, pad[7];
};

#define AAT_ADD_U8		0
#define AAT_SUB_U8		1
#define AAT_ADD_U16 	2
#define AAT_SUB_U16 	3
#define AAT_ADD_U32 	4
#define AAT_SUB_U32 	5
#define AAT_ADD_U64 	6
#define AAT_SUB_U64 	7
class CAOTAbsAddr
{
	CAOTAbsAddr	*next;
	I64			 rip;
	U8			 type, pad[7];
};

class CAOTHeapGlobalRef
{
	CAOTHeapGlobalRef	*next;
	I64					 rip;
};

class CAOTHeapGlobal
{
	CAOTHeapGlobal		*next;
	U8					*str;
	I64					 size;
	CAOTHeapGlobalRef	*references;
};

class CAOT
{
	CAOT				*next, *last;
	U8					*buf;
	I64					 rip, rip2,
						 aot_U8s,
						 max_align_bits, org;
	CAOT				*parent_aot;
	CAOTImportExport	*next_ie, *last_ie;
	CAOTAbsAddr			*abss;
	CAOTHeapGlobal		*heap_globals;
};

class CStreamBlk
{
	CStreamBlk	*next, *last;
	U8			*body;
};

class CCodeCtrl
{
	CCodeCtrl				*coc_next;
	CCodeMisc				*coc_next_misc, *coc_last_misc;
	CIntermediateCodeBase	 coc_head;
};

#help_index "Compiler/Lex"
#define __DATE__	 #exe{StreamPrint("\"%D\"", Now);}
#define __TIME__	 #exe{StreamPrint("\"%T\"", Now);}
#define __LINE__	 #exe{StreamPrint("%d", Fs->last_cc->lex_include_stack->line_num);}
#define __CMD_LINE__ #exe{StreamPrint("%d", Fs->last_cc->flags & CCF_CMD_LINE && Fs->last_cc->lex_include_stack->depth < 1);}
#define __FILE__	 #exe{StreamPrint("\"%s\"", Fs->last_cc->lex_include_stack->full_name);}
#define __DIR__ 	 #exe{StreamDir;}

#define LFSF_DOC		1
#define LFSF_DEFINE 	2
class CLexFile
{
	CLexFile	*next;
	U8			*buf,
				*buf_ptr;
	I64			 line_num, flags;
	U8			*full_name,
				*line_start;
	CDoc		*doc;
	CDocEntry	*cur_entry;
	I32			 depth;
	U8			 last_U16, pad[3];
};

class CAOTCtrl
{
	I64					 rip; //Instruction pointer
	CAsmArg				 arg1, arg2, arg3;
	CAOTBinBlk			*bin;
	I64					 num_bin_U8s,
						 max_align_bits, org;
	CAsmUnresolvedRef	*local_unresolved, *global_unresolved;
	CAOTAbsAddr			*abss;
	CAOTHeapGlobal		*heap_globals;
	I64					 list_col, list_last_rip;
	U8					*last_label, *list_last_line;
	CLexFile			*list_last_lfn;
	I64					 seg_size;
	Bool				 list;
};

//Tokens
#define TK_EOF			0
#define TK_SUPERSCRIPT	0x001
#define TK_SUBSCRIPT	0x002
#define TK_NORMALSCRIPT 0x003
#define TK_IDENT		0x100
#define TK_STR			0x101
#define TK_I64			0x102
#define TK_CHAR_CONST 	0x103
#define TK_F64			0x104
#define TK_PLUS_PLUS	0x105
#define TK_MINUS_MINUS	0x106
#define TK_DEREFERENCE	0x107
#define TK_DBL_COLON	0x108
#define TK_SHL			0x109
#define TK_SHR			0x10A
#define TK_EQU_EQU		0x10B
#define TK_NOT_EQU		0x10C
#define TK_LESS_EQU 	0x10D
#define TK_GREATER_EQU	0x10E
#define TK_AND_AND		0x10F
#define TK_OR_OR		0x110
#define TK_XOR_XOR		0x111
#define TK_SHL_EQU		0x112
#define TK_SHR_EQU		0x113
#define TK_MUL_EQU		0x114
#define TK_DIV_EQU		0x115
#define TK_AND_EQU		0x116
#define TK_OR_EQU 		0x117
#define TK_XOR_EQU		0x118
#define TK_ADD_EQU		0x119
#define TK_SUB_EQU		0x11A
#define TK_IF 			0x11B
#define TK_IFDEF		0x11C
#define TK_IFNDEF 		0x11D
#define TK_IFAOT		0x11E
#define TK_IFJIT		0x11F
#define TK_ENDIF		0x120
#define TK_ELSE 		0x121
#define TK_MOD_EQU		0x122
#define TK_DOT_DOT		0x123
#define TK_ELLIPSIS 	0x124
#define TK_INS_BIN		0x125
#define TK_INS_BIN_SIZE	0x126
#define TK_TKS_NUM		0x127

class CLexHashTableContext
{
	CLexHashTableContext	*next;
	I64						 old_flags, hash_mask;
	CHashFun				*local_var_list,
							*fun;
	CHashTable				*hash_table_list,
							*define_hash_table,
							*local_hash_table,
							*global_hash_table;
};

//CompCtrl flags
#define CCF_CMD_LINE			0x001
#define CCF_PROMPT				0x002
#define CCf_PROMPT				1
#define CCF_QUESTION_HELP 		0x004
#define CCF_DONT_FREE_BUF 		0x008
#define CCF_NO_DEFINES			0x010
#define CCF_IN_IF 				0x020
#define CCF_JUST_LOAD 			0x040
#define CCF_KEEP_NEW_LINES		0x080
#define CCF_KEEP_DOT			0x100
#define CCF_KEEP_SIGN_NUM 		0x200
#define CCF_KEEP_AT_SIGN		0x400
#define CCF_NO_CHAR_CONST 		0x800
#define CCf_PASS_TRACE_PRESENT	12
#define CCF_NOT_CONST 			0x0000020000
#define CCF_NO_REG_OPT			0x0000040000
#define CCF_IN_QUOTES 			0x0000080000
#define CCF_EXE_BLK 			0x0000100000
#define CCF_HAS_MISC_DATA 		0x0000200000
#define CCF_HAS_RETURN			0x0000400000
#define CCF_ASM_EXPRESSIONS 	0x0000800000
#define CCF_UNRESOLVED			0x0001000000
#define CCF_LOCAL 				0x0002000000
#define CCF_FUN_EXP 			0x0004000000
#define CCf_FUN_EXP 			26
#define CCF_POSTINC 			0x0008000000
#define CCF_POSTDEC 			0x0010000000
#define CCF_PREINC				0x0020000000
#define CCF_PREDEC				0x0040000000
#define CCF_ARRAY 				0x0080000000
#define CCF_RAX 				0x0100000000
#define CCF_USE_LAST_U16		0x0200000000
#define CCf_USE_LAST_U16		33
#define CCF_LAST_WAS_DOT		0x0400000000
#define CCF_AOT_COMPILE 		0x0800000000
#define CCf_AOT_COMPILE 		35
#define CCF_NO_ABSS 			0x1000000000
#define CCF_PAREN 				0x2000000000
#define CCf_PAREN 				37
#define CCF_CLASS_DOL_OFFSET	0x4000000000
#define CCF_DONT_MAKE_RES 		0x8000000000

public class CCompCtrl
{
	CCompCtrl				*next, *last;
	I64						 token, flags,
							 cur_i64;
	F64						 cur_f64;
	U8						*cur_str;
	I64						 cur_str_len,
							 class_dol_offset;
	U8						*dollar_buf;
	I64						 dollar_count;
	U8						*cur_help_idx;
	I64						 last_U16,
							 min_line, max_line, last_line_num,
							 lock_count;
	U32						*char_bmp_alpha_numeric;
	CLexHashTableContext	 htc;
	CHashGeneric			*hash_entry;
	CAbsCountsI64			 abs_counts;
	CAsmUndefHash			*asm_undef_hash;
	CMemberList				*local_var_entry;
	CCodeMisc				*lb_leave;
	U8						*cur_buf_ptr;
	CLexFile				*lex_include_stack,
							*lex_parse_stack,
							*fun_lex_file;
	CStreamBlk				*next_stream_blk, *last_stream_blk;
	CAOT					*aot;

	I64						 pass, opts, pass_trace, saved_pass_trace, error_count, warning_count;

	//For intermediate codes with multiple float ops (int<->float conversions)
	I64						 cur_ic_float_op_num, last_ic_float_op_num;
	CIntermediateCode		*last_float_op_ic;
	Bool					 last_dont_pushable, last_dont_popable, last_float_op_pos, dont_push_float, pad[4];

	CCodeCtrl				 coc;
	CParseStack				*ps;
	CAOTCtrl				*aotc;
	I64						 aot_depth, prompt_line;
#assert !($$ & 7)
};

#help_index "Compiler"
public class CCompGlobals
{
	CHashTable			*asm_hash;
	CHashClass			*internal_types[RT_RTS_NUM];
	CIntermediateCode	 ic_nop;
	U32					*dual_U16_tokens1, *dual_U16_tokens2, *dual_U16_tokens3,
						*binary_ops;
	I64					 num_reg_vars, num_non_ptr_vars,
						 stack_tmps_mask, reg_vars_mask, non_ptr_vars_mask;
	U8					*to_reg_vars_map, *non_ptr_vars_map;
	I64					 size_arg_mask[17],
						 compiled_lines;
};

#help_index "Debugging/Unassemble"
class CUAsmGlobals
{
	CInst **table_16_32,
		  **table_64;
	I64 	table_16_32_entries,
			table_64_entries,
			ins64_arg_mask,
			signed_arg_mask,
			mem_arg_mask;
};

#help_index "Devices/SMBIOS"
//SMBIOS parsing based on SMBIOS specification 3.3.0 (document "DSP0134")
#define SMBIOSt_BIOS				0
#define SMBIOSt_SYSTEM				1
#define SMBIOSt_BASEBOARD			2
#define SMBIOSt_ENCLOSURE			3
#define SMBIOSt_PROCESSOR			4
#define SMBIOSt_CACHE				7
#define SMBIOSt_CONNECTOR			8
#define SMBIOSt_SLOT				9
#define SMBIOSt_OEM_STRINGS			11
#define SMBIOSt_SYS_CONFIG_OPTIONS	12
#define SMBIOSt_PHYMEM				16
#define SMBIOSt_MEM_DEVICE			17
#define SMBIOSt_MAPPED_ADDR			19
#define SMBIOSt_BATTERY				22
#define SMBIOSt_BOOT_INFO			32
#define SMBIOSt_ALL					0xFF //Non-existent placeholder type

class CSMBIOSHeader
{//Section 6.1.2 line 885
	U8	type,	//SMBIOSt_*
		length;
	U16	handle;	//identifier for this structure.
};
class CSMBIOSEntryPoint
{//Section 5.2.1 line 812
	U8	anchor_str[4], // '_SM_'
		checksum,
		length,
		major_version,
		minor_version;
	U16	max_structure_size;
	U8	entry_point_revision,
		formatted_area[5],
		anchor_str2[5], // '_DMI_'
		checksum2;
	U16	table_length;
	U32	table_address;
	U16	structure_count;
	U8	bcd_revision;
};

class CSMBIOSBIOSInfo
{//Section 7.1 line 922
	CSMBIOSHeader header;
	U8	vendor,
		version;
	U16	start_address_segment;
	U8	release_date,
		rom_size;
	U64	flags;
	U8	extended_flags[2];
	U8	major_release,
		minor_release,
		embedded_controller_firmware_major_release,
		embedded_controller_firmware_minor_release;
	U16	extended_rom_size;
};

class CSMBIOSSystemInfo
{//Section 7.2 line 936
	CSMBIOSHeader header;
	U8	manufacturer,
		product_name,
		version,
		serial_number,
		uuid[16],
		wakeup_type,
		sku_number,
		family;
};

class CSMBIOSBaseboardInfo
{//Section 7.3 line 968
	CSMBIOSHeader header;
	U8	manufacturer,
		product,
		version,
		serial_number,
		asset_tag,
		feature_flags,
		chassis_location;
	U16	chassis_handle;
	U8	board_type,
		contained_object_handles_num;
	U16	contained_object_handles[1]; //Variable length, member above gives length
};

class CSMBIOSEnclosureInfo
{//Section 7.4 line 984
	CSMBIOSHeader header;
	U8	manufacturer,
		type,
		version,
		serial_number,
		asset_tag,
		bootup_state,
		power_supply_state,
		thermal_state,
		security_status;
	U32	oem_defined;
	U8	height,
		power_cord_count,
		contained_element_count,
		contained_element_record_length,
		contained_elements[1]; //array length == count * record_length;
};

class CSMBIOSEnclosureContainedElement
{//Section 7.4.4 line 999
	U8	contained_element_type,
		contained_element_minimum,
		contained_element_maximum;
};

class CSMBIOSProcessorInfo
{//Section 7.5 line 1010
	CSMBIOSHeader header;
	U8	name,
		type,
		family,
		manufacturer;
	U64	id;
	U8	version,
		voltage;
	U16	external_clock,
		max_speed,
		current_speed;
	U8	status,
		upgrade;
	U16	l1_cache_handle,
		l2_cache_handle,
		l3_cache_handle;
	U8	serial_number,
		asset_tag,
		part_number,
		core_count,
		cores_enabled,
		thread_count;
	U16	characteristics;
};

class CSMBIOSCacheInfo
{//Section 7.8 line 1168
	CSMBIOSHeader header;
	U8	name;
	U16	config,
		max_size,
		installed_size,
		supported_sram_type,
		installed_sram_type;
	U8	cache_speed,
		error_correction_type,
		cache_type,
		associativity;
};

class CSMBIOSConnectorInfo
{//Section 7.9 line 1198
	CSMBIOSHeader header;
	U8	internal_name,
		internal_type,
		external_name,
		external_type,
		port_type;
};

class CSMBIOSSlotInfo
{//Section 7.10 line 1226
	CSMBIOSHeader header;
	U8	name,
		type,
		data_bus_width,
		current_usage,
		length;
	U16	id;
	U8	flags1,
		flags2;
	U16	segment_group_number;
	U8	bus_number,
		device_function_number;
};

class CSMBIOSMemArrayInfo
{//Section 7.17 line 1519
	CSMBIOSHeader header;
	U8	location,
		use,
		memory_error_correction;
	U32	max_capacity;
	U16	memory_error_info_handle,
		mem_device_count;
	U64	extended_max_capacity;
};

class CSMBIOSMemDeviceInfo
{//Section 7.18 line 1538
	CSMBIOSHeader header;
	U16	memory_array_handle,
		memory_error_info_handle,
		total_width,
		data_width,
		size;
	U8	form_factor,
		device_set,
		device_locator,
		bank_locator,
		type;
	U16	type_detail,
		speed;
	U8	manufacturer,
		serial_number,
		asset_tag,
		part_number,
		attributes;
	U32	extended_size;
	U16	configured_speed,
		min_voltage,
		max_voltage,
		configured_voltage;
};

class CSMBIOSBatteryInfo
{//Section 7.23 line 1723
	CSMBIOSHeader header;
	U8	location,
		manufacturer,
		manufacture_date,
		serial_number,
		name,
		chemistry,
		capacity,
		voltage,
		sbds_version_number,
		max_battery_data_error,
		sbds_serial_number,
		sbds_manufacture_date,
		sbds_chemistry,
		capacity_multiplier;
	U32	oem;
};

#help_index "Devices;PCI"

//PCI Registers, used with $LK,"PCIRead",A="MN:PCIReadU16"$ functions.
#define PCIR_VENDOR_ID			0x00
#define PCIR_DEVICE_ID			0x02
#define PCIR_COMMAND			0x04
#define PCIR_STATUS 			0x06
#define PCIR_REVISION_ID		0x08
#define PCIR_PROG_IF			0x09
#define PCIR_SUB_CODE 			0x0A
#define PCIR_CLASS_CODE 		0x0B
#define PCIR_CACHE_LINE_SIZE	0x0C
#define PCIR_LATENCY_TIMER		0x0D
#define PCIR_HEADER_TYPE		0x0E
#define PCIR_BIST 				0x0F
#define PCIR_BASE0				0x10
#define PCIR_BASE1				0x14
#define PCIR_BASE2				0x18
#define PCIR_BASE3				0x1C
#define PCIR_BASE4				0x20
#define PCIR_BASE5				0x24
#define PCIR_SUBSYS_VENDOR_ID 	0x2C
#define PCIR_SUBSYS_ID			0x2E
#define PCIR_EXPANSION_ROM		0x30
#define PCIR_CAPABILITIES 		0x34
#define PCIR_INTERRUPT_LINE 	0x3C
#define PCIR_INTERRUPT_PIN		0x3D
#define PCIR_MIN_GRANT			0x3E
#define PCIR_MAX_LATENCY		0x3F

// PCI Command Register bit flags
#define	PCI_CMDf_IOEN	0	// I/O Space Enable
#define	PCI_CMDf_MSEN	1	// Memory Space Enable
#define	PCI_CMDf_BMEN	2	// Bus Master Enable
#define PCI_CMDf_INTD	10	// Interrupt Disable

#define PCI_CMDF_IOEN	(1 << PCI_CMDf_IOEN)
#define	PCI_CMDF_MSEN	(1 << PCI_CMDf_MSEN)
#define PCI_CMDF_BMEN	(1 << PCI_CMDf_BMEN)
#define PCI_CMDF_INTD	(1 << PCI_CMDf_INTD)

//PCI class codes
#define PCIC_STORAGE	0x1
#define PCIC_NETWORK	0x2
#define PCIC_MULTIMEDIA	0x4

//PCI subclass codes
#define PCISC_ETHERNET	0x0
#define PCISC_AUDIO		0x3
#define PCISC_AHCI		0x6

//PCI I/O ports
#define PCI_ADDR	0xCF8
#define PCI_DATA	0xCFC

class CPCIDev
{
	CPCIDev	*next, *last;
	U8		 bus, dev, fun,
			*vendor_str,
			*dev_id_str,
			 class_code,
			 sub_code,
			 prog_if,
			 revision_id,
			 bist,
			 header_type,
			 latency_timer,
			 cache_line_size,
			 capabilities,
			 interrupt_line,
			 interrupt_pin,
			 min_grant,
			 max_latency;
	U16		 vendor_id,
			 device_id,
			 subsys_id,
			 subsys_vendor_id;
	U32		 base[6],
			 erom;
};

#help_index "Devices;Disk/AHCI"
#define AHCI_MAX_PORTS			32

//Physical Region Descriptor Table
#define AHCI_PRD_MAX_BYTES		(4 * 1024 * 1024) //Max bytes that can go in one PRD entry ($ER$4 MiB). Section 4.2.3.3 Fig. 17 (DBC) 
#define AHCI_PRDT_MAX_BLOCKS	(U16_MAX + 1) 	  //Max blocks you can transfer in one command. 
#define AHCI_PRDT_MAX_LEN		8 				  //Max PRD entries in one command. This is equal to (MAX_BLOCKS * BLK_SIZE) ÷ MAX_BYTES.

//Global Host Control (Controller) flags
#define AHCI_GHCf_HBA_RESET			0
#define AHCI_GHCf_INTERRUPT_ENABLE	1
#define AHCI_GHCf_AHCI_ENABLE		31

#define AHCI_CAPSf_S64A		31	//Supports 64-bit Addressing

#define AHCI_CAPSEXTf_BOH	0	//Supports BIOS/OS Handoff
#define AHCI_CAPSEXTf_NVMP	1	//NVMHCI Supported & Present

//BIOS/OS Handoff Control
#define AHCI_BOHCf_BOS		0	//BIOS-Owned Semaphore (BIOS owns controller)
#define AHCI_BOHCf_OOS		1	//OS-Owned Semaphore (OS owns controller)
#define AHCI_BOHCf_BB		4	//BIOS Busy (polling bit while BIOS cleans up things after ownership transfer)

//Command Header flags
#define AHCI_CH_DESCf_A		5	//'ATAPI' bit. Set when ATAPI command is being sent.
#define AHCI_CH_DESCF_A		(1 << AHCI_CH_DESCf_A)
#define AHCI_CH_DESCf_W		6	//'Write' bit. Set when data is being written.
#define AHCI_CH_DESCF_W		(1 << AHCI_CH_DESCf_W)

//Command FIS flags
#define AHCI_CF_DESCf_C		7	//'Command' bit. Set when FIS is an ATA command.
#define AHCI_CF_DESCF_C		(1 << AHCI_CF_DESCf_C)

//Port register flags
//Command and Status register flags
#define AHCI_PxCMDf_ST		0	//'Start'. Start processing commmand list. FRE must be set before.
#define AHCI_PxCMDf_SUD		1	//'Spin-Up Device'. For devices that support Staggered Spin-up. We attempt to set it for all ports.
#define AHCI_PxCMDf_POD		2	//'Power-On Device'. For devices that support Cold Presence. We attempt to set it for all ports.
#define AHCI_PxCMDf_FRE		4	//'FIS Receive Enable'. Allows the processing of FISes.
#define AHCI_PxCMDf_FR		14	//'FIS receive Running'. Status indicator for FRE.
#define AHCI_PxCMDf_CR		15	//'Command list Running'. Status indicator for ST.
#define AHCI_PxCMDf_ATAPI	24	//'Device is ATAPI'. When set, HBA turns on desktop LED when device is in use. For ATAPI devices.
#define AHCI_PxCMDF_ST		(1 << AHCI_PxCMDf_ST)
#define AHCI_PxCMDF_SUD		(1 << AHCI_PxCMDf_SUD)
#define AHCI_PxCMDF_POD		(1 << AHCI_PxCMDf_POD)
#define AHCI_PxCMDF_FRE		(1 << AHCI_PxCMDf_FRE)
#define AHCI_PxCMDF_FR		(1 << AHCI_PxCMDf_FR)
#define AHCI_PxCMDF_CR		(1 << AHCI_PxCMDf_CR)
#define AHCI_PxCMDF_ATAPI	(1 << AHCI_PxCMDf_ATAPI)

//Task File Data register flags
#define AHCI_PxTFDf_STS_ERR	0 // Error Bit of Status register

//Signature types
#define AHCI_PxSIG_ATA		0x00000101
#define AHCI_PxSIG_ATAPI	0xEB140101
#define AHCI_PxSIG_SEMB		0xC33C0101 //Enclosure Management Bridge... rare to encounter in wild.
#define AHCI_PxSIG_PM		0x96690101 //Port multiplier... not relevant to PC-type systems.

//Interrupt flags (same in PxIE and PxIS)
#define AHCI_PxIf_OFS	24	//Overflow Status
#define AHCI_PxIf_INFS	26	//SATA Interface Non-Fatal Error
#define AHCI_PxIf_IFS	27	//SATA Interface Fatal Error
#define AHCI_PxIf_HBDS	28	//Host Bus Data Error
#define AHCI_PxIf_HBFS	29	//Host Bus Fatal Error
#define AHCI_PxIf_TFE	30	//Task File Error, see $LK,"ATAS_ERR",A="MN:ATAS_ERR"$.
#define AHCI_PxIf_CPDS	31	//Cold Port Detect Status

//COMRESET flags
//SATA Control register flags
#define AHCI_PxSCTLf_DET_INIT		1
#define AHCI_PxSCTLF_DET_INIT		(1 << AHCI_PxSCTLf_DET_INIT)
//SATA Status register flags
#define AHCI_PxSSTSF_DET_PRESENT	3

//SATA Error register flags
#define AHCI_PxSERR_ERR_I	0	// Recovered Data Integrity Error
#define AHCI_PxSERR_ERR_M	1	// Recovered Communication Error
#define AHCI_PxSERR_ERR_T	8	// Transient Data Integrity Error
#define AHCI_PxSERR_ERR_C	9	// Persistent Communication Error
#define AHCI_PxSERR_ERR_P	10	// SATA Protocol Error
#define AHCI_PxSERR_ERR_E	11	// Internal Error
#define AHCI_PxSERR_DIAG_I	17	// Phy Internal Error
#define AHCI_PxSERR_DIAG_C	21	// Link Layer CRC Error
#define AHCI_PxSERR_DIAG_H	22	// Handshake Error
#define AHCI_PxSERR_DIAG_S	23	// Link Sequence Error
#define AHCI_PxSERR_DIAG_T	24	// Transport State Transition Error

class CAHCIPort
{//Port register layout
	U32	cmd_list_base,
		cmd_list_base_upper,
		fis_base,
		fis_base_upper,
		interrupt_status,
		interrupt_enable,
		command,
		reserved,
		task_file_data,
		signature,
		sata_status,
		sata_ctrl,
		sata_error,
		sata_active,
		cmd_issue,
		sata_notif,
		fis_switch_ctrl,
		device_sleep;
	U8	reserved[40],
		vendor[16];
};

class CAHCIHba
{//HBA register layout
	U32			caps,
				ghc,		//Global Host Control
				interrupt_status,
				ports_implemented,
				version,
				ccc_ctrl,	//Command Completion Coalescing
				ccc_ports,
				em_location,//Enclosure Management
				em_ctrl,
				caps_ext,
				bohc;
	U8			reserved[116],
				vendor[96];
	CAHCIPort	ports[32];
};

#define FISt_H2D	0x27

class CFisH2D
{//Host To Device
	U8	type,
		desc,	//We are concerned with bit #7 ($LK,"AHCI_CF_DESCf_C",A="MN:AHCI_CF_DESCf_C"$) 1=command, 0=control.
		command,
		feature_low,
		lba0,
		lba1,
		lba2,
		device,
		lba3,
		lba4,
		lba5,
		feature_high;
	U16	count;
	U8	icc,
		ctrl;
	U32	reserved;
};

class CFisReceived
{
	U8	dma_fis[28],
		reserved[4],
		pio_fis[20],
		reserved[12],
		r_fis[20],
		reserved[4],
		devbits_fis[8],
		unknown_fis[64],
		reserved[96];
};

class CPrdtEntry
{
	U32	data_base,
		data_base_upper,
		reserved,
		data_byte_count; //bit 31 is "Interrupt on Completion". bits 21:0 are the actual count.
};

/*
Bits of first U32:
	4:0 - Command FIS Length, in U32s
	  5 - ATAPI bit (A) for ATAPI command
	  6 - Write bit (W) for write commands $LK,"AHCI_CH_DESCf_W",A="MN:AHCI_CH_DESCf_W"$ 1=write 0=read
	  7 - Prefetchable (P)
	  8 - Reset (R)
	  9 - Built-in Self Test (BIST)
	 10 - Clear busy upon R_OK
	 11 - Reserved
  15:12 - Port Multiplier Port (PMP)
  31:16 - Physical Region Descriptor Table Length (PRDTL)
*/
class CPortCmdHeader
{//What the CAHCIPort.cmd_list consists of.
	U16	desc,
		prdt_len;
	U32	prd_byte_count,
		cmd_table_base,
		cmd_table_base_upper,
		reserved[4];
};

class CPortCmdTable
{
	U8			cmd_fis[64],
				acmd[16],
				reserved[48];
	CPrdtEntry	prdt[8];
};

class CAtapiReadCmd
{
	U8	command,
		reserved;
	U32 lba,
		count;
	U8	reserved,
		ctrl,
		zero[4];
};

class CAtapiWriteCmd
{
	U8	command,
		reserved;
	U32 lba;
	U8	reserved;
	U16	count;
};

class CAtapiCloseCmd
{
	U8	command,
		reserved,
		code,
		reserved;
	U16	track_num;
};

class CAtapiModeHeader
{
	U16	data_length;
	U8	reserved[4];
	U16	block_desc_len;
};

class CAtapiModeWritePage
{
	U8	code,	//0
		length,
		type,
		mode,
		block_type,
		link_size,
		reserved,
		host_app_code,
		session_format,
		reserved; // 9
	U32	packet_size; // 10-13
	U16	audio_pause_length;// 14-15
	U8	media_catalog_num[16],//16-31
		recording_code[16],//32-47
		sub_0,
		sub_1,
		sub_2,
		sub_3;
};

class CAtapiModeWriteList
{
	CAtapiModeHeader	header;
	CAtapiModeWritePage	page;
};

//ATA_IDENTIFY command array indexes (array of U16s)
#define ATA_IDENT_SERIAL_NUM		10
#define ATA_IDENT_MODEL_NUM			27
#define ATA_IDENT_LBA48_CAPACITY	100

//See $LK,"::/Doc/Credits.DD"$.
#define ATA_NOP 				0x00
#define ATA_DEV_RST 			0x08
#define ATA_PACKET				0xA0
#define ATA_READ_NATIVE_MAX 	0xF8
#define ATA_READ_NATIVE_MAX_EXT 0x27
#define ATA_SET_MAX 			0xF9
#define ATA_SET_MAX_EXT 		0x37
#define ATA_READ_MULTI			0xC4
#define ATA_READ_MULTI_EXT		0x29
#define ATA_READ_DMA_EXT		0x25
#define ATA_WRITE_MULTI 		0xC5
#define ATA_WRITE_MULTI_EXT 	0x39
#define ATA_WRITE_DMA_EXT		0x35
#define ATA_IDENTIFY			0xEC
#define ATA_IDENTIFY_PACKET		0xA1 // IDENTIFY PACKET DEVICE, mirror of ATA_IDENTIFY for ATAPI

#define ATAPI_FORMAT_UNIT			0x0400
#define ATAPI_START_STOP_UNIT		0x1B00
#define ATAPI_READ_CAPACITY			0x2500
#define ATAPI_SEEK					0x2B00
#define ATAPI_SYNC_CACHE			0x3500
#define ATAPI_MODE_SELECT			0x5500
#define ATAPI_CLOSE_TRACK_SESSION	0x5B00
#define ATAPI_BLANK					0xA100
#define ATAPI_READ					0xA800
#define ATAPI_WRITE					0x2A00
#define ATAPI_SET_CD_SPEED			0xBB00

#define ATAS_ERR	0x01
#define ATAS_DRQ	0x08
#define ATAS_DF 	0x20
#define ATAS_DRDY	0x40
#define ATAS_BSY	0x80

#define ATAR0_DATA	0
#define ATAR0_FEAT	1
#define ATAR0_NSECT 2
#define ATAR0_SECT	3
#define ATAR0_LCYL	4
#define ATAR0_HCYL	5
#define ATAR0_SEL 	6
#define ATAR0_STAT	7
#define ATAR0_CMD 	7
#define ATAR1_CTRL	2

#help_index "File/FileNames"
#define FILEMASK_JIT	"*.ZC*;*.HH*"
#define FILEMASK_AOT	"*.ZC*;*.HH*;*.PRJ*"
#define FILEMASK_SRC	"*.ZC*;*.HH*;*.IN*;*.PRJ*"
#define FILEMASK_DD 	FILEMASK_SRC ";*.DD*"
#define FILEMASK_TXT	FILEMASK_DD ";*.TXT*;*.CFG*;*.CONF*"
#define FILEMASK_GR 	"*.GR*"

#help_index "File/Low Level"
#define BLK_SIZE_BITS 			9
#define BLK_SIZE				(1 << BLK_SIZE_BITS)
#define DVD_BLK_SIZE			(4 * BLK_SIZE)
#define DVD_BOOT_LOADER_SIZE	DVD_BLK_SIZE * 1
#define INVALID_CLUS			(-1)

class CMBRPart
{
	U8	active, //0x80=active  0x00=inactive
		start_head;
	U16 start_cyl;
	U8	type,
		end_head;
	U16 end_cyl;
	U32 offset, //Sectors between MBR and first sector
		size; 	//Sectors in drive
};

class CMasterBoot
{
	U8		 code[440];
	U32 	 media_id;
	U16 	 zero;
	CMBRPart p[4];
	U16 	 signature; //AA55
};

class CRedSeaBoot
{
	U8	jump_and_nop[3],
		signature, reserved[4]; //MBR_PT_REDSEA=0x88. Distinguish from real FAT32
	I64 drv_offset, 		//For CD/DVD image copy.
		sects,
		root_clus,
		bitmap_sects,
		unique_id;
	U8	code[462];
	U16 signature2; 		//0xAA55
};

class CFAT32Boot
{
	U8		jump_and_nop[3],
			oem_name[8];
	U16 	bytes_per_sect;
	U8		sects_per_clus;
	U16 	reserved_sects;
	U8		copies_of_fat;
	U16 	max_root_dir_entries, 	//Not used
			old_sects_in_drive; 		//Not used
	U8		media_desc; 						//F64 for hard disk
	U16 	old_sects_per_fat,			//Not used
			sects_per_track,
			num_heads;
	U32 	hidden_sects,
			sects,
			sects_per_fat;
	U16 	flags,
			version;
	U32 	root_clus;
	U16 	file_system_info_sect,
			backup_boot_sect;
	U8		reserved[12],
			log_drive_num,
			unused,
			ext_signature; //0x29
	U32 	serial_num;
	U8		vol_name[11],
			fat_name[8],
			code[420];
	U16 	signature;
};

class CFAT32FileInfoSect
{
	U32 	signature1;
	U8		unknown[480];
	U32 	signature2,
			free_clus,
			most_recently_alloced;
	U8		reserved[12];
	U32 	signature3;
};

class CFAT32DirEntry
{
	U8		name[11],
			attr,
			NTres,
			CrtTimeTenth;
	U16 	CrtTime,
			CrtDate,
			ListAccDate,
			clus_hi,
			WrtTime,
			WrtDate,
			clus_lo;
	U32 	size;
};

class CFAT32DirEntryLong
{
	U8		ord;
	U16 	name1[5];
	U8		attr,
			type,
			xsum;
	U16 	name2[6],
			zero,
			name3[2];
};

#define FAT32_ENTRIES_PER_BLK 	(BLK_SIZE / sizeof(CFAT32DirEntry))
#define FAT32_ENTRIES_BITS		Bsf(FAT32_ENTRIES_PER_BLK)

class CPalindromeU16
{
	U16 	little, big;
};

class CPalindromeU32
{
	U32 	little, big;
};

class CISODate
{
	U8	year, mon, day, hour, min, sec, sec100;
};

class CISODirEntry
{
	U8				len, ext_attr_len;
	CPalindromeU32	loc;
	CPalindromeU32	size;
	CISODate		date;
	U8				flags, file_unit_size, interleave;
	CPalindromeU16	vol_seq_num;
	U8				name_len, name;
};

class CISOPathEntry
{
	U8	name_len, zero;
	U32	blk;
	U16	parent_entry_num,
		name[1]; //Aligned to U16 boundaries
};

//ISO9660
#define ISOT_BOOT_RECORD		0
#define ISOT_PRI_VOL_DESC 		1
#define ISOT_SUPPLEMENTARY_DESC 2
#define ISOT_VOL_DRIVE_DESC 	3
#define ISOT_TERMINATOR 		255

class CISOPriDesc
{
	U8				type,
					id[5],
					version,
					unused1,
					system_id[32],
					vol_id[32],
					unused2[8];
	CPalindromeU32	vol_space_size;
	U8				unused3[32];
	CPalindromeU16	vol_set_size;
	CPalindromeU16	vol_seq_num;
	CPalindromeU16	log_block_size;
	CPalindromeU32	path_table_size;
	U32				type_l_path_table,
					opt_type_l_path_table,
					type_m_path_table,
					opt_type_m_path_table;
	CISODirEntry	root_dir_record;
	U8				vol_set_id[128],
					publisher_id[128],
					preparer_id[128],
					pad[307],
					file_structure_version,
					pad[1166];
};

#define ISO_BASE_YEAR	1900
#define ISO_ATTR_DIR	2

//Red Sea Attributes
//See $LK,"ST_FILE_ATTRS",A="MN:ST_FILE_ATTRS"$
#define RS_ATTR_READ_ONLY 		0x01 //R
#define RS_ATTR_HIDDEN			0x02 //H
#define RS_ATTR_SYSTEM			0x04 //S
#define RS_ATTR_VOL_ID			0x08 //V
#define RS_ATTR_DIR 			0x10 //D
#define RS_ATTR_ARCHIVE 		0x20 //A
#define RS_ATTR_LONG_NAME		(RS_ATTR_READ_ONLY | RS_ATTR_HIDDEN | RS_ATTR_SYSTEM | RS_ATTR_VOL_ID)
#define RS_ATTR_LONG_NAME_MASK	(RS_ATTR_LONG_NAME | RS_ATTR_DIR | RS_ATTR_ARCHIVE)
#define RS_ATTR_DELETED 		0x100 //X
#define RS_ATTR_RESIDENT		0x200 //T
#define RS_ATTR_CONTIGUOUS		0x400 //C
#define RS_ATTR_FIXED 			0x800 //F

#help_index "File/CD DVD"
//Media types for $LK,"DVDImageWrite",A="MN:DVDImageWrite"$()
#define MT_CD 					1
#define MT_DVD					2

#help_index "File/Low Level;File/Program Routines"
//CDirEntry flags (Used by $LK,"FileMgr",A="MN:FileMgr"$())
#define CDIR_FILENAME_LEN 			38 //Must include terminator zero
public class CDirEntry
{
	CDirEntry	*next, *parent, *sub;
	U8			*full_name;
	I64			 user_data, user_data2;

	U0			 start;
	U16			 attr;
	U8			 name[CDIR_FILENAME_LEN];
	I64			 clus, size;
	CDate		 datetime;
};
#define CDIR_SIZE (sizeof(CDirEntry) - offset(CDirEntry.start))

#help_index "File/Program Routines"
//File Util Flags
//See $LK,"ST_FILE_UTIL_FLAGS",A="MN:ST_FILE_UTIL_FLAGS"$
#define FUf_RECURSE 			0	// r
#define FUf_DIFF				1	// d
#define FUf_DEL 				1	// d
#define FUf_IGNORE				2	// i
#define FUf_ALL 				3	// a
#define FUf_CANCEL				4	// c
#define FUf_REPLACE 			5	// R
#define FUf_PUBLIC				6	// p
#define FUf_MAP 				7	// m
#define FUf_SINGLE				8	// s
#define FUf_JUST_DIRS 			9	// D
#define FUf_JUST_FILES			10	// F
#define FUf_JUST_TXT			11	// T
#define FUf_JUST_DD 			12	// $$
#define FUf_JUST_SRC			13	// S
#define FUf_JUST_AOT			14	// A
#define FUf_JUST_JIT			15	// J
#define FUf_JUST_GR 			16	// G
#define FUf_CLUS_ORDER			17	// O (Move disk head one direction)
#define FUf_SCAN_PARENTS		18	// P
#define FUf_FLATTEN_TREE		19	// f
#define FUf_WHOLE_LABELS		20	// l
#define FUf_WHOLE_LABELS_BEFORE 21	// lb
#define FUf_WHOLE_LABELS_AFTER	22	// la

#define FUF_RECURSE				(1 << FUf_RECURSE)
#define FUF_DIFF				(1 << FUf_DIFF)
#define FUF_DEL					(1 << FUf_DEL)
#define FUF_IGNORE				(1 << FUf_IGNORE)
#define FUF_ALL					(1 << FUf_ALL)
#define FUF_CANCEL				(1 << FUf_CANCEL)
#define FUF_REPLACE				(1 << FUf_REPLACE)
#define FUF_PUBLIC				(1 << FUf_PUBLIC)
#define FUF_MAP					(1 << FUf_MAP)
#define FUF_SINGLE				(1 << FUf_SINGLE)
#define FUF_JUST_DIRS			(1 << FUf_JUST_DIRS)
#define FUF_JUST_FILES			(1 << FUf_JUST_FILES)
#define FUF_JUST_TXT			(1 << FUf_JUST_TXT)
#define FUF_JUST_DD				(1 << FUf_JUST_DD)
#define FUF_JUST_SRC			(1 << FUf_JUST_SRC)
#define FUF_JUST_AOT			(1 << FUf_JUST_AOT)
#define FUF_JUST_JIT			(1 << FUf_JUST_JIT)
#define FUF_JUST_GR				(1 << FUf_JUST_GR)
#define FUF_CLUS_ORDER			(1 << FUf_CLUS_ORDER)
#define FUF_SCAN_PARENTS		(1 << FUf_SCAN_PARENTS)
#define FUF_FLATTEN_TREE		(1 << FUf_FLATTEN_TREE)
#define FUF_WHOLE_LABELS		(1 << FUf_WHOLE_LABELS)
#define FUF_WHOLE_LABELS_BEFORE	(1 << FUf_WHOLE_LABELS_BEFORE)
#define FUF_WHOLE_LABELS_AFTER	(1 << FUf_WHOLE_LABELS_AFTER)

#define FUG_FILES_FIND	(FUF_RECURSE | FUF_SINGLE | FUF_CLUS_ORDER | FUF_JUST_DIRS | FUF_JUST_FILES | FUF_JUST_TXT | \
						 FUF_JUST_DD | FUF_JUST_SRC | FUF_JUST_AOT | FUF_JUST_JIT | FUF_JUST_GR | FUF_FLATTEN_TREE)
#define FUG_FILE_FIND 	(FUF_JUST_DIRS | FUF_JUST_FILES | FUF_SCAN_PARENTS)

#help_index "File/Low Level"
//See $LK,"ST_BLKDEV_TYPES",A="MN:ST_BLKDEV_TYPES"$
#define BDT_NULL				0
#define BDT_RAM 				1
#define BDT_ATA 				2
#define BDT_ISO_FILE_READ 		3
#define BDT_ISO_FILE_WRITE		4
#define BDT_ATAPI 				5
#define BDT_TYPES_NUM 			6

#define BDf_REMOVABLE 			0
#define BDf_INITIALIZED 		1
#define BDf_READ_ONLY 			2
#define BDf_READ_ONLY_OVERRIDE	3
#define BDf_LAST_WAS_WRITE		4
#define BDf_READ_CACHE			5
#define BDf_FORMAT				6
#define BDf_INIT_IN_PROGRESS	7
#define BDf_EXT_SIZE			8
#define BDf_INTERNAL_BUF		9

#define BDF_REMOVABLE 			(1 << BDf_REMOVABLE)
#define BDF_INITIALIZED 		(1 << BDf_INITIALIZED)
#define BDF_READ_ONLY 			(1 << BDf_READ_ONLY)
#define BDF_READ_ONLY_OVERRIDE	(1 << BDf_READ_ONLY_OVERRIDE)
#define BDF_LAST_WAS_WRITE		(1 << BDf_LAST_WAS_WRITE)
#define BDF_READ_CACHE			(1 << BDf_READ_CACHE)
#define BDF_FORMAT				(1 << BDf_FORMAT)
#define BDF_INIT_IN_PROGRESS	(1 << BDf_INIT_IN_PROGRESS)
#define BDF_EXT_SIZE			(1 << BDf_EXT_SIZE)
#define BDF_INTERNAL_BUF		(1 << BDf_INTERNAL_BUF)

//locked flags
#define BDlf_LOCKED 			0

#define BLKDEVS_NUM 			26
#define BD_SIGNATURE_VAL		'BDSV'

public class CBlkDev
{
	CBlkDev		*lock_fwding; //If two blkdevs on same controller, use just one lock
	CTask		*owning_task;
	CAHCIPort	*ahci_port;
	U8			*prd_buf,
				 first_drive_let,
				*RAM_disk,
				*file_disk_name;
	CFile		*file_disk;
	U32 		 bd_signature,
				 type,
				 flags,
				 blk_size,
				 max_reads,
				 max_writes;
	I64 		 drv_offset,
				 init_root_dir_blks,
				 max_blk,
				 locked_flags,
				 port_num;
	U16 		*dev_id_record;
	F64 		 last_time;
};

//Drive locked_flags
#define DVlf_LOCKED 	0

//See $LK,"ST_DRIVE_TYPES",A="MN:ST_DRIVE_TYPES"$
#define FSt_NULL		0
#define FSt_REDSEA		1 //Supported
#define FSt_FAT32 		2 //Supported except for short names, to some degree
#define FSt_ISO9660 	3 //Supported (CD/DVD)
#define FSt_NTFS		4 //Not Supported
#define FSt_LINUX		5 //Not Supported
#define FSt_SWAP		6 //Not Supported
#define FSt_UNKNOWN 	7
#define FSt_TYPES_NUM 	8
#define FSG_TYPE_MASK 	0x7FFF
//File system type flags
#define FStf_DISABLE	15

#define MBR_PT_FAT32a 	0x0B
#define MBR_PT_FAT32b 	0x0C
#define MBR_PT_FAT32c 	0x1B
#define MBR_PT_FAT32d 	0x1C
#define MBR_PT_FAT32e 	0x8B
#define MBR_PT_FAT32f 	0x8C
#define MBR_PT_NTFS 	0x07
#define MBR_PT_REDSEA 	0x88
#define MBR_PT_LINUX	0x83
#define MBR_PT_SWAP		0x82

class CFreeList
{
	CFreeList	*next, *last;
	I64			 start, size;
};

#define DRIVES_NUM				26

#define DRIVE_SIGNATURE_VAL 	'DVSV'
public class CDrive
{
//Don't access ->drv_let directly in case a drive has been remapped.
	//Use $LK,"Drive2Letter",A="MN:Drive2Letter"$().
	I64					 locked_flags;
	U32					 drive_signature;
	U8					 drv_let, pad;
	U16					 fs_type;
	I64					 drv_offset,
						 size,
						 prt_num,
						 file_system_info_sect,
						 fat1, fat2,
						 root_clus,
						 data_area,
						 spc; //sectors per cluster
	CDate				 fat32_local_time_offset;
	CTask				*owning_task;
	CBlkDev				*bd;

	CFAT32FileInfoSect	*fis;
	I64					 fat_blk_dirty,
						 cur_fat_blk_num;
	U32					*cur_fat_blk;
	CFreeList			*next_free, *last_free;
};

#define DISK_CACHE_HASH_SIZE		0x2000

class CCacheBlk
{
	CCacheBlk	*next_lru,  *last_lru;
	CCacheBlk	*next_hash, *last_hash;
	CDrive		*drive;
	I64			 blk;
	U8			 body[BLK_SIZE];
};

#help_index "File/System"
#define DEFAULT_ISO_FILENAME	"::/Tmp/CDDVD.ISO"
#define DEFAULT_ISO_C_FILENAME	"::/Tmp/CDDVD.ISO.C"

public class CBlkDevGlobals
{
	CBlkDev	   *blkdevs;
	CDrive	   *drvs,
			   *let_to_drive[32];
	CAHCIHba   *ahci_hba;
	U8		   *default_iso_filename,	//$TX,"\"::/Tmp/CDDVD.ISO\"",D="DEFAULT_ISO_FILENAME"$
			   *default_iso_c_filename,	//$TX,"\"::/Tmp/CDDVD.ISO.C\"",D="DEFAULT_ISO_C_FILENAME"$
			   *tmp_filename,
			   *home_dir,
			    boot_drive_let,
				first_hd_drive_let,
			    first_dvd_drive_let;
	CCacheBlk  *cache_base,
			   *cache_ctrl,
			  **cache_hash_table;
	I64 		cache_size,
				read_count,
				write_count,
				mount_ide_auto_count,
				cmd_slot_count,
				ins_port;// Installed-from CD/DVD controller.
	Bool		dvd_boot_is_good,
				ahci64;
};

#help_index "File/Internal"
public class CDirContext
{
	CDrive	*old_dv, *drive;
	U8		*old_dir, *mask;
};

#help_index "File/CFile"
#define FFB_NEXT_BLK	I64_MAX

#define FF_WRITE				1
#define FF_NEW_FILE 			2
#define FF_BUF_DIRTY			4
#define FF_NEEDS_WRITE			8
#define FF_CONTIGUOUS 			16
#define FF_USE_OLD_DATETIME 	32

public class CFile //See $LK,"::/Demo/Disk/DataBase.ZC"$.
{
	I64			 flags;
	CDirEntry	 de;
	CDrive		*drive;
	I64			 fblk_num, clus, file_clus_num, max_blk;
	U8			*clus_buf;
};

#help_index "Memory/Heap"
#define _CONFIG_HEAP_DEBUG FALSE

#if _CONFIG_HEAP_DEBUG
class CMemUnused
{
	CHeapCtrl	*hc;
	U8			*caller1, *caller2;
	CMemUnused	*next;
	I64			 size;
};
class CMemUsed
{
	CHeapCtrl	*hc;
	U8			*caller1, *caller2;
	CMemUsed	*next, *last;
	I64			 size;
	U0			 start;
};
#else
class CMemUnused
{
	U0			 hc;
	U0			 caller1, caller2;
	CMemUnused	*next;
	I64			 size;
};
class CMemUsed
{
	CHeapCtrl	*hc;
	U0			 caller1, caller2;
	U0			 next, last;
	I64			 size;
	U0			 start;
};
#endif

#help_index "Memory/BlkPool"
#help_file "::/Doc/Pags"

#define MBS_USED_SIGNATURE_VAL		'MBUs'
#define MBS_UNUSED_SIGNATURE_VAL	'MBUn'
class CMemBlk
{
	CMemBlk *next, *last;
	U32 	 mb_signature, pags;
};

#define MRT_UNUSED	0
#define MRT_RAM 	1
#define MRT_DEV 	2

class CMemRange
{
	CMemRange	*next, *last;
	U32			 type, flags;
	U8			*base;
	I64			 size;
};

#define MEM_PAG_BITS			9
#define MEM_PAG_SIZE			(1 << MEM_PAG_BITS)
#define MEM_HEAP_HASH_SIZE		1024
#define MEM_FREE_PAG_HASH_SIZE	0x100
//It is common to $LK,"MAlloc",A="MN:MAlloc"$() exact powers of two.	There is some overhead.
//We add 1 pag, so a request is not rounded-up to next power of two.
#define MEM_EXTRA_HASH2_PAGS	1

#define MEM_SYSTEM_STACK		(MEM_PAG_SIZE * 512) //Like 16384*MEM_PAG_SIZE
#define MEM_EXECUTIVE_STACK		(MEM_PAG_SIZE * 512)
#define MEM_INTERRUPT_STACK 	(MEM_PAG_SIZE * 512)
#define MEM_DEFAULT_STACK 		(MEM_PAG_SIZE * 512)

#define TASK_HASH_TABLE_SIZE	(1 << 10)

//locked flags
#define BPlf_LOCKED 			0
public class CBlkPool
{
	I64 	 locked_flags, alloced_u8s, used_u8s;
	CMemBlk	*mem_free_list,
			*mem_free_2meg_list, //This is for Sup1CodeScraps/Mem/Mem2Meg.ZC.
			*free_pag_hash[MEM_FREE_PAG_HASH_SIZE],
			*free_pag_hash2[64 - MEM_PAG_BITS];
};

#help_index "Memory/HeapCtrl"
//locked flags
#define HClf_LOCKED 	0

#define HEAP_CTRL_SIGNATURE_VAL 'HcSV'
public class CHeapCtrl
{
	CBlkPool	*bp;
	U32			 hc_signature, pad;
	I64			 locked_flags, alloced_u8s, used_u8s;
	CTask		*mem_task;
	CMemBlk		*next_mem_blk, *last_mem_blk;
	CMemBlk		*last_mergable;
	CMemUnused	*malloc_free_list;
	CMemUsed	*next_um, *last_um;
	CMemUnused	*heap_hash[MEM_HEAP_HASH_SIZE / sizeof(U8 *)];
};

#help_index "Devices;Memory/Page Tables"
public class CDevGlobals
{
	CIDTEntry	*idt;
	U8			*mem64_ptr;
	U8			*uncached_alias; //Alias of lowest 4Gig.
	U8			 mp_apic_ids[MP_PROCESSORS_NUM];
	CMemRange	 mem32_head;
	CPCIDev		 pci_head;
	U64			 user_int_bitmap;
};

#help_index "Graphics/Color;Graphics/Device Contexts"
//Raster operations
#define ROPB_EQU					0x00
#define ROPB_XOR					0x01
#define ROPB_COLLISION				0x02
#define ROPB_MONO 					0x03
#define ROPBF_HALF_RANGE_COLOR		0x10
#define ROPBF_TWO_SIDED 			0x20
#define ROPBF_DITHER				0x40
#define ROPBF_PROBABILITY_DITHER	0x80

#define ROP_EQU 		(ROPB_EQU << 8)
#define ROP_XOR 		(ROPB_XOR << 8)
#define ROP_COLLISION	(ROPB_COLLISION << 8)
#define ROP_MONO		(ROPB_MONO << 8)

//These are just for $LK,"ROPF_PROBABILITY_DITHER",A="MN:ROPF_PROBABILITY_DITHER"$
//See $LK,"DCLighting",A="MN:DCLighting"$().
#define ROPF_HALF_RANGE_COLOR 	0x1000
#define ROPF_TWO_SIDED			0x2000

//These always go in the c1.rop of a CColorROPU32
#define ROPF_DITHER 				0x40000000
#define ROPF_PROBABILITY_DITHER 	0x80000000

#help_index "Graphics/Color"
#define TRANSPARENT		0xFF
#define BLACK 			0
#define BLUE			1
#define GREEN 			2
#define CYAN			3
#define RED 			4
#define PURPLE			5
#define BROWN 			6
#define LTGRAY			7
#define DKGRAY			8
#define LTBLUE			9
#define LTGREEN 		10
#define LTCYAN			11
#define LTRED 			12
#define LTPURPLE		13
#define YELLOW			14
#define WHITE 			15

#define COLORS_NUM		16
#define COLOR_INVALID	16
#define COLOR_MONO		0xFF

public U16 class CColorROPU16 //Don't use this, use CColorROPU32
{
	U8		color, rop;
};
public U32 class CColorROPU32
{
	CColorROPU16 c0, c1;
};
#define COLORROP_COLORS_MASK	0x00FF00FF
#define COLORROP_NO_ROP0_MASK 	0xFFFF00FF
#define COLORROP_BITS 			16
public U32 class CBGR24
{
	U8		b, g, r, pad;
};
public U32 class CBGR32
{
	U8		b, g, r, a;
};
public I64 class CBGR48
{
	U16 	b, g, r, pad;
};

#help_index "Keyboard Devices;Char/Input;StdIn"
#define KBD_PORT	0x60
#define KBD_CTRL	0x64

#define KBDC_LED		0xED
#define KBDC_DISABLE_MS 0xA7
#define KBDC_ENABLE_MS	0xA8
#define KBDC_ENABLE_KBD 0xAE
#define KBDC_TYPEMATIC	0xF3
#define KBDC_SCAN_CODES 0xF0

public class CKbdStateGlobals
{
	I64			 scan_code,			//See $LK,"scan codes",A="FI:::/Doc/CharOverview.DD"$
				 last_down_scan_code,
				 count,				//Count of keys pressed since boot.
				 timestamp,			//Output: TSCGet when event.
				 new_key_timestamp;	//Output: TSCGet when new key event.
	CFifoU8		*fifo, *fifo2;		//Private
	CFifoI64	*scan_code_fifo;
	U32			 down_bitmap[8],	//BitTest, $LK,"Bt",A="MN:Bt"$(), with a merged scan code. (Left and right shift merged, for example.)
				 down_bitmap2[8];	//BitTest, $LK,"Bt",A="MN:Bt"$(), with an unmerged scan code.
	Bool		 reset,				//Private: Reset KbdMouse
				 irqs_working; 		//Private
};

#help_index "Mouse"
class CMouseRawQueue:CQueue
{
	CTask *task;
};

public class CMouseHardStateGlobals
{
	CD3I64	 pos, 					//Position in pixels
			 prescale,
			 raw_data;
	CD3 	 scale;
	F64 	 speed;					//Output: How fast the user is moving it.
	I64 	 timestamp,				//Output: TSCGet when event.
			 install_attempts,		//Private
			 pkt_size;				//Private
	CFifoU8	*fifo, *fifo2;			//Private
	CQueue	*raw_queue;
	Bool	 bttns[5],
			 raw_bttns[5],
			 has_wheel,
			 has_ext_bttns,
			 enabled,
			 event,					//Private
			 installed,				//Private
			 install_in_progress,	//Private
			 irqs_working;			//Private
};

public class CMouseStateGlobals
{
	CD3I64	pos, 				//Position in pixels
			pos_text, 			//Position in text rows,cols
			presnap,
			offset;
	CD3 	scale;
	F64 	speed;				//Output: How fast the user is moving it.
	I64 	timestamp;			//Output: TSCGet when event.
	F64 	dbl_time, 			//Input: Time threshold for calling it a double click.
			left_dbl_time,		//Private
			right_dbl_time;		//Private
	Bool	lb, 				//Left Button
			rb, 				//Right Button
			show,
			has_wheel,
			left_dbl, 			//Private
			left_down_sent,		//Private
			right_dbl,			//Private
			right_down_sent;	//Private
};

public class CGridGlobals
{
	Bool	snap		format "$$CB,\"Snap Grid\"$$\n",
			show		format "$$CB,\"Show Grid\"$$\n",
			coord		format "$$CB,\"Show Coordinates\"$$\n";
	U8		pad[5];
	F64 	x 			format "$$DA-TRM,A=\"X Spacing:%6.3f\"$$\n",
			y 			format "$$DA-TRM,A=\"Y Spacing:%6.3f\"$$\n",
			z 			format "$$DA-TRM,A=\"Z Spacing:%6.3f\"$$\n",
			x_offset	format "$$DA-TRM,A=\"X Offset :%6.3f\"$$\n",
			y_offset	format "$$DA-TRM,A=\"Y Offset :%6.3f\"$$\n",
			z_offset	format "$$DA-TRM,A=\"Z Offset :%6.3f\"$$\n",
			x_speed		format "$$DA-TRM,A=\"X Speed  :%6.3f\"$$\n",
			y_speed		format "$$DA-TRM,A=\"Y Speed  :%6.3f\"$$\n",
			z_speed		format "$$DA-TRM,A=\"Z Speed  :%6.3f\"$$\n";
};

#help_index "Ctrls"
#define CTRLT_GENERIC 			0
#define CTRLT_WIN_HSCROLL 		1 //unique
#define CTRLT_WIN_VSCROLL 		2 //unique
#define CTRLT_VIEWING_ANGLES	3 //unique

#define CTRLF_SHOW				1
#define CTRLF_BORDER			2
#define CTRLF_CAPTURE_LEFT_MS 	4
#define CTRLF_CAPTURE_RIGHT_MS	8
#define CTRLF_CLICKED 			16

#define WSSf_SET_TO_POS 	0

public class CWinScroll
{
	I64 	min, pos, max;
	U32 	flags;
	U8		color, pad[3];
};

public class CViewAngles
{
	I64				sx, sy, sz;
	F64				ax, ay, az;
	CColorROPU32	cx, cy, cz, cbd, cbg, config;
};

public class CCtrl
{
	CCtrl	*next, *last;
	CTask	*win_task;
	I64		 type, flags;

	//win pix coordinates
	I64 	 left, right, top, bottom;

	//screen pix coordinates (derived)
	I64 	 screen_left, screen_right, screen_top, screen_bottom;

	U8		*state;

	//called on resize
	U0	   (*update_derived_vals)(CCtrl *c);
	U0	   (*draw_it)(CDC *dc,    CCtrl *c);

	Bool   (*inside_ctrl)(CCtrl *c, I64 x, I64 y); //For nonbox shapes
	U0	   (*left_click)( CCtrl *c, I64 x, I64 y, Bool down);
	U0	   (*right_click)(CCtrl *c, I64 x, I64 y, Bool down);
	U0	   (*wheel_chg)(  CCtrl *c, I64 delta);
};

#help_index "Menus"
public class CMenuEntry
{
	CMenuEntry	*next;
	CMenuEntry	*sub;
	U8			 name[32];
	I64			 message_code, arg1, arg2;
	Bool		 checked, dir, pad[6];
};

public class CMenu
{
	CMenu		*next;
	CMenuEntry	*sub;
	CTask		*task;
	I64			 flags;
	U8			 attr, pad[7];
};

#help_index "Task"
class CBpt
{
	CBpt	*next;
	U8		*addr,
			 val, pad[7];
};

class CExcept
{
	CExcept *next, *last;
	I64 	 handler_catch, handler_untry,
			 rsp, rbp, rflags, rsi, rdi, r10, r11, r12, r13, r14, r15;
};

class CFPU
{
	U8		body[512];
};

#help_index "Job/Exe;Task/Job/Exe"
#define JOBf_WAKE_MASTER		0
#define JOBf_FOCUS_MASTER 		1
#define JOBf_EXIT_ON_COMPLETE 	2
#define JOBf_DONT_FILTER		3
#define JOBf_HIGHEST_PRIORITY 	4
//MP flags
#define JOBf_DONE 				5
#define JOBf_DISPATCHED 		6
#define JOBf_FREE_ON_COMPLETE 	7
#define JOBf_ADD_TO_QUE 		8

#define JOBT_TEXT_INPUT	0 //$LK,"TaskText",A="MN:TaskText"$() 	Feed StdIn
#define JOBT_MESSAGE	1 //$LK,"TaskMessage",A="MN:TaskMessage"$() 		Post message
#define JOBT_EXE_STR	2 //$LK,"TaskExe",A="MN:TaskExe"$() 		Compile & execute src code text
//MP cmds
#define JOBT_CALL		3 //$LK,"JobQueue",A="MN:JobQueue"$() 	Tell MP to call function
#define JOBT_SPAWN_TASK	4 //$LK,"Spawn",A="MN:Spawn"$() Tell MP to spawn task

class CJob
{
	CJob		*next, *last;
	CJobCtrl	*ctrl;
	I64			 job_code, flags, message_code;

	I64		   (*addr)(U8 *fun_arg);
	U8			*fun_arg;

	U8			*aux_str;
	I64			 aux1, aux2, //Sometimes called arg1 and arg2. (Windows message param1 param2)
				 res;

	CTask		*spawned_task,
				*master_task;
};

#define JOBCf_LOCKED	0
class CJobCtrl
{
	CJob *next_waiting, *last_waiting;
	CJob *next_done,    *last_done;
	I64   flags;
};

#help_index "Messages"
//See $LK,"::/Demo/MessageLoop.ZC"$
#define MESSAGE_NULL			0
#define MESSAGE_CMD 			1
#define MESSAGE_KEY_DOWN		2  //($LK,"ASCII",A="MN:CH_CTRLA"$,$LK,"scan code",A="FI:::/Doc/CharOverview.DD"$) Press <CTRL-SHIFT-L>
#define MESSAGE_KEY_UP			3  //($LK,"ASCII",A="MN:CH_CTRLA"$,$LK,"scan code",A="FI:::/Doc/CharOverview.DD"$) Press <CTRL-SHIFT-L>
#define MESSAGE_MS_MOVE 		4  //(x,y)
#define MESSAGE_MS_L_DOWN 		5  //(x,y)
#define MESSAGE_MS_L_UP 		6  //(x,y)
#define MESSAGE_MS_L_D_DOWN 	7  //(x,y)
#define MESSAGE_MS_L_D_UP 		8  //(x,y)
#define MESSAGE_MS_R_DOWN 		9  //(x,y)
#define MESSAGE_MS_R_UP 		10 //(x,y)
#define MESSAGE_MS_R_D_DOWN 	11 //(x,y)
#define MESSAGE_MS_R_D_UP 		12 //(x,y)

//Fake messages used to send both an up and down.
#define MESSAGE_KEY_DOWN_UP 	-2	//Down & UP
#define MESSAGE_MS_L_DOWN_UP	-5	//Down & Up
#define MESSAGE_MS_L_D_DOWN_UP	-7	//Down & Up
#define MESSAGE_MS_R_DOWN_UP	-9	//Down & Up
#define MESSAGE_MS_R_D_DOWN_UP	-11 //Down & Up

#help_index "Task/Settings"
#define TSF_SAME_SONG 	1
public class CTaskSettings
{
	CTaskSettings	*next;
	U8				*cur_dir;
	I64				 left, right, top, bottom;
	U0			   (*draw_it)(CTask *task, CDC *dc);
	U0			   (*task_end_cb)();
	CTask			*song_task, *animate_task;
	I64				 scroll_x, scroll_y, scroll_z;
	CBGR24			 palette[COLORS_NUM];
	U32				 win_inhibit;
	U8				 text_attr,   title_src,
					 border_attr, border_src,
					 task_title[STR_LEN];
	Bool			 border, hide_cursor, highlight_cursor, scroll, autocomplete, pad[3];
#assert !($$ & 7)
};

#help_index "Task"
//CTask.border_src
#define BDS_CONST 				0
#define BDS_CUR_DRIVE 			1
#define BDS_ED_FILENAME_DRIVE 	2

//CTask.title_src
#define TTS_CONST 			0
#define TTS_LOCKED_CONST	1 //This is not strictly enforced
#define TTS_TASK_NAME 		2
#define TTS_ED_FILENAME 	3
#define TTS_CUR_LEX 		4

//CTask.task_flags
//See $LK,"ST_TASK_FLAGS",A="MN:ST_TASK_FLAGS"$
#define TASKf_TASK_LOCK 			0
#define TASKf_KILL_TASK 			1
#define TASKf_SUSPENDED 			2
#define TASKf_IDLE					3
#define TASKf_CMD_LINE_PROMPT 		4
#define TASKf_INPUT_FILTER_TASK 	5
#define TASKf_FILTER_INPUT			6
#define TASKf_HAS_SONG				7
#define TASKf_DISABLE_BPTS			8
#define TASKf_AWAITING_MESSAGE		9
#define TASKf_BREAK_LOCKED			10
#define TASKf_PENDING_BREAK 		11
#define TASKf_BREAK_TO_SHIFT_ESC	12
#define TASKf_KILL_AFTER_DEBUG		13
#define TASKf_NONTIMER_RAND 		14
#define TASKf_FLAGS_NUM				15

//CTask.display_flags
#define DISPLAYf_SHOW 					0
#define DISPLAYf_NOT_RAW				1
#define DISPLAYf_SILENT 				2
#define DISPLAYf_NO_BORDER				3
#define DISPLAYf_WIN_ON_TOP 			4
#define DISPLAYf_CHILDREN_NOT_ON_TOP	5
#define DISPLAYf_FLAGS_NUM				6

#define TASK_SIGNATURE_VAL		'TskS'
#define TASK_NAME_LEN 			32
#define TASK_EXCEPT_CALLERS		8
class CTaskStack
{
	CTaskStack	*next_stack;
	I64			 stack_size, stack_ptr;
	U0			 stack_base;
};

#define DYING_JIFFIES 	ToI64(JIFFY_FREQ / 5)
class CTaskDying
{
	CTask	*next, *last;
	I64 	 wake_jiffy;
};

public class CTask //The Fs segment register points to current CTask.
{
	CTask			*addr; //Self-addressed pointer
	U32				 task_signature, win_inhibit;
#assert $$ == offset(CTaskDying.wake_jiffy)
	I64				 wake_jiffy;
	U32				 task_flags, display_flags;

	CHeapCtrl		*code_heap, *data_heap;

	CDoc			*put_doc, *display_doc, //When double buffering, these two differ.
					*border_doc;
	I64				 win_left, win_right, win_top, win_bottom;

	CDrive			*cur_dv;
	U8				*cur_dir;

	CTask			*parent_task,
					*next_task,              *last_task,
					*next_input_filter_task, *last_input_filter_task,
					*next_sibling_task,      *last_sibling_task,
					*next_child_task,        *last_child_task;

	//These are derived from left,top,right,bottom
	I64				 win_width, win_height,
					 pix_left, pix_right,  pix_width, //These are in pixs, not characters
					 pix_top,  pix_bottom, pix_height,
					 scroll_x, scroll_y, scroll_z;

	//These must be in this order
	//for $LK,"TASK_CONTEXT_SAVE",A="FF:::/Kernel/Sched.ZC,TASK_CONTEXT_SAVE"$ and $LK,"_TASK_CONTEXT_RESTORE",A="FF:::/Kernel/Sched.ZC,_TASK_CONTEXT_RESTORE"$
	I64				 rip, rflags, rsp, rsi, rax, rcx, rdx, rbx, rbp, rdi, r8, r9, r10, r11, r12, r13, r14, r15;
	CCPU			*gs;
	CFPU			*fpu_mmx;
	I64				 swap_counter;

	U0			   (*draw_it)(CTask *task, CDC *dc);

	U8				 task_title[STR_LEN],
					 task_name[TASK_NAME_LEN],
					 wallpaper_data[4096],

					 title_src, border_src,
					 text_attr, border_attr;
	U16				 win_z_num, pad;

	CTaskStack		*stack;

	CExcept			*next_except, *last_except;
	I64				 except_rbp, 		//throw routine's RBP
					 except_ch;			//throw(ch)
	U8				*except_callers[TASK_EXCEPT_CALLERS];

	Bool			 catch_except;
	Bool			 new_answer;
	U8				 answer_type, pad[5];
	I64				 answer;
	F64				 answer_time;
	CBpt			*bpt_list;
	CCtrl			*next_ctrl, *last_ctrl;
	CMenu			*cur_menu;
	CTaskSettings	*next_settings;
	CMathODE		*next_ode, *last_ode;
	F64				 last_ode_time;
	CHashTable		*hash_table;

	CJobCtrl		 server_ctrl;
	CCompCtrl		*next_cc, *last_cc;
	CHashFun		*last_fun;

	U0			   (*task_end_cb)();
	CTask			*song_task, *animate_task;
	I64				 rand_seed,
					 task_num,
					 fault_num, fault_err_code;
	CTask			*popup_task,
					*debug_task;
	CWinScroll		 horz_scroll, vert_scroll;

	I64				 user_data;
#assert !($$ & 7)
};

class CTSS
{
	U32 	 res1;
	I64 	 rsp0, rsp1, rsp2, res2,
			 ist1, ist2, ist3, ist4, ist5, ist6, ist7, res3;
	U16 	 res4, io_map_offset;
	U8		 io_map[0x10000/8];
	I64 	*st0, *st1, *st2;
	U16 	 tr, tr_ring3;
};

#define ans 	(Fs->answer)
#define ansf	(Fs->answer(F64))

#define _RAX Fs->rax
#define _RBX Fs->rbx
#define _RCX Fs->rcx
#define _RDX Fs->rdx
#define _RSI Fs->rsi
#define _RDI Fs->rdi
#define _RBP Fs->rbp
#define _RSP Fs->rsp
#define _RIP Fs->rip
#define _R8  Fs->r8
#define _R9  Fs->r9
#define _R10 Fs->r10
#define _R11 Fs->r11
#define _R12 Fs->r12
#define _R13 Fs->r13
#define _R14 Fs->r14
#define _R15 Fs->r15

#help_index "MultiCore"
#define CPUf_RAN_A_TASK 		0
#define CPUf_DYING_TASK_QUE 	1

public class CCPU //The Gs segment register points to current CCPU.
{
	CCPU		*addr; //Self-addressed pointer
	I64			 num, cpu_flags,
				 startup_rip,
				 idle_pt_hits;
	F64			 idle_factor;
	I64			 total_jiffies;
	CTask		*executive_task, *idle_task;
	I64			 tr, 	//task reg
				 swap_counter;
	U0		   (*profiler_timer_irq)(CTask *task);
	CTaskDying	*next_dying, *last_dying;
	I64			 kill_jiffy;
	CTSS		*tss;
	I64			 start_stack[16];
#assert !($$ & 7)
};

#help_index "Memory/Page Tables"
#define MEM_MIN_MEG 			256 //256 Meg minimum.

#define SYS_FIXED_AREA			0x100000
#define SYS_16MEG_AREA_LIMIT	0x1000000
public class CSysFixedArea
{
	CFPU		init_fpu_mmx;
	CCPU		boot_cpu;
	CTask		system;
	CBlkPool	sys_code_bp;
	CHeapCtrl	system_hc;
	$$ = ($$ + 0x1000 - 1) & -0x1000;
};

#help_index "Char"
#define CH_CTRLA		0x01
#define CH_CTRLB		0x02
#define CH_CTRLC		0x03
#define CH_CTRLD		0x04
#define CH_CTRLE		0x05
#define CH_CTRLF		0x06
#define CH_CTRLG		0x07
#define CH_CTRLH		0x08
#define CH_CTRLI		0x09
#define CH_CTRLJ		0x0A
#define CH_CTRLK		0x0B
#define CH_CTRLL		0x0C
#define CH_CTRLM		0x0D
#define CH_CTRLN		0x0E
#define CH_CTRLO		0x0F
#define CH_CTRLP		0x10
#define CH_CTRLQ		0x11
#define CH_CTRLR		0x12
#define CH_CTRLS		0x13
#define CH_CTRLT		0x14
#define CH_CTRLU		0x15
#define CH_CTRLV		0x16
#define CH_CTRLW		0x17
#define CH_CTRLX		0x18
#define CH_CTRLY		0x19
#define CH_CTRLZ		0x1A
#define CH_CURSOR 		0x05
#define CH_BACKSPACE	0x08
#define CH_ESC			0x1B
#define CH_SHIFT_ESC	0x1C
#define CH_SPACE		0x20

#define ST_ERR_ST 	"$$RED$$$$BK,1$$ERROR:$$FG$$$$BK,0$$ "
#define ST_WARN_ST	"$$LTRED$$$$BK,1$$WARNING:$$FG$$$$BK,0$$ "

//Scan code flags
#define SCf_E0_PREFIX 	7
#define SCf_KEY_UP		8
#define SCf_SHIFT 		9
#define SCf_CTRL		10
#define SCf_ALT 		11
#define SCf_CAPS		12
#define SCf_NUM 		13
#define SCf_SCROLL		14
#define SCf_NEW_KEY 	15
#define SCf_MS_L_DOWN 	16
#define SCf_MS_R_DOWN 	17
#define SCf_DELETE		18
#define SCf_INS 		19
#define SCf_NO_SHIFT	30
#define SCf_KEY_DESC	31
#define SCF_E0_PREFIX 	(1 << SCf_E0_PREFIX)
#define SCF_KEY_UP		(1 << SCf_KEY_UP)
#define SCF_SHIFT 		(1 << SCf_SHIFT)
#define SCF_CTRL		(1 << SCf_CTRL)
#define SCF_ALT 		(1 << SCf_ALT)
#define SCF_CAPS		(1 << SCf_CAPS)
#define SCF_NUM 		(1 << SCf_NUM)
#define SCF_SCROLL		(1 << SCf_SCROLL)
#define SCF_NEW_KEY 	(1 << SCf_NEW_KEY)
#define SCF_MS_L_DOWN 	(1 << SCf_MS_L_DOWN)
#define SCF_MS_R_DOWN 	(1 << SCf_MS_R_DOWN)
#define SCF_DELETE		(1 << SCf_DELETE)
#define SCF_INS 		(1 << SCf_INS)
#define SCF_NO_SHIFT	(1 << SCf_NO_SHIFT)
#define SCF_KEY_DESC	(1 << SCf_KEY_DESC)

//ZealOS places a 1 in bit 7 for
//keys with an E0 prefix.
//See $LK,"::/Doc/CharOverview.DD"$ and $LK,"KbdHandler",A="MN:KbdHandler"$().
#define SC_ESC			0x01
#define SC_BACKSPACE	0x0E
#define SC_TAB			0x0F
#define SC_ENTER		0x1C
#define SC_SHIFT		0x2A
#define SC_CTRL 		0x1D
#define SC_ALT			0x38
#define SC_CAPS 		0x3A
#define SC_NUM			0x45
#define SC_SCROLL 		0x46
#define SC_CURSOR_UP	0x48
#define SC_CURSOR_DOWN	0x50
#define SC_CURSOR_LEFT	0x4B
#define SC_CURSOR_RIGHT 0x4D
#define SC_PAGE_UP		0x49
#define SC_PAGE_DOWN	0x51
#define SC_HOME 		0x47
#define SC_END			0x4F
#define SC_INS			0x52
#define SC_DELETE 		0x53
#define SC_F1 			0x3B
#define SC_F2 			0x3C
#define SC_F3 			0x3D
#define SC_F4 			0x3E
#define SC_F5 			0x3F
#define SC_F6 			0x40
#define SC_F7 			0x41
#define SC_F8 			0x42
#define SC_F9 			0x43
#define SC_F10			0x44
#define SC_F11			0x57
#define SC_F12			0x58
#define SC_PAUSE		0x61
#define SC_GUI			0xDB
#define SC_PRINTSCREEN1 0xAA
#define SC_PRINTSCREEN2 0xB7

#help_index "Char;Debugging/Raw Output;TextBase Layer/Char"
//text.raw_flags
#define RAWF_IN_DOLLAR		1
#define RAWF_LAST_DOLLAR	2
#define RAWF_SHOW_DOLLAR	4
#define RAWF_SCROLL 		8

public class CTextGlobals
{
	I64 	 raw_col, raw_flags;
	U32 	*raw_screen, *fb_alias;
	I64 	 rows, cols;	//Use TEXT_ROWS,TEXT_COLS
	U64 	*font, *aux_font, screen_size, buffer_size;
	U8		 border_chars[16];
	Bool	 is_fb_busy;
};

#define FONT_WIDTH		8
#define FONT_HEIGHT 	8

#help_index "Graphics"
//z-values less than zero are in front of screen and not drawn.
//we want to shift all Z-values into a drawable range.
//GR_Z_ALL is set to half of the Z-range which is an I32.
#define GR_Z_ALL	(I32_MAX/2)

#help_index "Graphics/Device Contexts"
//Low 8 bits reserved for flags that go into saved bitmaps
#define DCF_PALETTE 			1
#define DCF_NO_TRANSPARENTS 	2 //Can be used to optimized $LK,"GrBlot",A="MN:GrBlot"$().

#define DCF_TRANSFORMATION		0x100

//See $LK,"DCSymmetrySet",A="MN:DCSymmetrySet"$() or $LK,"DCSymmetry3Set",A="MN:DCSymmetry3Set"$()
#define DCF_SYMMETRY			0x200

//Must be used with DCF_SYMMETRY set also.
//See $LK,"::/Demo/Games/BigGuns.ZC"$
#define DCF_JUST_MIRROR 		0x400

#define DCF_LOCATE_NEAREST		0x800
#define DCF_DONT_DRAW 			0x1000
#define DCF_ALIAS 				0x2000
#define DCF_SCREEN_BITMAP 		0x4000
#define DCF_FILL_NOT_COLOR		0x8000
#define DCF_RECORD_EXTENTS		0x10000
#define DCF_ON_TOP				0x20000

//$LK,"DCSave",A="MN:DCSave"$() flags.
#define DCSF_PALETTE_GET	1

#define DCS_SIGNATURE_VAL	'DvCS'

class CGrSym
{
	I32 	sx, sy, sz, pad;
//Normal of symmetry plane
	I64 	snx, sny, snz;
};

public class CDC
{
	U0				 start;
	CDate			 cdt;
	I32				 x0, y0,
					 width, width_internal,
					 height,
					 flags;
	U0				 end;
	CBGR24			 palette[COLORS_NUM];

	//public (Change directly)
	CColorROPU32	 color,
					 bkcolor, //Set for use with $LK,"ROP_COLLISION",A="MN:ROP_COLLISION"$
					 color2; //Internally used for $LK,"GrFloodFill",A="MN:GrFloodFill"$()
	CD3I32			 ls; //Light source (should be normalized to 65536).

	//dither_probability_u16 is basically a U16.
	//It is activated by $LK,"ROPF_PROBABILITY_DITHER",A="MN:ROPF_PROBABILITY_DITHER"$.
	//0x0000 =100% color.c0
	//0x8000 =50%  color.c0 	50% color.c1
	//0x10000=100% color.c1
	//See $LK,"::/Demo/Graphics/SunMoon.ZC"$ and	$LK,"::/Demo/Graphics/Shading.ZC"$.
	U64				 dither_probability_u16;

	CDC				*brush;

	//Set with $LK,"DCMat4x4Set",A="MN:DCMat4x4Set"$().  $LK,"Free",A="MN:Free"$() before setting.
	I64				*r, //rotation matrix of quads decimal in lo
					 r_norm; //shifted 32 bits.	Used for scaling thick

	//public (Change directly)
	I32				 x, y, z,
					 thick;

	//Can be changed from the default $LK,"DCTransform",A="MN:DCTransform"$()
	U0			   (*transform)(CDC *dc, I64 *x, I64 *y, I64 *z);

	//Can be changed from the default $LK,"DCLighting",A="MN:DCLighting"$()
	U0			   (*lighting)(CDC *dc, CD3I32 *p1, CD3I32 *p2, CD3I32 *p3, CColorROPU32 color);

	//Set by $LK,"DCSymmetrySet",A="MN:DCSymmetrySet"$() or $LK,"DCSymmetry3Set",A="MN:DCSymmetry3Set"$()
	CGrSym			 sym;

	I32				 cur_x, cur_y, cur_z, pad;
	I64				 collision_count;

	I64				 nearest_dist,
					 min_x, max_x, min_y, max_y; //Set by $LK,"DCF_RECORD_EXTENTS",A="MN:DCF_RECORD_EXTENTS"$ (screen coordinates)

	U32				 dc_signature, pad;
	CTask			*mem_task, *win_task;
	CDC				*alias;
	U8				*body;

	//Set by $LK,"DCDepthBufAlloc",A="MN:DCDepthBufAlloc"$()
	I32				*depth_buf;
	I64				 db_z; //private
#assert !($$ & 7)
};

#define "Char/Input;StdIn"
//StrGet flags
#define SGF_SHIFT_ESC_EXIT			1 //This kills task on <SHIFT-ESC>
#define SGF_WITH_NEW_LINE 			2

#define "Char/Operations"
//Flags for StrUtil and MStrUtil
#define SUF_REM_CTRL_CHARS	0x001
#define SUF_REM_LEADING 	0x002
#define SUF_REM_TRAILING	0x004
#define SUF_REM_SPACES		0x008
#define SUF_SINGLE_SPACE	0x010
#define SUF_TO_UPPER		0x020
#define SUF_TO_LOWER		0x040
#define SUF_S2T 			0x080
#define SUF_T2S 			0x100 // Only works with MStrUtil
#define SUF_SCALE_INDENT	0x200
#define SUF_SAFE_DOLLAR 	0x400

//Flags for StrFind
#define SFF_IGNORE_CASE 		1
#define SFF_WHOLE_LABELS_BEFORE 2
#define SFF_WHOLE_LABELS_AFTER	4
#define SFG_WHOLE_LABELS		(SFF_WHOLE_LABELS_BEFORE | SFF_WHOLE_LABELS_AFTER)

//Flags for ListMatch
#define LMF_IGNORE_CASE 	1
#define LMF_EXACT 			2

#help_index "Keyboard Devices/System"
#define KDF_HAS_DESCS 	1
class CKeyDevEntry
{
	CKeyDevEntry	*next, *last;
	I64				 priority, flags;
	Bool		   (*put_key)(I64 ch, I64 sc);
	Bool		   (*put_s)(U8 *st);
};

class CKeyDevGlobals
{
	CKeyDevEntry	 put_key_head;
	U0			  (**fp_ctrl_alt_cbs)(I64 sc);
	I64				 ctrl_alt_in_irq_flags,
				   **ctrl_alt_ret_addr; //address of ret address on stack in kbd irq
	U8			   **ctrl_alt_no_shift_descs, **ctrl_alt_shift_descs,
					 desc[STR_LEN],
					*handler;
};

#help_index "Sound"
#define PCSPKR	0x61
#help_index "ScreenCast;Sound/AU Files"
public class CAUData
{//Format of AU files
	CDate	cdt;
	I8		ona;
};

class CSoundData
{//Format recorded in mem
	CSoundData	*next, *last;
	F64			 tS;
	I8			 ona;
};

public class CScreenCastGlobals
{
	CSoundData	 sound_head;
	CDate		 t0_now;
	F64			 t0_tS;
	U8			*print_format;
	CDC			*dc, *dc2_alias;
	Bool		 record, just_audio;
	I8			 ona;
};

#help_index "Debugging/FunSeg"
#define FUN_SEG_CACHE_SIZE			256
class CFunSegCache
{
	I64 	base, limit;
	F64 	time_stamp;
	U8		str[1]; //FUN_SEG_CACHE_STR_LEN
$$ = 64;
};
#define FUN_SEG_CACHE_STR_LEN 	(sizeof(CFunSegCache) - offset(CFunSegCache.str))

#help_index "Debugging"
class CMPCrash
{
	I64		 cpu_num;
	CTask	*task;
	I64		 rip;
	U8		*message;
	I64		 message_num;
};

public class CDebugGlobals
{
	CTask			*focus_task;
	U8				*message;
	I64				 message_num;
	CMPCrash		*mp_crash;
	U8				*int_fault_code,
					*fix_file_line;
	CFunSegCache	*fun_seg_cache;
	I64				 fun_seg_cache_index;
	Bool			 panic;
};

#help_index "Boot"
//Boot related
#define BOOT_RAM_BASE 		0x07C00
#define BOOT_RAM_LIMIT		0x97000
#define BOOT_STACK_SIZE 	BLK_SIZE

#define BOOT_SRC_NULL 		0
#define BOOT_SRC_ROM		1
#define BOOT_SRC_RAM		2
#define BOOT_SRC_HARDDRIVE	3
#define BOOT_SRC_DVD		4

// $LK,"In",A="MN:In"$("") StdIn for call to $LK,"BootHDIns",A="MN:BootHDIns"$().
#define STD_DISTRO_DVD_CONFIG 	"TB\nScale2Mem(2048,0x40000)\nT\n\n\n\n"

#help_index "Registry"
//Registry sys_message_flags. $LK,"RegOneTimePopUp",A="MN:RegOneTimePopUp"$()
#define ARf_FLOODFILL 				0
#define ARf_CSPRITE_INS_CLIP		1
#define ARf_PLANAR_SYMMETRY 		2
#define ARf_PSALMODY_JUKEBOX		3
#define ARf_MESH_ED 				4
#define ARf_CSPRITE_PTS_RECTANGLES	5
#define ARf_MANAGE_SLIDER 			6

#help_index "Misc/Progress Bars"
#define PROGRESS_BARS_NUM 			4
#define PROGRESS_DESC_LEN 			(64 - 8 - 8)
class CProgress
{
	I64 	val, max;
	F64 	t0, tf;
	U8		desc[PROGRESS_DESC_LEN];
};

#help_index "Char/Operations"
#define PRINTF_PAD_ZERO 			0x001
#define PRINTF_LEFT_JUSTIFY 		0x002
#define PRINTF_TRUNCATE 			0x004
#define PRINTF_COMMA				0x008
#define PRINTF_DOLLAR 				0x010
#define PRINTF_SLASH				0x020
#define PRINTF_QUESTION 			0x040
#define PRINTF_AUX_FORMAT_NUM 		0x080
#define PRINTF_DECIMAL				0x100
#define PRINTF_NEG					0x200
#define PRINTF_NEG_E				0x400
#define PRINTF_NEG_AUX_FORMAT_NUM	0x800

#help_index ""
