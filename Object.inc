.Data

	
	RegisterObjects	EQU <CALL Register>
	DrawSoldiers 	EQU <CALL DrawingSoldiers>
	Initial 		EQU <CALL Init>
	

	BuildUserSoldierA EQU <BuildSoldier UserSoldiers, 0, 1, 1>
	BuildUserSoldierB EQU <BuildSoldier UserSoldiers, 0, 2, 1>
	BuildUserSoldierC EQU <BuildSoldier UserSoldiers, 0, 3, 1>

	BuildCompSoldierA EQU <BuildSoldier CompSoldiers, 1, 1, -1>
	BuildCompSoldierB EQU <BuildSoldier CompSoldiers, 1, 2, -1>
	BuildCompSoldierC EQU <BuildSoldier CompSoldiers, 1, 3, -1>


	Soldier STRUCT
		HP			DWORD 0
		X			DWORD 0
		Y 			DWORD 0
		SWidth		DWORD 0
		SHeight		DWORD 0
		ATK			DWORD 0

		SPD			DWORD 0
		LV			DWORD 0
		Arms		DWORD 0
		League		DWORD 0
		State		DWORD 0

		Alive		DWORD 0
	Soldier ENDS


	UserSoldiers	Soldier	8 DUP(<0,0,0,0,0,0,0,0,0,0>)
	CompSoldiers	Soldier	8 DUP(<0,0,0,0,0,0,0,0,0,0>)

	
	SoilderHeight	DWORD	3, 4, 4,
							3, 3, 3,
							3, 4, 5


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
			CopyFrom 		StoreTo, Object[EBX].LV
		POPA
		ENDM
	SettingSoldierLevel		MACRO	Object, ID, Number
		PUSHA
			ObjectOffset 	ID
			CopyFrom		Object[EBX].LV, Number
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


	GettingSoldierHeight	MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].SHeight
		POPA
		ENDM
	SettingSoldierHeight	MACRO	Object, ID, Number
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].SHeight, Number
		POPA
		ENDM


	GettingSoldierWidth		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].SWidth
		POPA
		ENDM
	SettingSoldierWidth		MACRO	Object, ID, Number
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].SWidth, Number
		POPA
		ENDM

	;SettingSoliderSize		MACRO	Object,	ObjectID, League, Arms, Level
	;	PUSHA
	;		SettingSoliderWidth		UserSoldiers, ObjectID, EBX
	;		SettingSoliderHeight	UserSoldiers, ObjectID, SoilderHeight[]		
	;	POPA
	;	ENDM


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

	GettingSoldierATK		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].ATK
		POPA
		ENDM
	SettingSoldierATK		MACRO	Object, ID, Attack
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].ATK, Attack
		POPA
		ENDM

	GettingSoldierSPD		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom 		StoreTo, Object[EBX].SPD
		POPA
		ENDM
	SettingSoldierSPD		MACRO	Object, ID, Speeds
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].SPD, Speeds
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

	GettingSoldierState		MACRO	Object, ID, StoreTo
		PUSHA
			ObjectOffset 	ID
			CopyFrom		StoreTo, Object[EBX].State
		POPA
		ENDM
	SettingSoldierState		MACRO	Object, ID, States
		PUSHA
			ObjectOffset 	ID
			CopyFrom  		Object[EBX].State, States
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

