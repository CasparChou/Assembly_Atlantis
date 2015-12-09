Draw MACRO

	DrawSolider 5,5

	ENDM





GraphDisplay MACRO String
		PUSH EDX
			WriteS 	String
		POP  EDX
		INC  DH
		Call GoToXY
	ENDM