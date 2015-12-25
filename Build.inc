;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Build New Soldier 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	TriggleBuild MACRO 	League,	Arms
		PUSHA
			MOV EAX, League
			MOV EBX, Arms
			.IF( EAX == 0)
				.IF( EBX == 1)
					BuildUserSoldierA
				.ELSEIF( EBX == 2)
					BuildUserSoldierB
				.ELSEIF( EBX == 3)
					BuildUserSoldierC
				.ENDIF
			.ELSE
				.IF( EBX == 1)
					BuildCompSoldierA
				.ELSEIF( EBX == 2)
					BuildCompSoldierB
				.ELSEIF( EBX == 3)
					BuildCompSoldierC
				.ENDIF
			.ENDIF
		POPA
		ENDM
	BuildSoldierBufferTime 	MACRO	League,		Arms
		PUSHA
			.IF( Timer_UserBuild == 0)
				CopyFrom Timer_UserBuild, 1
			.ENDIF
			MOV EAX,	League
			.IF( EAX == 0 )
				PUSHArray 	User_BuildQueue,	Arms
			.ELSE
				PUSHArray	Comp_BuildQueue,	Arms
			.ENDIF
		POPA
		ENDM
	BuildSoldier MACRO Object, League, Arms, Speed
		PUSHA
			INVOKE FindUsableSoldier, League, Arms
		POPA
		ENDM
.Code	
	FindUsableSoldier PROC, League:DWORD, Arms:DWORD
		PUSHA
				;WriteD League
				;AnyKeyToContinue

			.IF (League == 0)
				LoopTimes 0
				FindUser:
					ObjectOffset ECX
					.IF (UserSoldiers[EBX].Alive == 0)
						SettingSoldierAlive		UserSoldiers, ECX, 1
						SettingSoldierArms 		UserSoldiers, ECX, Arms
						SettingSoldierX	 		UserSoldiers, ECX, 20
						SettingSoldierLeague	UserSoldiers, ECX, 0
						SettingSoldierLevel		UserSoldiers, ECX, UserCurrLevel
						SettingSoldierState		UserSoldiers, ECX, -1
						SettingSoldierInitialHP	UserSoldiers, ECX
						SettingSoldierAttack	UserSoldiers, ECX
						POPA
						RET
					.ENDIF
					NextInc 8, FindUser
			.ELSEIF (League == 1)
				LoopTimes 0
				FindComp:
					ObjectOffset ECX
					.IF (CompSoldiers[EBX].Alive == 0)
						SettingSoldierAlive		CompSoldiers, ECX, 1
						SettingSoldierArms 		CompSoldiers, ECX, Arms
						SettingSoldierX	 		CompSoldiers, ECX, 90
						SettingSoldierLeague	CompSoldiers, ECX, 1
						SettingSoldierLevel		CompSoldiers, ECX, CompCurrLevel
						SettingSoldierState		CompSoldiers, ECX, -1
						SettingSoldierInitialHP	CompSoldiers, ECX
						SettingSoldierAttack	CompSoldiers, ECX
						POPA
						RET
					.ENDIF
					NextInc 8,	FindComp
			.ENDIF
		POPA
		RET
	FindUsableSoldier ENDP

