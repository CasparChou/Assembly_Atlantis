.Data

	
	Draw MACRO

		DrawCastle	 	0, 0
		DrawCastle		1, 103
		DrawSoldiers
		;DrawInfo
		ENDM

	Clear MACRO
		SettingColor 	Black
		CopyFrom		ClearOn, 1
		Draw
		DefaultColor
		CopyFrom		ClearOn, 0
		;CopyFrom 		KeyPress, 0
		ENDM

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

	GraphDisplay MACRO String
			PUSH EDX
				WriteS 	String
			POP  EDX
			INC  DH
			Call GoToXY
		ENDM


	KeyHandler MACRO
		PUSHA
			MOV EAX, 0
			Call ReadKey
			.IF( AL == 'Q' || AL == 'q' )
				CopyFrom KeyPress, 1
				;BuildUserSoldierBufferTime
				BuildUserSoldierA
			.ELSEIF( AL == 'W' || AL == 'w')
				CopyFrom KeyPress, 2
				;BuildUserSoldierBufferTime
				BuildUserSoldierB
			.ELSEIF( AL == 'E' || AL == 'e')
				CopyFrom KeyPress, 3
				;BuildUserSoldierBufferTime
				BuildUserSoldierC


			.ELSEIF( AL == 'I' || AL == 'i')
				BuildCompSoldierA
			.ELSEIF( AL == 'O' || AL == 'o')
				BuildCompSoldierB
			.ELSEIF( AL == 'P' || AL == 'p')
				BuildCompSoldierC


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
	DumpList 	MACRO

		CALL DumpSoldierList

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
	MoveOnSoldiers MACRO
		CALL MoveOnUserSoldiers
		CALL MoveOnCompSoldiers
		ENDM
.Code
	MoveOnUserSoldiers PROC
		LoopTimes 0
		MS:
			ObjectOffset ECX
			.IF UserSoldiers[EBX].Alive == 1
				MOVE UserSoldiers, ECX, 1, 0
			.ENDIF
			NextInc	16, MS
		RET
	MoveOnUserSoldiers ENDP
	MoveOnCompSoldiers PROC
		LoopTimes 0
		MS:
			ObjectOffset ECX
			.IF CompSoldiers[EBX].Alive == 1
				MOVE CompSoldiers, ECX, -1, 0
			.ENDIF
			NextInc	16, MS
		RET
	MoveOnCompSoldiers ENDP
	


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Build New Soldier 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
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
						SettingSoldierInitialHP	UserSoldiers, ECX
						SettingSoldierAttack	UserSoldiers, ECX
						;SettingSoldierSize		UserSoldiers, ECX
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
						SettingSoldierInitialHP	CompSoldiers, ECX
						SettingSoldierAttack	CompSoldiers, ECX
						;SettingSoldierSize		CompSoldiers, ECX
						POPA
						RET
					.ENDIF
					NextInc 8,	FindComp
			.ENDIF
		POPA
		RET
	FindUsableSoldier ENDP


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Drawing Soldiers 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	SoldierOn	MACRO Object, ID
		ObjectOffset ID
		.IF (Object[EBX].Alive == 1)
			.IF (Object[EBX].League == 0) 
				
				.IF (Object[EBX].Arms == 1) 
					DrawSoldierA Object[EBX], Beats2x
				.ELSEIF (Object[EBX].Arms == 2) 
					DrawSoldierB Object[EBX], Beats2x
				.ELSEIF (Object[EBX].Arms == 3) 
					DrawSoldierC Object[EBX], Beats4x
				.ENDIF

			.ELSEIF (Object[EBX].League == 1) 

				.IF (Object[EBX].Arms == 1) 
					DrawMonsterA Object[EBX], Beats2x
				.ELSEIF (Object[EBX].Arms == 2) 
					DrawMonsterB Object[EBX], Beats4x
				.ELSEIF (Object[EBX].Arms == 3) 
					DrawMonsterC Object[EBX], Beats4x
				.ENDIF

			.ENDIF
			;WriteD MonsterWidth[((Object[EBX].Level-1)*4)+((Object[EBX].Arms-1)*12)]
			;WriteD ID
			GettingSoldierWidth Object, ID, GetterHandler
			WriteD GetterHandler
		.ENDIF
		ENDM
.Code
	DrawingSoldiers 	PROC
		PUSHA
			LoopTimes 0
			DSs:
				SoldierOn	UserSoldiers, ECX
				SoldierOn	CompSoldiers, ECX
				NextInc	8, DSs
		POPA
		RET
	DrawingSoldiers		ENDP





;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Dump 	 Soldiers 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
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
		;WriteD	Object[EBX].State
		;Write  09H
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
					"Alive",	09H, 0

.Code
	DumpSoldierList		PROC
		PUSHA
			WriteS TableHead
			LoopTimes 0
			DSs:
				NL
				WriteD ECX
				DumpSoldier CompSoldiers, ECX
				NextInc	8, DSs
		POPA

		RET
	DumpSoldierList		ENDP