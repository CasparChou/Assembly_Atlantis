.Data
Draw MACRO

	DrawCastle	 	0
	DrawCastle		95

	;DrawTurrent  10,14

	
	;DrawSolider 	20, Beats2x
	DrawMonster  	50, Beats5x
	DrawMonster2 	70
	DrawSoilders

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


