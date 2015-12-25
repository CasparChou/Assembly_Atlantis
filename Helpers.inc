.Data


	LoopTimes	MACRO	Times
		MOV 	ECX,	Times
	ENDM
	Translate	MACRO X, Y
		MOV  	dl, BYTE PTR X
		MOV  	dh, BYTE PTR Y
		CALL 	Gotoxy  
		ENDM
	;Position 	MACRO X, Y
	;	MOV 	EAX,	EDX
	;	MOV  	 DL, 	X
	;	MOV  	 DH, 	Y 
	;	CALL 	Gotoxy
	;	MOV 	EDX,	EAX
	;	ENDM
	;PrintAt  	MACRO X, Y, Code
	;	PUSH	EAX
	;		MOV 	EAX,	EDX
	;		ADD  	 DL, BYTE PTR X
	;		ADD  	 DH, BYTE PTR Y 
	;		CALL 	Gotoxy
	;		MOV 	EDX,	EAX
	;	POP		EAX
	;	Write   Code
	;	ENDM
	;PrintAtCoord  	MACRO Coord, Index, Code
	;	PUSH	EAX
	;		MOV 	EAX,	EDX
	;		ADD  	 DL, BYTE PTR Coord[Index*4].X
	;		ADD  	 DH, BYTE PTR Coord[Index*4].Y 
	;		CALL 	Gotoxy
	;		MOV 	EDX,	EAX
	;	POP		EAX
	;	Write   Code
	;	ENDM
	DecAtCoord  	MACRO CoordX, CoordY, Dec
		PUSH	EAX
			MOV 	EAX,	EDX
			MOV  	 DL, BYTE PTR CoordX
			MOV  	 DH, BYTE PTR CoordY
			CALL 	Gotoxy
			MOV 	EDX,	EAX
		POP		EAX
		WriteD  Dec
		;MOV EAX, Dec
		;.IF	Dec < 10
		;	WriteD  0
		;	WriteD  Dec
		;.ELSE
		;	WriteD 	Dec
		;.ENDIF
		ENDM
	;WriteDAtCoord 	MACRO Coord, Dec
	;		PUSH	EAX
	;		MOV 	EAX,	EDX
	;		ADD  	 DL, BYTE PTR Coord.X
	;		ADD  	 DH, BYTE PTR Coord.Y 
	;		CALL 	Gotoxy
	;		MOV 	EDX,	EAX
	;	POP		EAX
	;	MOV EAX, Dec
	;	.IF	EAX < 10
	;		WriteD  0
	;		WriteD  Dec
	;	.ELSE
	;		WriteD 	Dec
	;	.ENDIF
	;	ENDM
;
	WriteSAtCoord 	MACRO CoordX,	CoordY, String
;
		PUSH EAX
		PUSH ECX
		PUSH ESI
;
			MOV 	EAX,	EDX
			MOV  	 DL, BYTE PTR CoordX
			MOV  	 DH, BYTE PTR CoordY 
			CALL 	Gotoxy
			MOV 	EDX,	EAX
;
			MOV EDX, String
			CALL WriteString
;
		POP EAX
		POP ECX
		POP ESI
