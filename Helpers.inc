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
	PrintAt  	MACRO X, Y, Code
		PUSH	EAX
			MOV 	EAX,	EDX
			ADD  	 DL, BYTE PTR X
			ADD  	 DH, BYTE PTR Y 
			CALL 	Gotoxy
			MOV 	EDX,	EAX
		POP		EAX
		Write   Code
		ENDM
	PrintAtCoord  	MACRO Coord, Index, Code
		PUSH	EAX
			MOV 	EAX,	EDX
			ADD  	 DL, BYTE PTR Coord[Index*4].X
			ADD  	 DH, BYTE PTR Coord[Index*4].Y 
			CALL 	Gotoxy
			MOV 	EDX,	EAX
		POP		EAX
		Write   Code
		ENDM
	DecAtCoord  	MACRO Coord, Index, Dec
		PUSH	EAX
			MOV 	EAX,	EDX
			ADD  	 DL, BYTE PTR Coord[Index*4].X
			ADD  	 DH, BYTE PTR Coord[Index*4].Y 
			CALL 	Gotoxy
			MOV 	EDX,	EAX
		POP		EAX
		MOV EAX, Dec
		.IF	EAX < 10
			WriteD  0
			WriteD  Dec
		.ELSE
			WriteD 	Dec
		.ENDIF
		ENDM
	WriteDAtCoord 	MACRO Coord, Dec
			PUSH	EAX
			MOV 	EAX,	EDX
			ADD  	 DL, BYTE PTR Coord.X
			ADD  	 DH, BYTE PTR Coord.Y 
			CALL 	Gotoxy
			MOV 	EDX,	EAX
		POP		EAX
		MOV EAX, Dec
		.IF	EAX < 10
			WriteD  0
			WriteD  Dec
		.ELSE
			WriteD 	Dec
		.ENDIF
		ENDM

	WriteSAtCoord 	MACRO Coord, String

		PUSH EAX
		PUSH ECX
		PUSH ESI

			MOV 	EAX,	EDX
			ADD  	 DL, BYTE PTR Coord.X
			ADD  	 DH, BYTE PTR Coord.Y 
			CALL 	Gotoxy
			MOV 	EDX,	EAX

			MOV EDX, String
			CALL WriteString

		POP EAX
		POP ECX
		POP ESI

		ENDM

	SettingColor MACRO Color
		PUSH 	EAX
			MOV 	EAX, Color
			CALL	SetTextColor
		POP 	EAX
		ENDM
	DefaultColor MACRO
		PUSH 	EAX
			MOV 	EAX, 00000111b
			CALL	SetTextColor
		POP 	EAX
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

	NL	 EQU <Write 0AH>
	Dump EQU <CALL DumpRegs>	
	CLS  EQU <CALL 	ClrScr>	
	CLSALL  EQU <CALL 	ForceCLS>	



	CLST MACRO
	    push        Eax
	    mov         Eax,0b800h  ; Start at memory 0b800
	    mov         esP,Eax
	    xor         Edi,Edi

	    mov         Ecx,2000  ; 
	    mov         Eax,0720h; Black bg, white fg, 20h = space char

	    rep         stosw
	           pop         esP
	    pop         Eax 
	   ENDM

.Code

	ForceCLS  PROC
		PUSH ECX
		Translate 0,0	;Gotoxy 0, 0
		LoopTimes 50	;Same AS MOV ECX, 50
		;SettingColor Black ;Set Font Color to Black
		NewLine:
			PUSH ECX
				LoopTimes 115
				BLANKS:
					Write 65
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

