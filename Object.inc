.Data

	
	RegisterObjects	EQU <CALL Register>
	DrawSoldiers 	EQU <CALL DrawingSoldiers>
	Initial 		EQU <CALL Init>
	

	BuildUserSoldierA EQU <BuildSoldier UserSoldiers, 0, 1>
	BuildUserSoldierB EQU <BuildSoldier UserSoldiers, 0, 2>
	BuildUserSoldierC EQU <BuildSoldier UserSoldiers, 0, 3>

	BuildCompSoldierA EQU <BuildSoldier CompSoldiers, 1, 1>
	BuildCompSoldierB EQU <BuildSoldier CompSoldiers, 1, 2>
	BuildCompSoldierC EQU <BuildSoldier CompSoldiers, 1, 3>


	Soldier STRUCT
		HP			DWORD 0
		X			DWORD 0
		Y 			DWORD 0
		ATK			DWORD 0

		Level		DWORD 0
		Arms		DWORD 0
		League		DWORD 0

		State		DWORD 0
		Alive		DWORD 0
	Soldier ENDS


	UserSoldiers	Soldier	8 DUP(<0,0,0,0,0,0,0>)
	CompSoldiers	Soldier	8 DUP(<0,0,0,0,0,0,0>)

	
	UserSoldier_Height	DWORD	3, 4, 4,	;A
								3, 3, 3,	;B
								3, 4, 5		;C

	UserSoldier_Width	DWORD	3, 4, 4,	;A
								3, 3, 3,	;B
								3, 4, 5		;C

	CompSoldier_Height	DWORD	4, 4, 6,	;A
								3, 5, 5,	;B
								2, 5, 6		;C

	CompSoldier_Width	DWORD	3, 4, 4,	;A
								3, 3, 3,	;B
								3, 4, 5		;C


	Soldier_HP			DWORD	4, 6, 8,	;A
								3, 4, 5,	;B
								5, 8, 11	;C

	Soldier_Attack		DWORD	2, 4, 6,	;A
								3, 6, 9,	;B
								1, 2, 3		;C

	Soldier_Buffer		DWORD	4, 6, 7,	;A
								5, 7, 8,	;B
								6, 8, 9		;C


	ObjectOffset MACRO ID
		MOV EAX, (SIZEOF Soldier)
		MOV EBX, ID
		MUL EBX
		MOV EBX, EAX
	ENDM

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Getter / Setter 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	GettingSoldierLevel		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].Level
		POPA
		ENDM
	SettingSoldierLevel		MACRO	Object, ID, Number
		PUSHA
			ObjectOffset 	ID
			CopyFrom		Object[EBX].Level, Number
		POPA
		ENDM

	GettingSoldierX		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].X
		POPA
		ENDM
	SettingSoldierX		MACRO	Object, ID, Number
		PUSHA
			ObjectOffset 	ID
			CopyFrom		Object[EBX].X, Number
		POPA
		ENDM

	GettingSoldierY		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].Y
		POPA
		ENDM
	SettingSoldierY		MACRO	Object, ID, Number
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].Y, Number
		POPA
		ENDM

	GettingSoldierState		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].State
		POPA
		ENDM
	SettingSoldierState		MACRO	Object, ID, Number
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].State, Number
		POPA
		ENDM
;
;
	;GettingSoldierHeight	MACRO	Object, ID, StoreTo
	;	PUSHA
	;		ObjectOffset 	ID
	;		CopyFrom 		StoreTo, Object[EBX].SHeight
	;	POPA
	;	ENDM
	;SettingSoldierHeight	MACRO	Object, ID, Number
	;	PUSHA
	;		ObjectOffset 	ID
	;		CopyFrom  		Object[EBX].SHeight, Number
	;	POPA
	;	ENDM
;
;
	CounterSoldierOffsetIndex	MACRO Arms, Level
		MOV EAX, Arms
		DEC EAX
		MOV EDX, 12
		MUL EDX
		MOV EDX, EAX
		MOV EAX, Level
		DEC EAX
		SHL EAX, 2
		ADD EAX, EDX
		ENDM

	CounterSoldierOffset	MACRO Object
		MOV EAX, Object[EBX].Arms
		DEC EAX
		MOV EDX, 12
		MUL EDX
		MOV EDX, EAX
		MOV EAX, Object[EBX].Level
		DEC EAX
		SHL EAX, 2
		ADD EAX, EDX
				; 0 	12	24
				; 0		0	0
				
				; 0 	12	24
				; 4		4	4

				; 0 	12	24
				; 8		8	8
		ENDM
	GettingSoldierHeight	MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			.IF( Object[EBX].League == 0)
				CopyFrom StoreTo, UserSoldier_Height[EAX]
			.ELSE
				CopyFrom StoreTo, CompSoldier_Height[EAX]
			.ENDIF
		POPA
		ENDM
	GettingSoldierWidth		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CounterSoldierOffset Object
			.IF( Object[EBX].League == 0)
				CopyFrom StoreTo, UserSoldier_Width[EAX]
			.ELSE
				CopyFrom StoreTo, CompSoldier_Width[EAX]
			.ENDIF
		POPA
		ENDM

	GettingSoldierHP		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].HP
		POPA
		ENDM
	SettingSoldierHP		MACRO	Object, ID, Blood
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].HP, Blood
		POPA
		ENDM
	SettingSoldierInitialHP		MACRO	Object, ID
		PUSHA
			ObjectOffset 	ID
			CounterSoldierOffset Object
			CopyFrom 		Object[EBX].HP, Soldier_HP[EAX]
		POPA
		ENDM

	GettingSoldierAttack	MACRO	Object, ID
		PUSHA
			ObjectOffset 	ID
			CounterSoldierOffset Object
			CopyFrom 		StoreTo, Soldier_Attack[EAX]
		POPA
		ENDM
	SettingSoldierAttack	MACRO	Object, ID
		PUSHA
			ObjectOffset 	ID
			CounterSoldierOffset Object
			CopyFrom 		Object[EBX].ATK, Soldier_Attack[EAX]
		POPA
		ENDM

	GettingSoldierArms		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].Arms
		POPA
		ENDM
	SettingSoldierArms		MACRO	Object, ID, Kinds
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].Arms, Kinds
		POPA
		ENDM
	GettingSoldierLeague		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].League
		POPA
		ENDM
	SettingSoldierLeague		MACRO	Object, ID, Kinds
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].League, Kinds
		POPA
		ENDM

	GettingSoldierAlive		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].Alive
		POPA
		ENDM
	SettingSoldierAlive		MACRO	Object, ID, SAlive
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].Alive, SAlive
		POPA
		ENDM


	GettingSoldierTime	MACRO	Arms, Level, StoreTo
		PUSHA
			CounterSoldierOffsetIndex Arms, Level
			CopyFrom 		StoreTo, Soldier_Buffer[EAX]
		POPA
		ENDM

.Code
	
	Init PROC
		PUSHA
			LoopTimes 0
			EACH:
				SettingSoldierX 	UserSoldiers, ECX, 0
				SettingSoldierAlive UserSoldiers, ECX, 0

				NextInc	8, EACH
		POPA
		RET
	Init ENDP

