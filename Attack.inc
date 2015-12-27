.Data

	UserAttackSoldier	DWORD	?
	CompAttackSoldier	DWORD	?
	
	UserAttackTarget	DWORD	?
	CompAttackTarget	DWORD	?

	UserATK	DWORD	?
	CompATK	DWORD	?

	UserHP	DWORD	?
	CompHP	DWORD	?


	UserAttack MACRO


		ENDM


	CompAttack MACRO
		PUSHAD
			GettingSoldierAttack	CompSoldiers, 	CompAttackSoldier,	CompATK
			GettingSoldierHP		UserSoldiers, 	CompAttackTarget,	UserHP
			
			SubBy UserHP,	CompATK
			SettingSoldierHP		UserSoldiers,	CompAttackTarget,	UserHP
			.IF( UserHP == 0)
				DestorySoldier UserSoldiers, CompAttackTarget
				SettingSoldierAttackTo	CompSoldiers,	CompAttackSoldier,	-1
				ResetAttack
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