;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	   Collision 	    ;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.DATA
Collision_A_X 	DWORD 	?
Collision_B_X	DWORD 	?

CollisionCheck MACRO 	Current
	PUSHA
		LoopTimes 	0
		CollisionChecking:
			Collision	Current,	ECX,	GetterHandler
			.IF	GetterHandler == 1
				;MOV ECX, 0
			.ENDIF
			NEXTINC 7, 	CollisionChecking
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

		.IF	( EAX != 0 && EBX !=0 )
			.IF	( EDX < 6 )
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

;				DefaultColor
;				Translate 0,0
;				
;				Write 		' '
;				WriteD 		Soldier
;				Write 		':'
;				WriteD 		Collision_A_X
;				Write 		':'
;				WriteD 		EAX
;				NL
;				Write 		' '
;				WriteD 		FrontSoldier
;				Write 		':'
;				WriteD 		Collision_B_X
;				Write 		':'
;				WriteD 		EBX
;				NL
		.IF	( EBX > EAX && Soldier != FrontSoldier && EDX == 0)
			CopyFrom 	SetterBuffer,	EBX
			SUB 		SetterBuffer, 	EAX
			.IF	( SetterBuffer < 6 )
				SettingSoldierWaitFor 	UserSoldiers,	Soldier,	FrontSoldier
				CopyFrom	Call_Back_Val,	1
			.ElSE
				CopyFrom	Call_Back_Val,	0
			.ENDIF
		.ELSEIF ( EBX < EAX && Soldier != FrontSoldier && EDX == 1 )
			CopyFrom 	SetterBuffer,	EAX
			SUB 		SetterBuffer, 	EBX
			.IF	( SetterBuffer < 6 )
				SettingSoldierWaitFor 	CompSoldiers,	Soldier,	FrontSoldier
				CopyFrom	Call_Back_Val,	1
			.ElSE
				CopyFrom	Call_Back_Val,	0
			.ENDIF
		.ENDIF

			
	POPA
	ENDM	