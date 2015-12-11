.Data

;	Regester


	Soilder STRUCT
		HP			DWORD ?
		XY			COORD <>
		ATK			DWORD ?
		SPD			DWORD ?
		LV			DWORD ?
		KIND		DWORD ?
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

	RegisterObjects	EQU <CALL Register>

	GettingSolderLV		MACRO	Object, ID, StoreTo
		CopyFrom StoreTo, (Soilder PTR Object[ID*4]).LV
		ENDM

	SettingSolderLV		MACRO	Object, ID, Number
		CopyFrom (Soilder PTR Object[ID*4]).LV, Number
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
