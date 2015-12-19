	

	INCLUDE	Irvine32.inc
	INCLUDE	Helpers.inc

	INCLUDE	UI.inc
	INCLUDE	Graph_castle.inc
	INCLUDE	Graph_soldier.inc
	INCLUDE	Graph_turret.inc
	INCLUDE	Graph_Monster.inc
	
	INCLUDE	Status.inc
	INCLUDE	Object.inc
	INCLUDE	Function.inc

.Code
MAIN:

	StartUp
	LoopTimes 0FFFH
	CLS
	;Initial
	DR:


		Draw
		KeyHandler
		;DumpList
		PauseTime 800

		Clear

		NL
		NL
		LoopTimes 0FFFH
		NEXT DR
ExitMain
END MAIN