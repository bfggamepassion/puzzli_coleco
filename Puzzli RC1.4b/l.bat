path c:\sdcc\bin
@echo off
sdcc -mz80 --code-loc 0x8048 --data-loc 0x7000 --no-std-crt0 ../crtcv.rel ../cvlib.lib ../getput.lib charset.rel levels.rel main.rel menu.rel puzzli_logo.rel sound.rel splash0.rel textes.rel
objcopy --input-target=ihex --output-target=binary crtcv.ihx result.rom
del *.ihx
del crtcv.lnk
pause
