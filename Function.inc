.Data

	Draw MACRO

		;DrawTurrent  10,14
		;DrawSolider 	20, Beats2x
		;DrawMonster  	50, Beats5x
		;DrawMonster2 	70
		DrawSoilders
		DrawCastle	 	0
		DrawCastle		95

		MoveOnSoilders
		ENDM

	Clear MACRO
		SettingColor 	Black
		Draw
		DefaultColor
		Beats
		ENDM


	MOVE MACRO Object, ID, AddX, AddY

		AddBy Object[ID*4].X, AddX
		AddBy Object[ID*4].Y, AddY

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
			.ENDIF
		POPA
		ENDM

