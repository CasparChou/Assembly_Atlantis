.Data

	
	Draw MACRO

		;DrawTurrent  10,14
		;DrawSolider 	20, Beats2x
		;DrawMonster  	50, Beats5x
		;DrawMonster2 	70
		DrawSoilders
		DrawCastle	 	0, 0
		DrawCastle		1, 98

		ENDM

	Clear MACRO
		SettingColor 	Black
		Draw
		DefaultColor
		Beats
		MoveOnSoilders
		LevelUpCheck
		ENDM

	LevelUpCheck MACRO
		.IF( UserLevelUpFlag == 1)
			INC UserCurrLevel
			CopyFrom UserCurrLevel, 0
		.ENDIF
		.IF( CompLevelUpFlag == 1)
			INC CompCurrLevel
			CopyFrom CompCurrLevel, 0
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
				BuildUserSoilderA
			.ELSEIF( AL == 'W' || AL == 'w')
				BuildUserSoilderB
			.ELSEIF( AL == 'E' || AL == 'e')
				BuildUserSoilderC


			.ELSEIF( AL == 'I' || AL == 'i')
				BuildCompSoilderA
			.ELSEIF( AL == 'O' || AL == 'o')
				BuildCompSoilderB
			.ELSEIF( AL == 'P' || AL == 'p')
				BuildCompSoilderC


			.ELSEIF( AL == 'Z' || AL == 'z')
				CopyFrom UserLevelUpFlag, 1

			.ELSEIF( AL == 'X' || AL == 'x')
				CopyFrom CompLevelUpFlag, 1

			.ENDIF
		POPA
		ENDM
	DumpList 	MACRO

		CALL DumpSoilderList

		ENDM

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;		Moving 	 		;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	MOVE MACRO Object, ID, AddX, AddY
		ObjectOffset ID
		AddBy Object[EBX].X, AddX
		AddBy Object[EBX].Y, AddY
		ENDM
	MoveOnSoilders MACRO
		CALL MoveOnUserSoilders
		CALL MoveOnCompSoilders
		ENDM
.Code
	MoveOnUserSoilders PROC
		LoopTimes 0
		MS:
			ObjectOffset ECX
			.IF UserSoilders[EBX].Alive == 1
				MOVE UserSoilders, ECX, UserSoilders[EBX].SPD, 0
			.ENDIF
			NextInc	16, MS
		RET
	MoveOnUserSoilders ENDP
	MoveOnCompSoilders PROC
		LoopTimes 0
		MS:
			ObjectOffset ECX
			.IF CompSoilders[EBX].Alive == 1
				MOVE CompSoilders, ECX, CompSoilders[EBX].SPD, 0
			.ENDIF
			NextInc	16, MS
		RET
	MoveOnCompSoilders ENDP
	


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Build New Soilder 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	BuildSoilder MACRO Object, League, Arms, Speed
		PUSHA
			INVOKE FindUsableSoilder, League, Arms, Speed
		POPA
		ENDM
.Code	
	FindUsableSoilder PROC, League:DWORD, Arms:DWORD, Speed:DWORD
		PUSHA
				;WriteD League
				;AnyKeyToContinue

			.IF (League == 0)
				LoopTimes 0
				FindUser:
					ObjectOffset ECX
					.IF (UserSoilders[EBX].Alive == 0)
						SettingSoilderAlive		UserSoilders, ECX, 1
						SettingSoilderArms 		UserSoilders, ECX, Arms
						SettingSoilderX	 		UserSoilders, ECX, 20
						SettingSoilderLeague	UserSoilders, ECX, 0
						SettingSoilderSPD		UserSoilders, ECX, Speed
						SettingSoilderLevel		UserSoilders, ECX, UserCurrLevel
						RET
					.ELSE
						SettingSoilderAlive		UserSoilders, ECX, 1
						SettingSoilderLeague	UserSoilders, ECX, 0
					.ENDIF
					NextInc 8, FindUser
			.ELSEIF (League == 1)
				LoopTimes 0
				FindComp:
					ObjectOffset ECX
					.IF (CompSoilders[EBX].Alive == 0)
						SettingSoilderAlive		CompSoilders, ECX, 1
						SettingSoilderArms 		CompSoilders, ECX, Arms
						SettingSoilderX	 		CompSoilders, ECX, 90
						SettingSoilderLeague	CompSoilders, ECX, 1
						SettingSoilderSPD		CompSoilders, ECX, Speed
						SettingSoilderLevel		CompSoilders, ECX, CompCurrLevel
						RET
					.ELSE
						SettingSoilderAlive		CompSoilders, ECX, 1
						SettingSoilderLeague	CompSoilders, ECX, 1
					.ENDIF
					NextInc 8,	FindComp
			.ENDIF
		POPA
		RET
	FindUsableSoilder ENDP


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Drawing Soilders 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	SoilderOn	MACRO Object, ID
		ObjectOffset ID
		.IF (Object[EBX].Alive == 1)
			.IF (Object[EBX].League == 0) 
				.IF (Object[EBX].Arms == 1) 
					DrawSoilderA1 Object[EBX].X, Beats2x
				.ELSEIF (Object[EBX].Arms == 2) 
					;DrawSoilderB Object[EBX].X, Beats2x
				.ELSEIF (Object[EBX].Arms == 3) 
					;DrawSoilderC1 Object[EBX].X, Beats4x

				.ENDIF
			.ELSEIF (Object[EBX].League == 1) 
				DrawMonster Object[EBX].X, Beats2x
			.ENDIF
			;WriteD ID
		.ENDIF
		ENDM
.Code
	DrawingSoilders 	PROC
		PUSHA
			LoopTimes 0
			DSs:
				SoilderOn	UserSoilders, ECX
				SoilderOn	CompSoilders, ECX
				NextInc	8, DSs
		POPA
		RET
	DrawingSoilders		ENDP





;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Dump 	 Soilders 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	DumpSoilder 	MACRO	Object, ID
		ObjectOffset ID
		Write  09H
		WriteD	Object[EBX].HP
		Write  09H
		WriteD	Object[EBX].X
		Write  09H
		WriteD	Object[EBX].Y
		Write  09H
		WriteD	Object[EBX].ATK
		Write  09H
		WriteI	Object[EBX].SPD
		Write  09H
		WriteD	Object[EBX].LV
		Write  09H
		WriteD	Object[EBX].ARMS
		Write  09H
		WriteD	Object[EBX].League
		Write  09H
		WriteD	Object[EBX].State
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
					"SPD",		09H,
					"LV",		09H,
					"AR",		09H,
					"Leag",		09H,
					"State",	09H,
					"Alive",	09H, 0

.Code
	DumpSoilderList		PROC
		PUSHA
			WriteS TableHead
			LoopTimes 0
			DSs:
				NL
				WriteD ECX
				DumpSoilder UserSoilders, ECX
				NextInc	8, DSs
		POPA

		RET
	DumpSoilderList		ENDP