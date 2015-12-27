	

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
	INCLUDE Collision.inc
	;INCLUDE Attack.inc
	INCLUDE	Draw.inc
	INCLUDE	Build.inc
	INCLUDE	Function.inc

	INCLUDE	AI.inc

.Code
MAIN:

	;StartUpLogo
	StartUp
	LoopTimes 0FFFH
	CLS
	DrawPanel
	Introduce


	DR:

		
		;AnyKeyToContinue
		Draw
		;AI
		DumpList
		KeyHandler
		Translate 60, 28
		
		PauseTime 600
		
		Clear

		Beats
		MoveOnSoldiers
		LevelUpCheck

		LoopTimes 0FFFH
		NEXT DR
ExitMain
END MAIN