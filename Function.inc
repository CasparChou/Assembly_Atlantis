Draw MACRO

	DrawMonster  80, 17
	DrawCastle	 0, 13
	;DrawCastle2	20, 10
	DrawCastle3	95, 9
	;DrawSolider 20,10
	DrawMonster2 70,15
	DrawTurrent  10,14

	ENDM





GraphDisplay MACRO String
		PUSH EDX
			WriteS 	String
		POP  EDX
		INC  DH
		Call GoToXY
	ENDM