;
		ENDM
	WriteSAtCenter	MACRO	Center,		Top,	String

		MOV 	ECX,	Center
		MOV 	EBX,	SIZEOF String
		SHR		EBX,	1
		SUB 	ECX,	EBX
		MOV 	SetterBuffer,	ECX


		WriteSAtCoord 	SetterBuffer,	Top, OFFSET String
		ENDM

	SettingColor MACRO Color
		.IF( ClearOn == 0)
			PUSH 	EAX
				MOV 	EAX, Color
				CALL	SetTextColor
			POP 	EAX
		.ENDIF
		ENDM
	DefaultColor MACRO
		.IF( ClearOn == 0)
			PUSH 	EAX
				MOV 	EAX, 00000111b
				CALL	SetTextColor
			POP 	EAX
		.ENDIF
		ENDM
	Write 		MACRO Code
		PUSH 	EAX
			MOV 	EAX,	Code
			CALL 	WriteChar
		POP 	EAX
		ENDM
	WriteD 		MACRO Dec
		PUSH 	EAX
			MOV 	EAX,	Dec
			CALL 	WriteDec
		POP 	EAX
		ENDM
	WriteI 		MACRO Int
		PUSH 	EAX
			MOV 	EAX,	Int
			CALL 	WriteInt
		POP 	EAX
		ENDM
	WriteH 		MACRO Hex
		PUSH 	EAX
			MOV 	EAX,	Hex
			CALL 	WriteHex
		POP 	EAX
		ENDM
	WriteS 		MACRO String
		PUSH EDX
		PUSH ECX
		PUSH ESI

			MOV EDX, OFFSET String
			CALL WriteString

		POP ECX
		POP ECX
		POP ESI
		ENDM
	WriteSAddr	MACRO String
		PUSH EDX
		PUSH ECX
		PUSH ESI

			MOV EDX, String
			CALL WriteString

		POP ECX
		POP ECX
		POP ESI
		ENDM

	NEXT		MACRO 	WHERE
		DEC ECX
		JNZ WHERE
		ENDM
	NEXTINC		MACRO 	LIMIT, WHERE
		INC ECX
		CMP ECX, LIMIT
		JL WHERE
		ENDM


	PauseTime MACRO Timer
		PUSH 	EAX
		MOV 	EAX, Timer
		CALL 	Delay
		POP 	EAX
		ENDM
	ReadI	  MACRO StoreTo
		PUSH 	EAX
		CALL 	ReadInt
		MOV 	StoreTo, EAX
		POP 	EAX
		ENDM
	ReadS 	  MACRO InputHandler
		PUSH ECX
		PUSH EDX
			MOV EDX, OFFSET InputHandler
			MOV ECX, (SIZEOF InputHandler)-1
			CALL ReadString
		POP ECX
		POP EDX
	ENDM
	Random 	  MACRO Range, Output
		PUSH EAX
		CALL 	Randomize
		MOV  	EAX, Range
		CALL 	RandomRange 
		MOV  	Output, EAX
		POP EAX
	ENDM
	AnyKeyToContinue MACRO
		PUSH EAX
			CALL ReadChar
		POP  EAX
	ENDM
	CopyFrom MACRO A, B
		PUSH EAX
			MOV EAX, B
			MOV A, 	EAX
		POP EAX
	ENDM
	CopyAddrFrom MACRO A, B
		PUSHA
			LEA  ESI,  B
			MOV  A, ESI
		POPA
	ENDM
	AddBy MACRO A, B
		PUSH EAX
			MOV EAX, B
			ADD A, 	EAX
		POP EAX
	ENDM
	ExitMain MACRO
		;Translate 20,20
		;PrintAt 0,0, 20H
		EXIT
	ENDM

	CopyStringFrom MACRO A, B
		PUSH 	ESI
		PUSH 	EDI
		PUSH 	ECX
			MOV		ESI, 0
			MOV		ESI, 0
			MOV 	ECX, SIZEOF B
			MOV 	ESI, OFFSET B
			MOV 	EDI, OFFSET A

		POP 	ESI
		POP 	EDI
		POP 	ECX
	ENDM

	ResetReg	MACRO
		MOV EAX, 0h
		MOV EBX, 0h
		MOV ECX, 0h
		MOV EDX, 0h
		MOV ESI, 0h
		MOV EDI, 0h
		ENDM
	NL	 EQU <Write 0AH>
	Dump EQU <CALL DumpRegs>	
	CLS  EQU <CALL 	ClrScr>	
	CLSALL  EQU <CALL 	ForceCLS>	


.Code

	ForceCLS  PROC
		PUSH ECX
		Translate 0,0	;Gotoxy 0, 0
		LoopTimes 50	;Same AS MOV ECX, 50
		SettingColor Black ;Set Font Color to Black
		NewLine:
			PUSH ECX
				LoopTimes 115
				BLANKS:
					Write 020H
					; Same As MOV EAX, 020H 
					; CALL 	WriteChar
					Loop BLANKS
			POP  ECX
			NL ;New Line
			Loop NewLine
		POP  ECX
		Translate 0,0 	;Gotoxy 0, 0
		DefaultColor 	;Set Font Color to Default
		RET
	ForceCLS ENDP

	CoppingString PROC
		CoppingS:
			MOV 	AL,	[ESI]
			MOV 	[EDI], AL
	        INC 	ESI
	        INC 	EDI
	        LOOP 	CoppingS
	    RET
	CoppingString ENDP

