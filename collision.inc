;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	   Collision 	    ;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.DATA
Collision_A_X 	DWORD 	?
Collision_B_X	DWORD 	?
Collision_Check_ID	DWORD	?
CollisionCheck MACRO 	Current
	PUSHA
		ObjectOffset Current
		.IF( UserSoldiers[EBX].Alive == 1)
			LoopTimes 	0
			CollisionChecking:
				CopyFrom Collision_Check_ID, ECX
				ObjectOffset Collision_Check_ID
				.IF( CompSoldiers[EBX].Alive == 1 )					
					Collision	Current,	Collision_Check_ID,	GetterHandler
					.IF	GetterHandler == 1
						;MOV ECX, 0
					.ENDIF
				.ENDIF
			NEXTINC 7, 	CollisionChecking
		.ENDIF
	POPA
	ENDM
UserWaitStackCheck MACRO 	Current
	PUSHA
		SettingSoldierWaitFor 	UserSoldiers,	Current,	-1
		LoopTimes 	0
		UserWattingChecking:
			ObjectOffset ECX
			.IF (UserSoldiers[EBX].Alive == 1)
				.IF Current != ECX
					WaitStack	0, Current,	ECX,	GetterHandler
					.IF	GetterHandler == 1
						;MOV ECX, 0
					.ENDIF
				.ENDIF
			.ENDIF
			NEXTINC 7,	UserWattingChecking
	POPA
	ENDM
CompWaitStackCheck MACRO 	Current
	PUSHA
		SettingSoldierWaitFor 	CompSoldiers,	Current,	-1
		LoopTimes 	0
		CompWattingChecking:
			ObjectOffset ECX
			.IF (CompSoldiers[EBX].Alive == 1)
				.IF Current != ECX
					WaitStack	1, Current,	ECX,	GetterHandler
					.IF	GetterHandler == 1
						;MOV ECX, 0
					.ENDIF
				.ENDIF
			.ENDIF
			NEXTINC 7,	CompWattingChecking
	POPA
	ENDM

Collision	MACRO	UserSoldier, CompSoldier, Call_Back_Val
	PUSHA
		;	Get User Soldier Current X Coord in ID
		GettingSoldierX		UserSoldiers,			UserSoldier,			Collision_A_X
		;	Get Computer Soldier Current X Coord in ID
		GettingSoldierX		CompSoldiers,			CompSoldier,			Collision_B_X

		MOV		EAX,	Collision_A_X
		MOV 	EBX,	Collision_B_X
		
		MOV 	EDX,	EBX
		SUB 	EDX,	EAX

		GettingSoldierWidth UserSoldiers, UserSoldier, GetterHandler
		MOV ECX, GetterHandler
		.IF	( EAX != 0 && EBX !=0 )
			.IF	( EDX < ECX )


				;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
				;;;
				;;; 	THIS IS A DEBUG CODE FOR Collision
				;;; 	IF ANY PROBLEM OCCURED
				;;;	 	REMOVE " COMMENT " TO DEBUG
				;;;
				;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

				;DEBUG SECTION START
				COMMENT #
				DefaultColor
				WriteSAtCenter	60,	10,	Attacking
				Translate 20,10
				Write '['
				WriteI UserSoldier
				Write '-'
				WriteI CompSoldier
				Write ']'
				AnyKeyToContinue
				SettingColor Black
				WriteSAtCenter	60,	10,	Attacking
				Translate 20,10
				Write '['
				WriteI UserSoldier
				Write '-'
				WriteI CompSoldier
				Write ']'
				DefaultColor
				TranslatePrevious

				#
				;DEBUG SECTION CLOSE

				SettingSoldierAttackTo 	UserSoldiers,	UserSoldier,	CompSoldier
				SettingSoldierAttackTo 	CompSoldiers,	CompSoldier,	UserSoldier
				CopyFrom	Call_Back_Val,	1
			.ElSE
				CopyFrom	Call_Back_Val,	0
			.ENDIF
		.ENDIF
	POPA
	ENDM	

WaitStack	MACRO	League,	Soldier, FrontSoldier,	Call_Back_Val
	PUSHA

		MOV EDX,	League
		.IF( EDX == 0)
			GettingSoldierX		UserSoldiers,			Soldier,			Collision_A_X
			GettingSoldierX		UserSoldiers,			FrontSoldier,		Collision_B_X
		.ElSE
			GettingSoldierX		CompSoldiers,			Soldier,			Collision_A_X
			GettingSoldierX		CompSoldiers,			FrontSoldier,		Collision_B_X
		.ENDIF

		MOV		EAX,	Collision_A_X
		MOV		EBX,	Collision_B_X
		.IF	( EBX > EAX && Soldier != FrontSoldier && EDX == 0)
			CopyFrom 	SetterBuffer,	EBX
			SUB 		SetterBuffer, 	EAX
			GettingSoldierWidth UserSoldiers, Soldier, GetterHandler
			MOV ECX, GetterHandler
			.IF	( SetterBuffer < ECX )
				SettingSoldierWaitFor 	UserSoldiers,	Soldier,	FrontSoldier
				CopyFrom	Call_Back_Val,	1
			.ElSE
				CopyFrom	Call_Back_Val,	0
			.ENDIF
		.ELSEIF ( EBX < EAX && Soldier != FrontSoldier && EDX == 1 )
			CopyFrom 	SetterBuffer,	EAX
			SUB 		SetterBuffer, 	EBX

			GettingSoldierWidth CompSoldiers, Soldier, GetterHandler
			MOV ECX, GetterHandler
			.IF	( SetterBuffer < ECX )
				SettingSoldierWaitFor 	CompSoldiers,	Soldier,	FrontSoldier
				CopyFrom	Call_Back_Val,	1
			.ElSE
				CopyFrom	Call_Back_Val,	0
			.ENDIF
		.ENDIF

			
	POPA
	ENDM	