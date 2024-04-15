;;; Copyright (c) 2021-2022 Ufasoft  http://ufasoft.com  mailto:support@ufasoft.com,  Sergey Pavlov  mailto:dev@ufasoft.com
;;;
;;; SPDX-License-Identifier: MIT

;;; Default Configuration definitions for BkMacro


; .INCLUDE /config.inc/

.MCALL	.CFG
.CFG

.LIST	ME		; Macro expansions
.ENABL	AMA		; address mode 37
.DSABL	GBL
.ENABL	LC


...EMT = 1		; Use EMT API for BK-0011M

;; Define C$xxxx on C.xxxx definitions
;; C.xxx are necessary because bash/make/nmake have inconsistent escaping rules of '$' char
.IIF DF C.RT11,	C$RT11=C.RT11
.IIF DF C.BK10,	C$BK10=C.BK10
.IIF DF C.BK11,	C$BK11=C.BK11


.IIF NDF C$RT11, 	C$RT11 	= 0			; Define for RT-11
.IIF NE C$BK11		C$BK10 = 0
.IIF NDF C$BK10, 	C$BK10	= 1 - C$RT11		; Define for BK-0010.01 conditional compilation
.IIF NDF C$BK11,	C$BK11	= 1 - <C$BK10 ! C$RT11>	; Define for BK-0011 conditional compilation
.IIF NDF C$B11M,	C$B11M	= C$BK11		; Define for BK-0011M conditional compilation

.IIF NDF C$VM1,		C$VM1	= C$BK10 ! C$BK11	; Define to enable unaligned word access
.IIF NDF C$1801,	C$1801	= C$VM1			; K1801 family
