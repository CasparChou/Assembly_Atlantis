Draw MACRO

	DrawCastle	 	0
	;DrawCastle2	20, 10
	DrawCastle		95
	DrawSolider 	20, Beats2x
	DrawMonster2 	70
	DrawMonster  	50, Beats5x
	;DrawTurrent  10,14
	Beats
	ENDM


MOVE MACRO Object, X, Y
	LoopTimes 0
;	INVOKE	MovingFunction, 3

	ENDM


GraphDisplay MACRO String
		PUSH EDX
			WriteS 	String
		POP  EDX
		INC  DH
		Call GoToXY
	ENDM


