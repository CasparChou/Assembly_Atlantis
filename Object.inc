.Data

	RegisterObjects	EQU <CALL Register>
	DrawSoilders 	EQU <CALL DrawingSoilders>
	Initial 	EQU <CALL Init>


	Soilder STRUCT
		HP			DWORD 0
		X			DWORD 0
		Y 			DWORD 0
		ATK			DWORD 0

		SPD			DWORD 0
		LV			DWORD 0
		KIND		DWORD 0
		State		DWORD 0

		Alive		DWORD 0
	Soilder ENDS


	
	Soilder1 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder2 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder3 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder4 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder5 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder6 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder7 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder8 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder9 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder10 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder11 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder12 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder13 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder14 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder15 Soilder <0,0,0,0,0,0,0,0,0>
	Soilder16 Soilder <0,0,0,0,0,0,0,0,0>

	UserSoilders	Soilder	8 DUP(<>)
	CompSoilders	Soilder	8 DUP(<>)

	;Registing 	MACRO	Object, ObjectList, ID
	;	PUSH ESI
	;		LEA		ESI,	Object
	;		MOV		ObjectList[ID*4],	ESI
	;	POP ESI
	;	ENDM


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

	GettingSoilderKIND		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object[ID*4].KIND
		POPA
		ENDM
	SettingSoilderKIND		MACRO	Object, ID, Kinds
		PUSHA
		CopyFrom  Object[ID*4].KIND, Kinds
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


	SoilderOn	MACRO Object, ID

		.IF Object[ID*4].Alive == 1

			DrawSoilder Object[ID*4].X, Beats2x
			WriteD Object[ID*4].SPD
		.ENDIF


		ENDM

	BuildUserSoilderA EQU <BuildSoilder UserSoilders, 1, 1>
	BuildUserSoilderB EQU <BuildSoilder UserSoilders, 2, 1>
	BuildUserSoilderC EQU <BuildSoilder UserSoilders, 3, 1>

	BuildSoilder MACRO Object, Level, Speed
		PUSHA
			CALL FindUsableUserSoilder
			.IF ECX < 9
				SettingSoilderLV 	Object, ECX, Level
				SettingSoilderX	 	Object, ECX, 20
				SettingSoilderSPD	Object, ECX, Speed
			.ENDIF
		POPA
		ENDM

	MoveOnSoilders MACRO
		CALL MoveOnUserSoilders
		;CALL MoveOnCompSoilders
		ENDM
.Code

	FindUsableUserSoilder PROC
		LoopTimes 0
		BS:
			.IF UserSoilders[ECX*4].Alive == 0
				CopyFrom UserSoilders[ECX*4].Alive, 1
				RET
			.ENDIF
			NextInc	9, BS
		RET
	FindUsableUserSoilder ENDP
	
	MoveOnUserSoilders PROC
		LoopTimes 0
		MS:
			.IF UserSoilders[ECX*4].Alive == 1
				MOVE UserSoilders, ECX, UserSoilders[ECX*4].SPD, 0
			.ENDIF
			NextInc	16, MS
		RET
	MoveOnUserSoilders ENDP
	
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


	DrawingSoilders 	PROC
		PUSHA
			LoopTimes 0
			DSs:
				SoilderOn	UserSoilders, ECX
				NextInc	8, DSs
		POPA
		RET
	DrawingSoilders		ENDP