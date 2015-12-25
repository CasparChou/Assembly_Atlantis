;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	   Collision 	    ;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.DATA
Collision_User_X 	DWORD 	?
Collision_Comp_X	DWORD 	?

Collision	MACRO	USoldier_ID, CSoldiers_ID, Call_Back_Val
	PUSHA
		;	Get User Soldier Current X Coord in ID
		GettingSoldierX		UserSoldiers,			USoldier_ID,			GetterHandler
		CopyFrom			Collision_User_X,		GetterHandler

		;	Get Computer Soldier Current X Coord in ID
		GettingSoldierX		CompSoldiers,			CSoldiers_ID,			GetterHandler
		CopyFrom 			Collision_Comp_X,		GetterHandler

		MOV		EAX,	Collision_User_X
		MOV 	EBX,	EAX
		ADD		EBX,	6
		MOV		ECX,	Collision_Comp_X

		.IF	( EAX != 0 && ECX !=0 )
			.IF	( EAX <=  ECX && EBX >= ECX )
				AnyKeyToContinue

				ObjectOffset 	USoldier_ID
				CopyFrom 		UserSoldiers[EBX].State,	CSoldiers_ID
				
				ObjectOffset 	CSoldiers_ID
				CopyFrom 		CompSoldiers[EBX].State,	USoldier_ID

				SettingSoldierState 	UserSoldiers,	USoldier_ID,	CSoldiers_ID
				SettingSoldierState 	CompSoldiers,	CSoldiers_ID,	USoldier_ID
				CopyFrom	Call_Back_Val,	1
			.ElSE
				CopyFrom	Call_Back_Val,	0
			.ENDIF

			ObjectOffset 	USoldier_ID
			CopyFrom 		EAX, UserSoldiers[EBX].State
			WriteD			USoldier_ID
			Write			':'
			WriteD			EAX
			Write			' '
			WriteD			CSoldiers_ID
		.ENDIF
	POPA
	ENDM	
