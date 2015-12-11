.Data

	RegisterObjects	EQU <CALL Register>
	DrawSoilders 	EQU <CALL DrawingSoilders>


	Soilder STRUCT
		HP			DWORD ?
		X			DWORD ?
		Y			DWORD ?
		ATK			DWORD ?
		SPD			DWORD ?
		LV			DWORD ?
		KIND		DWORD ?
		State		DWORD ?
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
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).LV
		ENDM
	SettingSoilderLV		MACRO	Object, ID, Number
		CopyFrom (Soilder PTR Object[ID*4]).LV, Number
		ENDM


	GettingSoilderX		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).X
		POPA
		ENDM
	SettingSoilderX		MACRO	Object, ID, Number
		PUSHA
		CopyFrom (Soilder PTR Object[ID*4]).X, Number
		POPA
		ENDM

	GettingSoilderY		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).Y
		POPA
		ENDM
	SettingSoilderY		MACRO	Object, ID, Number
		PUSHA
		CopyFrom  (Soilder PTR Object[ID*4]).Y, Number
		POPA
		ENDM

	GettingSoilderHP		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).HP
		POPA
		ENDM
	SettingSoilderHP		MACRO	Object, ID, Blood
		PUSHA
		CopyFrom  (Soilder PTR Object[ID*4]).HP, Blood
		POPA
		ENDM

	GettingSoilderATK		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).ATK
		POPA
		ENDM
	SettingSoilderATK		MACRO	Object, ID, Attack
		PUSHA
		CopyFrom  (Soilder PTR Object[ID*4]).ATK, Attack
		POPA
		ENDM

	GettingSoilderSPD		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).SPD
		POPA
		ENDM
	SettingSoilderSPD		MACRO	Object, ID, Speeds
		PUSHA
		CopyFrom  (Soilder PTR Object[ID*4]).SPD, Speeds
		POPA
		ENDM

	GettingSoilderKIND		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).KIND
		POPA
		ENDM
	SettingSoilderKIND		MACRO	Object, ID, Kinds
		PUSHA
		CopyFrom  (Soilder PTR Object[ID*4]).KIND, Kinds
		POPA
		ENDM

	GettingSoilderState		MACRO	Object, ID, StoreTo
		PUSHA
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).State
		POPA
		ENDM
	SettingSoilderState		MACRO	Object, ID, States
		PUSHA
		CopyFrom  (Soilder PTR Object[ID*4]).State, States
		POPA
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


	DrawingSoilders 	PROC
		PUSHA
			LoopTimes 0
			DSs:

				
				NextInc	16, DSs
		POPA
		RET
	DrawingSoilders		ENDP