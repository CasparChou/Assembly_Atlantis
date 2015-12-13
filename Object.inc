.Data

	RegisterObjects	EQU <CALL Register>
	DrawSoilders 	EQU <CALL DrawingSoilders>
	Initial 	EQU <CALL Init>


	Soilder STRUCT
		HP			DWORD 0
		X			DWORD 0
		PosY		DWORD 0
		ATK			DWORD 0
		SPD			DWORD 0
		LV			DWORD 0
		KIND		DWORD 0
		State		DWORD 0
		Alive		DWORD 0
	Soilder ENDS
	
	Soilder1 Soilder <>
	Soilder2 Soilder <>
	Soilder3 Soilder <>
	Soilder4 Soilder <>
	Soilder5 Soilder <>
	Soilder6 Soilder <>
	Soilder7 Soilder <>
	Soilder8 Soilder <>
	Soilder9 Soilder <>
	Soilder10 Soilder <>
	Soilder11 Soilder <>
	Soilder12 Soilder <>
	Soilder13 Soilder <>
	Soilder14 Soilder <>
	Soilder15 Soilder <>
	Soilder16 Soilder <>

	UserSoilders	DWORD	8 DUP(?)
	CompSoilders	DWORD	8 DUP(?)

	Registing 	MACRO	Object, ObjectList, ID
		PUSH ESI
			LEA		ESI,	Object
			MOV		ObjectList[ID*4],	ESI
		POP ESI
		ENDM


	GettingSoilderLV		MACRO	Object, ID, StoreTo
		CopyFrom StoreTo, Object.Soilder[ID*4].LV
		ENDM
	SettingSoilderLV		MACRO	Object, ID, Number
		CopyFrom Object.Soilder[ID*4].LV, Number
		ENDM


	GettingSoilderX		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object.Soilder[ID*4].X
		POPA
		ENDM
	SettingSoilderX		MACRO	Object, ID, Number
		PUSHA
		CopyFrom Object.Soilder[ID*4].X, Number
		POPA
		ENDM

;	GettingSoilderY		MACRO	Object, ID, StoreTo
;		PUSHA
;		CopyFrom StoreTo, Object.Soilder[ID*4].PosY
;		POPA
;		ENDM
;	SettingSoilderY		MACRO	Object, ID, Number
;		PUSHA
;		CopyFrom  Object.Soilder[ID*4].PosY, Number
;		POPA
;		ENDM

	GettingSoilderHP		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object.Soilder[ID*4].HP
		POPA
		ENDM
	SettingSoilderHP		MACRO	Object, ID, Blood
		PUSHA
		CopyFrom  Object.Soilder[ID*4].HP, Blood
		POPA
		ENDM

	GettingSoilderATK		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object.Soilder[ID*4].ATK
		POPA
		ENDM
	SettingSoilderATK		MACRO	Object, ID, Attack
		PUSHA
		CopyFrom  Object.Soilder[ID*4].ATK, Attack
		POPA
		ENDM

	GettingSoilderSPD		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object.Soilder[ID*4].SPD
		POPA
		ENDM
	SettingSoilderSPD		MACRO	Object, ID, Speeds
		PUSHA
		CopyFrom  Object.Soilder[ID*4].SPD, Speeds
		POPA
		ENDM

	GettingSoilderKIND		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object.Soilder[ID*4].KIND
		POPA
		ENDM
	SettingSoilderKIND		MACRO	Object, ID, Kinds
		PUSHA
		CopyFrom  Object.Soilder[ID*4].KIND, Kinds
		POPA
		ENDM

	GettingSoilderState		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object.Soilder[ID*4].State
		POPA
		ENDM
	SettingSoilderState		MACRO	Object, ID, States
		PUSHA
		CopyFrom  Object.Soilder[ID*4].State, States
		DrawMonster  	50, Beats5x
		POPA
		ENDM

	GettingSoilderAlive		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, Object.Soilder[ID*4].Alive
		POPA
		ENDM
	SettingSoilderAlive		MACRO	Object, ID, SAlive
		PUSHA
		CopyFrom  Object.Soilder[ID*4].Alive, SAlive
		POPA
		ENDM

	SoilderOn	MACRO Object, ID

		.IF Object.Soilder[ID*4].Alive == 1

			DrawSoilder 20, Beats2x

		.ENDIF


		ENDM

	BuildUserSoilderA MACRO


		INVOKE BuildSoilder, UserSoilders, 1

		ENDM

.Code

	

	
	Register 	PROC
		Registing	Soilder1, UserSoilders, 1
		Registing	Soilder2, UserSoilders, 2
		Registing	Soilder3, UserSoilders, 3
		Registing	Soilder4, UserSoilders, 4
		Registing	Soilder5, UserSoilders, 5
		Registing	Soilder6, UserSoilders, 6
		Registing	Soilder7, UserSoilders, 7
		Registing	Soilder8, UserSoilders, 8
		Registing	Soilder9,	CompSoilders, 1
		Registing	Soilder10,	CompSoilders, 2
		Registing	Soilder11,	CompSoilders, 3
		Registing	Soilder12, 	CompSoilders, 4
		Registing	Soilder13, 	CompSoilders, 5
		Registing	Soilder14, 	CompSoilders, 6
		Registing	Soilder15, 	CompSoilders, 7
		Registing	Soilder16, 	CompSoilders, 8

		RET
	Register 	ENDP

	Init PROC
		PUSHA
			LoopTimes 0
			EACH:
				SettingSoilderX UserSoilders, ECX, 0
				NextInc	16, EACH
		POPA
		RET
	Init ENDP


	DrawingSoilders 	PROC
		PUSHA
			LoopTimes 0
			DSs:
				;SettingSoilderX UserSoilders, ECX, 3
				;SettingSoilderY UserSoilders, ECX, ECX
				;GettingSoilderY UserSoilders, ECX, GetterHandler
				;WriteD GetterHandler
				;NL
				SoilderOn	UserSoilders, ECX
				
				NextInc	8, DSs
		POPA
		RET
	DrawingSoilders		ENDP

	BuildSoilder 	PROC,  Object:DWORD, LEVEL:DWORD
		PUSHA
			LoopTimes 0
			DSs:
				.IF Object.Soilder[ECX*4].Alive == 1

					
				.ENDIF
				;SettingSoilderX UserSoilders, ECX, 3
				;SettingSoilderY UserSoilders, ECX, ECX
				;GettingSoilderY UserSoilders, ECX, GetterHandler
				;WriteD GetterHandler
				;NL
				;SoilderOn	UserSoilders, ECX
				
				NextInc	8, DSs
		POPA
		RET
	BuildSoilder 	ENDP