.Code

	;ArrayShift PROC, 	Array:DWORD,		ArraySize:DWORD
	;	LoopTimes ArraySize
	;	MOV ESI, Array
	;	AS1:
	;		MOV EAX, 0h
	;		MOV AL, [ESI]
	;		CALL WriteChar
	;		INC ESI
	;		LOOP AS1
;
	;	MOV EAX, Array
	;	;CALL WriteString
	;	;DUMP
	;	SHL Array, 4
	;	;MOV EAX, Array
	;	;DUMP
	;	LoopTimes ArraySize
	;	MOV ESI, Array
	;	AS2:
	;		MOV EAX, 0h
	;		MOV AL, [ESI]
	;		CALL WriteChar
	;		INC ESI
	;		LOOP AS2
;
;
	;	RET
	;ArrayShift ENDP



.Code


		ArrayDump 	PROC, Array:DWORD
		PUSHA
			MOV 	EAX, 0
			MOV 	ESI, Array
			LOOPC:
			MOV 	AL, 	[ESI]
			;DUMP
			.IF( AL != -1 )
				CALL 	WriteDec
				ADD ESI, 4
				NL
				JMP LOOPC
			.ENDIF

		POPA
		RET
		ArrayDump 	ENDP

		ArrayPOP	PROC,	Array:DWORD
			MOV 	ESI, 	Array
			MOV 	EBX,    1
			MOV 	ECX, 	0
			MOV 	EAX, 	[ESI]
			.IF( AL == 0 )
				RET
			.ENDIF
			LOOPA:
				MOV EAX, 	[ESI]
				.IF( AL == 0 )
					INC	EBX
				.ENDIF
				.IF( AL != -1 )
					INC		ECX
					MOV 	EDX, 	EAX
					PUSH 	EDX
					ADD 	ESI, 4
					JMP 	LOOPA
				.ENDIF
			.IF( EBX == ECX )
				MOV 	ESI, 	Array
				CopyFrom [ESI],	00h
				RET
			.ENDIF
			DEC EBX
			MOV 		ESI, 	Array
			LOOPB:
				MOV 	EAX,	ECX 
				DEC 	EAX	
				SHL		EAX,	2
				ADD 	ESI, 	EAX
			FILLZERO:
				MOV 	[ESI], DWORD PTR 00h
				.IF( EBX > 0 )
					SUB 	ESI, 4
					DEC EBX
					DEC ECX
					JMP FILLZERO
				.ENDIF
			DEC ECX
			MOV ESI, 	Array
			ADD ESI,	EAX

			.REPEAT
				POP 	EDX
				SUB 	ESI, 4
			.UNTIL EDX != 0
			FILLNUM:
				
				MOV 	[ESI], EDX
				POP 	EDX
				SUB 	ESI, 4
				LOOP 	FILLNUM
		RET
		ArrayPOP 	ENDP

		ArrayPUSH 	PROC, 	Array:DWORD,	Num:DWORD
			PUSHA
			MOV 	ESI, 	Array
			MOV 	EAX, [ESI]
			.WHILE EAX > 0
				ADD ESI, 4
				MOV EAX, [ESI]
			.ENDW

			.IF( EAX == -1 )
				RET
			.ENDIF

			CopyFrom [ESI], Num
			POPA
		RET
		ArrayPUSH 	ENDP

.Data

	PushArray MACRO	Array,	Num
		INVOKE ArrayPUSH, OFFSET Array, Num
		ENDM

	PopArray MACRO	Array
		INVOKE ArrayPOP, OFFSET Array
		ENDM

	DumpArray MACRO	Array
		INVOKE ArrayDump, OFFSET Array
		ENDM

COMMENT *

	TO USE ArrayPOP
	EXAMPLE:
		INVOKE ArrayPOP, OFFSET YOUR_ARRAY
	
	TO USE ArrayPUSH
	EXAMPLE:
		INVOKE ArrayPUSH, OFFSET YOUR_ARRAY, NUMBER

	TO USE ArrayPOP
	EXAMPLE:
		INVOKE ArrayDump, OFFSET YOUR_ARRAY

*		