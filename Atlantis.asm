	

	INCLUDE	Irvine32.inc
	INCLUDE	Helpers.inc


	INCLUDE	UI.inc
	INCLUDE	Graph_castle.inc
	INCLUDE	Graph_soldier.inc
	INCLUDE	Graph_turret.inc
	INCLUDE	Graph_Monster.inc
	
	INCLUDE	Status.inc
	INCLUDE	Function.inc
	INCLUDE	Object.inc

.Code
MAIN:
	RegisterObjects
	Initial
	LoopTimes 0FFFH
	CLS
	DR:


		;Draw
		
		KeyHandler
		PauseTime 1000
		;Clear
		NEXT DR
ExitMain
END MAIN