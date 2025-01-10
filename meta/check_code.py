#!/usr/bin/env python3

import os
from pathlib import Path

os.chdir(os.path.realpath(os.path.dirname(__file__))+'/../src')

for f in Path(os.getcwd()).glob('**/*'):
    if not f.is_file():
        continue

    if not os.path.basename(f).lower().endswith('.zc'):
        continue

    contents = b''
    with open(f, 'r+b') as file:
        contents = file.read()

        n = contents.find(b'\x05')
        byte = contents[n]

        if n == -1: continue
        if contents[n-1] == 0 or contents[n-1] > 127: continue
        if n+1 < len(contents) and contents[n+1] == 5: continue
        if contents[n-1] <= 0x1F and (not contents[n-1] in b'\n\r'): continue
        if n+1 < len(contents) and contents[n+1] <= 0x1F and (not contents[n+1] in b'\n\r'): continue

        contents = contents[0:n:]

        file.seek(0)
        file.truncate()
        file.write(contents)

