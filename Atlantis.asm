	

	INCLUDE	Irvine32.inc
	INCLUDE	Helpers.inc

	INCLUDE	UI.inc
	INCLUDE	Graph_UI.inc
	INCLUDE	Graph_castle.inc
	INCLUDE	Graph_soldier.inc
	INCLUDE	Graph_turret.inc
	INCLUDE	Graph_Monster.inc
	
	INCLUDE	Status.inc
	INCLUDE	Object.inc
	INCLUDE collision.inc
	INCLUDE	Function.inc

	INCLUDE	AI.inc

.Code
MAIN:

	;StartUpLogo
	StartUp
	LoopTimes 0FFFH
	CLS
	;Initial
	DrawPanel
	Introduce


	DR:

		
		Draw
		AI
		;DumpList
		KeyHandler
		Translate 60, 28
		
		PauseTime 500
		Clear

		Beats
		MoveOnSoldiers
		LevelUpCheck

		LoopTimes 0FFFH
		NEXT DR
ExitMain
END MAIN