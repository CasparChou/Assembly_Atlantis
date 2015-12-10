Draw MACRO

	DrawCastle	 0, 13
	;DrawCastle2	20, 10
	;DrawCastle3	40, 9
	DrawSolider 20,10

	ENDM





GraphDisplay MACRO String
		PUSH EDX
			WriteS 	String
		POP  EDX
		INC  DH
		Call GoToXY
	ENDM