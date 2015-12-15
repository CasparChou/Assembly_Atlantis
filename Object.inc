.Data

	RegisterObjects	EQU <CALL Register>
	DrawSoilders 	EQU <CALL DrawingSoilders>
	Initial 	EQU <CALL Init>

	BuildUserSoilderA EQU <BuildSoilder UserSoilders, 0, 1, 1>
	BuildUserSoilderB EQU <BuildSoilder UserSoilders, 0, 2, 1>
	BuildUserSoilderC EQU <BuildSoilder UserSoilders, 0, 3, 1>

	BuildCompSoilderA EQU <BuildSoilder CompSoilders, 1, 1, -1>
	BuildCompSoilderB EQU <BuildSoilder CompSoilders, 1, 2, -1>
	BuildCompSoilderC EQU <BuildSoilder CompSoilders, 1, 3, -1>


	Soilder STRUCT
		HP			DWORD 0
		X			DWORD 0
		Y 			DWORD 0
		ATK			DWORD 0

		SPD			DWORD 0
		LV			DWORD 0
		Arms		DWORD 0
		League		DWORD 0
		State		DWORD 0

		Alive		DWORD 0
	Soilder ENDS

	UserSoilders	Soilder	8 DUP(<>)
	CompSoilders	Soilder	8 DUP(<>)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Getter / Setter 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	GettingSoilderLV		MACRO	Object, ID, StoreTo
		CopyFrom StoreTo, Object[ID*4].LV
		ENDM
	SettingSoilderLV		MACRO	Object, ID, Number
		CopyFrom Object[ID*4].LV, Number
		ENDM


	GettingSoilderX		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].X
		POPA
		ENDM
	SettingSoilderX		MACRO	Object, ID, Number
		PUSHA
			CopyFrom Object[ID*4].X, Number
		POPA
		ENDM

;	GettingSoilderY		MACRO	Object, ID, StoreTo
;		PUSHA
;		CopyFrom StoreTo, Object[ID*4].PosY
;		POPA
;		ENDM
;	SettingSoilderY		MACRO	Object, ID, Number
;		PUSHA
;		CopyFrom  Object[ID*4].PosY, Number
;		POPA
;		ENDM

	GettingSoilderHP		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].HP
		POPA
		ENDM
	SettingSoilderHP		MACRO	Object, ID, Blood
		PUSHA
		CopyFrom  Object[ID*4].HP, Blood
		POPA
		ENDM

	GettingSoilderATK		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].ATK
		POPA
		ENDM
	SettingSoilderATK		MACRO	Object, ID, Attack
		PUSHA
		CopyFrom  Object[ID*4].ATK, Attack
		POPA
		ENDM

	GettingSoilderSPD		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].SPD
		POPA
		ENDM
	SettingSoilderSPD		MACRO	Object, ID, Speeds
		PUSHA
		CopyFrom  Object[ID*4].SPD, Speeds
		POPA
		ENDM

	GettingSoilderArms		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].Arms
		POPA
		ENDM
	SettingSoilderArms		MACRO	Object, ID, Kinds
		PUSHA
		CopyFrom  Object[ID*4].Arms, Kinds
		POPA
		ENDM
	GettingSoilderLeague		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].League
		POPA
		ENDM
	SettingSoilderLeague		MACRO	Object, ID, Kinds
		PUSHA
		CopyFrom  Object[ID*4].League, Kinds
		POPA
		ENDM

	GettingSoilderState		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].State
		POPA
		ENDM
	SettingSoilderState		MACRO	Object, ID, States
		PUSHA
			CopyFrom  Object[ID*4].State, States
			DrawMonster  	50, Beats5x
		POPA
		ENDM

	GettingSoilderAlive		MACRO	Object, ID, StoreTo
		PUSHA
			CopyFrom StoreTo, Object[ID*4].Alive
		POPA
		ENDM
	SettingSoilderAlive		MACRO	Object, ID, SAlive
		PUSHA
			CopyFrom  Object[ID*4].Alive, SAlive
		POPA
		ENDM

.Code
	
	Init PROC
		PUSHA
			LoopTimes 0
			EACH:
				SettingSoilderX 	UserSoilders, ECX, 0
				SettingSoilderAlive UserSoilders, ECX, 0
				NextInc	8, EACH
		POPA
		RET
	Init ENDP

