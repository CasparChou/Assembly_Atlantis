.Data

	Draw MACRO

		;DrawTurrent  10,14
		;DrawSolider 	20, Beats2x
		;DrawMonster  	50, Beats5x
		;DrawMonster2 	70
		DrawSoilders
		DrawCastle	 	0
		DrawCastle		99

		ENDM

	Clear MACRO
		SettingColor 	Black
		Draw
		DefaultColor
		Beats
		MoveOnSoilders
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
				BuildCompSoilderA
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
		AddBy Object[ID*4].X, AddX
		AddBy Object[ID*4].Y, AddY
		ENDM
	MoveOnSoilders MACRO
		CALL MoveOnUserSoilders
		CALL MoveOnCompSoilders
		ENDM
.Code
	MoveOnUserSoilders PROC
		LoopTimes 0
		MS:
			.IF UserSoilders[ECX*4].Alive == 1
				MOVE UserSoilders, ECX, UserSoilders[ECX*4].SPD, 0
			.ENDIF
			NextInc	16, MS
		RET
	MoveOnUserSoilders ENDP
	MoveOnCompSoilders PROC
		LoopTimes 0
		MS:
			.IF CompSoilders[ECX*4].Alive == 1
				MOVE CompSoilders, ECX, CompSoilders[ECX*4].SPD, 0
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
	BuildSoilder MACRO Object, League, Level, Speed
		PUSHA
			INVOKE FindUsableSoilder, League, Level, Speed
			;.IF (ECX == 0)
			;	CALL FindUsableUserSoilder
			;	SettingSoilderLV 	Object, ECX, Level
			;	SettingSoilderX	 	Object, ECX, 20
			;	SettingSoilderSPD	Object, ECX, Speed
			;.ELSE
			;	CALL FindUsableCompSoilder
			;	SettingSoilderLV 	Object, ECX, Level
			;	SettingSoilderX	 	Object, ECX, 70
			;	SettingSoilderSPD	Object, ECX, Speed
			;.ENDIF
		POPA
		ENDM
.Code	
	FindUsableSoilder PROC, League:DWORD, Level:DWORD, Speed:DWORD
		PUSHA
				;WriteD League
				;AnyKeyToContinue

			.IF (League == 0)
				LoopTimes 0
				FindUser:
					.IF (UserSoilders[ECX*4].Alive == 0)
						SettingSoilderAlive		UserSoilders, ECX, 1
						SettingSoilderLV 		UserSoilders, ECX, Level
						SettingSoilderX	 		UserSoilders, ECX, 20
						SettingSoilderLeague	UserSoilders, ECX, 0
						SettingSoilderSPD		UserSoilders, ECX, Speed
						RET
					.ELSE
						SettingSoilderAlive		UserSoilders, ECX, 1
						SettingSoilderLeague	UserSoilders, ECX, 0
					.ENDIF
					NextInc 8, FindUser
			.ELSEIF (League == 1)
				LoopTimes 0
				FindComp:
					.IF (CompSoilders[ECX*4].Alive == 0)
						SettingSoilderAlive		CompSoilders, ECX, 1
						SettingSoilderLV 		CompSoilders, ECX, Level
						SettingSoilderX	 		CompSoilders, ECX, 90
						SettingSoilderLeague	CompSoilders, ECX, 1
						SettingSoilderSPD		CompSoilders, ECX, Speed
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
		.IF (Object[ID*4].Alive == 1)
			.IF (Object[ID*4].League == 0) 
				DrawSoilder Object[ID*4].X, Beats2x

			.ELSEIF (Object[ID*4].League == 1) 
				DrawMonster Object[ID*4].X, Beats2x
			.ENDIF
			WriteD ID
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

.Code
	DumpSoilderList		PROC
		PUSHA
			NL
				Write 'I'
				Write 'D'
				LoopTimes 2
				A2AA:
				Write  09H
				Write 'H'
				Write 'P'
				Write  09H
				Write 'X'
				Write  09H
				Write 'S'
				Write 'P'
				Write 'D'
				Write  09H
				Write 'L'
				Write 'V'
				Write  09H
				Write 'A'
				Write 'R'
				Write  09H
				Write 'L'
				Write 'E'
				Write  09H
				Write 'A'
				Write 'L'
				NEXT A2AA
				
			LoopTimes 0
			DSs:
				NL
				WriteD ECX
				Write  09H
				WriteD	UserSoilders[ECX*4].HP
				Write  09H
				WriteD	UserSoilders[ECX*4].X
				Write  09H
				WriteD	UserSoilders[ECX*4].SPD
				Write  09H
				WriteD	UserSoilders[ECX*4].LV
				Write  09H
				WriteD	UserSoilders[ECX*4].ARMS
				Write  09H
				WriteD	UserSoilders[ECX*4].League
				Write  09H
				WriteD	UserSoilders[ECX*4].Alive
				Write  09H
				WriteD	CompSoilders[ECX*4].HP
				Write  09H
				WriteD	CompSoilders[ECX*4].X
				Write  09H
				WriteD	CompSoilders[ECX*4].SPD
				Write  09H
				WriteD	CompSoilders[ECX*4].LV
				Write  09H
				WriteD	CompSoilders[ECX*4].ARMS
				Write  09H
				WriteD	CompSoilders[ECX*4].League
				Write  09H
				WriteD	CompSoilders[ECX*4].Alive
				NextInc	8, DSs
		POPA

		RET
	DumpSoilderList		ENDP