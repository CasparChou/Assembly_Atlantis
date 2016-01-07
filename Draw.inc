;	Version 3
.Data


	Draw MACRO
		DrawCastle	 	0, 0
		DrawCastle		1, 103

		DrawSoldiers
		PanelDisplay
		

		Collision		0,	0,	GetterHandler
		ENDM

	Clear MACRO
		SettingColor 	Black
		CopyFrom		ClearOn, 1
		;Draw
		.IF( UserLevelUpFlag == 1 )
			DrawCastle	 	0, 0
		.ENDIF
		.IF( CompLevelUpFlag == 1 )
			DrawCastle		1, 103
		.ENDIF
		DrawSoldiers
		PanelDisplay
		DefaultColor
		CopyFrom		ClearOn, 0

		ENDM

	PanelDisplay MACRO
		.IF DebugMode == 0
			DrawInfo
			.IF( Timer_UserBuild > 0)
				Building_Dialog Beats6x
				;DrawLoading 	Beats4x
			.ENDIF
			;DumpArray UserSoldierQueue
		.ENDIF

		ENDM

	GraphDisplay MACRO String
			PUSH EDX
				WriteS 	String
			POP  EDX
			INC  DH
			Call GoToXY
		ENDM

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Drawing Soldiers 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	SoldierOn	MACRO Object, ID
		ObjectOffset ID
		.IF (Object[EBX].Alive == 1)
			DrawHP Object, ID
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
			;GettingSoldierWidth Object, ID, GetterHandler
			;WriteD GetterHandler
		.ENDIF
		ENDM

	HPLine 			DWORD ?
	HPLineX			DWORD ?
	HPLineY			DWORD ?
	DrawHP MACRO Object, ID
		PUSHAD
			GettingSoldierX 		Object, ID,	HPLineX
			GettingSoldierHeight	Object, ID, HPLineY
			;AnyKeyToContinue
			;CopyFrom HPLineY, 15
			;SubBy HPLineY, GetterHandler
			ObjectOffset ID
			GettingSoldierHP 		Object, ID,	HPLine
			GettingSoldierPercentHP Object, ID,	GetterHandler
			DrawHPBar HPLineY, GetterHandler
		POPAD
		ENDM
	DrawHPBar  	 MACRO	HP, Length
		PUSHAD
			Translate HPLineX, HPLineY
			WriteD HP
			Write '['
			MOV ECX, Length
			.IF ECX == 1
				SettingColor Red
				Write 'I'
				Write ' '
				Write ' '
				Write ' '
			.ELSEIF ECX == 2
				SettingColor LightRed
				Write 'I'
				Write 'I'
				Write ' '
				Write ' '
			.ELSEIF ECX == 3
				SettingColor Green
				Write 'I'
				Write 'I'
				Write 'I'
				Write ' '
			.ELSEIF ECX == 4
				SettingColor LightGreen
				Write 'I'
				Write 'I'
				Write 'I'
				Write 'I'
			.ENDIF
			DefaultColor
			Write ']'
			TranslatePrevious
		POPAD
		ENDM
	DrawCastleHP MACRO	League
		PUSHAD
			MOV EAX, League

			.IF (EAX ==  0)
				CopyFrom HPLineX, 10
				CopyFrom HPLineY, 10
				MOV EBX, UserCastleHP
			.ELSE
				CopyFrom HPLineX, 110
				CopyFrom HPLineY, 10
				MOV EBX, CompCastleHP
			.ENDIF
			.IF EBX > 75
				DrawHPBar EBX, 4
			.ELSEIF EBX > 50
				DrawHPBar EBX, 3
			.ELSEIF EBX > 25
				DrawHPBar EBX, 2
			.ELSE
				DrawHPBar EBX, 1
			.ENDIF
		POPAD
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
