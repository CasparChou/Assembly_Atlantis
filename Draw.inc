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
