.Data

	LevelUpCheck MACRO
		.IF( UserLevelUpFlag == 1)
			INC UserCurrLevel
			CopyFrom UserLevelUpFlag, 0
		.ENDIF
		.IF( CompLevelUpFlag == 1)
			INC CompCurrLevel
			CopyFrom CompLevelUpFlag, 0
		.ENDIF

		ENDM


	KeyHandler MACRO
		PUSHA
			MOV EAX, 0
			Call ReadKey
			.IF( AL == 'Q' || AL == 'q' )
				;BuildUserSoldierA
				BuildSoldierBufferTime 	0,	1
			.ELSEIF( AL == 'W' || AL == 'w')
				;BuildUserSoldierB
				BuildSoldierBufferTime 	0,	2
			.ELSEIF( AL == 'E' || AL == 'e')
				;BuildUserSoldierC
				BuildSoldierBufferTime 	0,	3


			.ELSEIF( AL == 'I' || AL == 'i')
				BuildCompSoldierA
				;BuildSoldierBufferTime 	1, 1
			.ELSEIF( AL == 'O' || AL == 'o')
				BuildCompSoldierB
				;BuildSoldierBufferTime 	1, 2
			.ELSEIF( AL == 'P' || AL == 'p')
				BuildCompSoldierC
				;BuildSoldierBufferTime 	1, 3


			.ELSEIF( AL == 'Z' || AL == 'z')
				.IF( UserCurrLevel < 3)
					CopyFrom UserLevelUpFlag, 1
				.ENDIF
			.ELSEIF( AL == 'X' || AL == 'x')
				.IF( CompCurrLevel < 3)
					CopyFrom CompLevelUpFlag, 1
				.ENDIF
			.ENDIF
		POPA
		ENDM


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;		Dialog 	 		;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.Data


	Dialog_Example_1	DB "Greetings , warrior ! ",0
	Dialog_Example_2	DB "Thank you for accepting this task to protect Atlantis.",0
	Dialog_Example_3	DB "Now,",0
	Dialog_Example_4	DB "We are attacked by those who long for treasure of Atlantis.",0
	Dialog_Example_5	DB "Please fight with us side by side and bring the victory.",0

	Introduce MACRO
		DrawCastle	 	0, 0
		DrawCastle		1, 103

		Dialog 	Dialog_Example_1
		Dialog 	Dialog_Example_2
		Dialog 	Dialog_Example_3
		Dialog 	Dialog_Example_4
		Dialog 	Dialog_Example_5


		ENDM
	Dialog 	MACRO 	String
		PUSHAD
			WriteSAtCenter	60,	23,	String
			AnyKeyToContinue
			SettingColor	Black
			WriteSAtCenter	60,	23,	String
			DefaultColor
		POPAD
		ENDM

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;		Moving 	 		;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	MOVE MACRO Object, ID, AddX, AddY
		ObjectOffset ID
		.IF Object[EBX].League == 0
			INC Object[EBX].X
		.ELSE
			DEC Object[EBX].X
		.ENDIF
		AddBy Object[EBX].Y, AddY
		ENDM
	MoveOnSoldiers EQU	<CALL MoveingSoldiers>
	CollisionCurrID	DWORD	?
	WaitCheckCurrID	DWORD	?
.Code
	MoveingSoldiers PROC
		LoopTimes 0
		MUS:
			ObjectOffset ECX
			.IF UserSoldiers[EBX].Alive == 1
				.IF( UserSoldiers[EBX].AttackTo == -1 && UserSoldiers[EBX].WaitFor == -1 )
				;WriteD UserSoldiers[EBX].State
				;AnyKeyToContinue
					CopyFrom 	CollisionCurrID,	ECX
					CopyFrom 	WaitCheckCurrID,	ECX
					MOVE 		UserSoldiers, 	ECX, 1, 0
					CollisionCheck	 	CollisionCurrID
					UserWaitStackCheck	WaitCheckCurrID
				.ELSEIF( UserSoldiers[EBX].AttackTo != -1 )
					CopyFrom UserAttackSoldier, ECX
					CopyFrom UserAttackTarget, UserSoldiers[EBX].AttackTo
					.IF UserAttackTimer == 0
						CopyFrom UserAttackTimer,	1
					.ENDIF
				.ENDIF
			.ENDIF
			NextInc	8, MUS
		LoopTimes 0
		MCS:
			ObjectOffset ECX
			;WaitStackCheck	1,	ECX
			.IF CompSoldiers[EBX].Alive == 1 
				.IF(CompSoldiers[EBX].AttackTo == -1 && CompSoldiers[EBX].WaitFor == -1)
					MOVE CompSoldiers, ECX, -1, 0
					CopyFrom 	WaitCheckCurrID,	ECX
					CompWaitStackCheck	WaitCheckCurrID
				.ELSEIF (CompSoldiers[EBX].AttackTo != -1)
					CopyFrom CompAttackSoldier, ECX
					CopyFrom CompAttackTarget, CompSoldiers[EBX].AttackTo
					.IF CompAttackTimer == 0
						CopyFrom CompAttackTimer, 1
					.ENDIF
				.ENDIF
				;CollisionCheck	
			.ENDIF
			NextInc	8, MCS
		RET
	MoveingSoldiers ENDP
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Dump 	 Soldiers 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	DumpList MACRO 
		CopyFrom DebugMode, 1
		CALL DumpSoldierList
		ENDM
	DumpSoldier 	MACRO	Object, ID
		ObjectOffset ID
		Write  09H
		WriteD	Object[EBX].HP
		Write  09H
		WriteD	Object[EBX].X
		Write  09H
		WriteD	Object[EBX].Y
		;Write  09H
		;WriteD	Object[EBX].SWidth
		;Write  09H
		;WriteD	Object[EBX].SHeight
		Write  09H
		WriteD	Object[EBX].ATK
		Write  09H
		WriteD	Object[EBX].Level
		Write  09H
		WriteD	Object[EBX].ARMS
		Write  09H
		WriteD	Object[EBX].League
		Write  09H
		WriteI	Object[EBX].AttackTo
		Write  09H
		WriteI	Object[EBX].WaitFor
		Write  09H
		WriteI	Object[EBX].State
		Write  09H
		WriteD	Object[EBX].Alive
		Write  09H
	ENDM

	TableHead DB 	0AH,
					"ID",		09H,
					"HP",		09H,
					"X",		09H,
					"Y",		09H,
					"ATK",		09H,
					"Level",	09H,
					"AR",		09H,
					"Leag",		09H,
					"Attack",	09H,
					"Wait",		09H,
					"State",	09H,
					"Alive",	09H, 0

.Code
	DumpSoldierList		PROC
		PUSHA
			CopyFrom DebugMode, 1
			WriteS TableHead
			LoopTimes 0
			DSs:
				NL
				WriteD ECX
				DumpSoldier UserSoldiers, ECX
				NextInc	8, DSs
		POPA

		RET
	DumpSoldierList		ENDP