;	Version 3
.Data

	UserAttackSoldier	DWORD	?
	CompAttackSoldier	DWORD	?
	
	UserAttackTarget	DWORD	?
	CompAttackTarget	DWORD	?

	UserATK	DWORD	?
	CompATK	DWORD	?

	UserHP	DWORD	?
	CompHP	DWORD	?

	UserCastleHP	DWORD	5000
	CompCastleHP	DWORD	5000

	AttackToUserCastle MACRO

		GettingSoldierAttack	CompSoldiers, 	CompAttackSoldier,	CompATK
		
		MOV EAX, CompATK
		.IF( UserCastleHP > EAX )
			SubBy UserCastleHP,	CompATK
		.ELSE
			CompWin
		.ENDIF

		ENDM
	AttackToCompCastle MACRO
		GettingSoldierAttack	UserSoldiers, 	UserAttackSoldier,	UserATK
		
		MOV EAX, UserATK
		.IF( CompCastleHP > EAX )
			SubBy CompCastleHP,	UserATK
		.ELSE
			UserWin
		.ENDIF

		ENDM


	UserAttack MACRO
		PUSHAD
		.IF( UserAttackTarget < 8 && UserAttackTarget >= 0 )

			GettingSoldierAttack	UserSoldiers, 	UserAttackSoldier,	UserATK
			GettingSoldierHP		CompSoldiers, 	UserAttackTarget,	CompHP
			
			MOV EAX,	UserATK
			.IF( CompHP > EAX )
				SubBy CompHP,	UserATK
				SettingSoldierHP		CompSoldiers,	UserAttackTarget,	CompHP
			.ELSE
				GettingSoldierMoney 	CompSoldiers,	UserAttackTarget, GetterHandler
				MOV 	EDX, 	0
				MOV 	EAX,	GetterHandler
				MOV 	ECX,	2
				DIV		ECX
				AddBy 	UserMoney, EAX
				DestorySoldier CompSoldiers, UserAttackTarget
				SettingSoldierAttackTo	UserSoldiers,	UserAttackSoldier,	-1
				ResetAttack
				CollisionCheck	 	UserAttackSoldier
			.ENDIF
		.ELSEIF ( UserAttackTarget == 8 )
			AttackToCompCastle
		.ENDIF	

		POPAD
		ENDM

	CompAttack MACRO
		PUSHAD

		.IF( CompAttackTarget < 8 && CompAttackTarget >= 0 )

			GettingSoldierAttack	CompSoldiers, 	CompAttackSoldier,	CompATK
			GettingSoldierHP		UserSoldiers, 	CompAttackTarget,	UserHP
			
			MOV EAX, CompATK
			.IF( UserHP > EAX )
				SubBy UserHP,	CompATK
				SettingSoldierHP		UserSoldiers,	CompAttackTarget,	UserHP
			.ELSE
				DestorySoldier UserSoldiers, CompAttackTarget
				SettingSoldierAttackTo	CompSoldiers,	CompAttackSoldier,	-1
				ResetAttack
			.ENDIF

		.ELSEIF( CompAttackTarget == 8 )
			AttackToUserCastle
		.ENDIF	

		POPAD
		ENDM

	ResetAttack 	MACRO

		MOV UserAttackTimer		,0
		MOV CompAttackTimer		,0
		MOV UserAttackSoldier	,0
		MOV CompAttackSoldier	,0
		MOV UserAttackTarget	,0
		MOV CompAttackTarget	,0
		MOV UserATK	,0
		MOV CompATK	,0
		MOV UserHP	,0
		MOV CompHP	,0
		ENDM