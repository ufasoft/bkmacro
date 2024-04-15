;; The starting state of BkMacro text buffer to show an example of MACRO-11 Syntax

.ASCII	";; Example program to show features of the Macro Assembler."
.ASCII	<C.NL>";; To delete and start from"<C.NL>
.ASCII	<C.NL>";; scratch press "<C.CY.S><C.CY.U>"-A, "<$K.DEL><C.NL>
.ASCII	<C.NL>".	= 1016"
.ASCII	<C.NL>"START:	MOVB	%7, R1"	; %7 is PC
.ASCII	<C.NL>"	MOV	#19., R2"
.ASCII	<C.NL>"1$:	NEG	R2"
.ASCII	<C.NL>"	ADD	(PC), R2	; R2 += 20."
.ASCII	<C.NL>"	EMT	24		; Set cursor"
.ASCII	<C.NL>"	EMT	16		; Print char"
.ASCII	<C.NL>"	BMI	1$"
.ASCII	<C.NL>"	SUB	#6, %1"		; %1 is R1
.ASCII	<C.NL>"	BHI	1$"
.ASCII	<C.NL>"	ADD	#19., R1"
.ASCII	<C.NL>"	MOVB	PC, R0		; R0: '*'"
.ASCII	<C.NL>"	SOB	R2, 1$"
.ASCII	<C.NL>"	RETURN"
.ASCII	<C.NL>";;========"
.ASCII	<C.NL>";; Macros:"
.ASCII	<C.NL>".MACRO	PUSH	c, d, e, f, g, h"
.ASCII	<C.NL>"	.IRP	x, <c, d, e, f, g, h>"
.ASCII	<C.NL>"		.IIF	B, x,	.MEXIT"
.ASCII	<C.NL>"		MOV	x, -(SP)"
.ASCII	<C.NL>"	.ENDR"
.ASCII	<C.NL>".ENDM"
.ASCII	<C.NL>
.ASCII	<C.NL>".MACRO	POP	c, d, e, f, g, h"
.ASCII	<C.NL>"	.IRP	x, <c, d, e, f, g, h>"
.ASCII	<C.NL>"		.IIF	B, x,	.MEXIT"
.ASCII	<C.NL>"		MOV	(SP)+, x"
.ASCII	<C.NL>"	.ENDR"
.ASCII	<C.NL>".ENDM"
.ASCII	<C.NL>";;========"
.ASCII	<C.NL>";; Directives:"
.ASCII	<C.NL>"	.ENABL	AMA		; address mode 37"
.ASCII	<C.NL>"	.DSABL	AMA		; address mode 67"
.ASCII	<C.NL>"	.BYTE	1, 2"
.ASCII	<C.NL>"	.WORD	1, 2"
.ASCII	<C.NL>"	.BLKB	6"
.ASCII	<C.NL>"	.BLKW	2"
.ASCII	<C.NL>"	.FLT2	0, 1.5, -0.025"
.ASCII	<C.NL>"	.FLT4	0, 1.5, -0.025"
.ASCII	<C.NL>"	.WORD	^B010101	; Binary"
.ASCII	<C.NL>"	.WORD	^C17700		; Complement"
.ASCII	<C.NL>"	.WORD	^F3.14159	; 16-bit Float"
.ASCII	<C.NL>"	.WORD	^Rabc		; RADIX-50"
.ASCII	<C.NL>"	.WORD	1 + 3, 4 * 5, 70 / 3, 3 & 5, 6 ! 9.	; Arithmetics"
.ASCII	<C.NL>"	.WORD	189.	 	; Decimal"
.ASCII	<C.NL>"	.RADIX	10"
.ASCII	<C.NL>"	.WORD	189"
.ASCII	<C.NL>"	.ODD"
.ASCII	<C.NL>"	.ASCII	!abc!"
.ASCII	<C.NL>"	.ASCIZ	/DEF/"
.ASCII	<C.NL>"	.EVEN"
.ASCII	<C.NL>"	.RAD50	/RADIX50/"
.ASCII	<C.NL>"	.IRPC	ch, <12AaB.>"
.ASCII	<C.NL>"	MOV	#'ch, R0"
.ASCII	<C.NL>"	.ENDR"
.ASCII	<C.NL>"	.REPT	4"
.ASCII	<C.NL>"		ASR	R0"
.ASCII	<C.NL>"	.ENDR"
.ASCII	<C.NL>"	.IF EQ 1"
.ASCII	<C.NL>"		SEC"
.ASCII	<C.NL>"		.ERROR aa  ; some error"

.ASCII	<C.NL>"	.IFF"
.ASCII	<C.NL>"		CLC"
.ASCII	<C.NL>"	.IFT"
.ASCII	<C.NL>"		MFPS	R1"
.ASCII	<C.NL>"	.IFTF"
.ASCII	<C.NL>"		MARK	6"
.ASCII	<C.NL>"	.ENDC"
.ASCII	<C.NL>"	.REM	&"
.ASCII	<C.NL>"Multiline comment"
.ASCII	<C.NL>"ends here &"
.ASCII	<C.NL>".END	START"<C.NL>