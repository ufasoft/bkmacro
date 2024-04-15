### (c) 1990-2024 Ufasoft https://ufasoft.com, Sergey Pavlov mailto:dev@ufasoft.com
### Copyright (c) 1990-2024 Ufasoft  http://ufasoft.com  mailto:support@ufasoft.com,  Sergey Pavlov  mailto:dev@ufasoft.com
###
### SPDX-License-Identifier: MIT

### Makefile for building BkMacro for following systems:
###   BK-0010.01


MACRO11=RT11 MACRO

SOURCES	= macro.mac editor.mac init.mac defcfg.inc pdp11.inc exampl.inc

macro.bin: $(SOURCES) bk10.mlb
	$(MACRO11) /LIST:macro.lst macro.mac+bk10.mlb/LIB
	pclink11 /EXECUTE:macro.sav macro.OBJ
#	bash -c "tail -c +495 macro.sav | head -c $$((4 + `od -An --skip-bytes=496 -N2 -d macro.sav`)) >$@"
#	bash -c "tail -c +4097 macro.sav | head -c $$((4 + `od -An --skip-bytes=4098 -N2 -d macro.sav`)) >$@"
	bash -c "tail -c +8193 macro.sav | head -c $$((4 + `od -An --skip-bytes=8194 -N2 -d macro.sav`)) >$@"

bk10.mlb: bk10.cfg
	RT11 LIBRARY/MACRO/CREATE bk10 bk10.cfg


clean:
	-rm *.bin *.11m *.LST *.OBJ *.sav
