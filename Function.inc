Draw MACRO

	DrawCastle	 	0, 	13
	;DrawCastle2	20, 10
	DrawCastle		95, 9
	DrawSolider 	20,	10, Beats2x
	DrawMonster2 	70,	15
	DrawMonster  	50, 15, Beats5x
	;DrawTurrent  10,14
	Beats
	ENDM





GraphDisplay MACRO String
		PUSH EDX
			WriteS 	String
		POP  EDX
		INC  DH
		Call GoToXY
	ENDM


