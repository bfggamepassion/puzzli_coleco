path c:\sdcc\bin
@echo off
sdcc -mz80 -c --std-c99 --opt-code-speed charset.c
del charset.lst
del charset.sym
del charset.asm
sdcc -mz80 -c --std-c99 --opt-code-speed levels.c
del levels.lst
del levels.sym
del levels.asm
sdcc -mz80 -c --std-c99 --opt-code-speed main.c
del main.lst
del main.sym
del main.asm
sdcc -mz80 -c --std-c99 --opt-code-speed menu.c
del menu.lst
del menu.sym
del menu.asm
sdcc -mz80 -c --std-c99 --opt-code-speed puzzli_logo.c
del puzzli_logo.lst
del puzzli_logo.sym
del puzzli_logo.asm
sdcc -mz80 -c --std-c99 --opt-code-speed sound.c
del sound.lst
del sound.sym
del sound.asm
sdcc -mz80 -c --std-c99 --opt-code-speed splash0.c
del splash0.lst
del splash0.sym
del splash0.asm
sdcc -mz80 -c --std-c99 --opt-code-speed textes.c
del textes.lst
del textes.sym
del textes.asm
pause
