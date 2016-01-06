;	Version 3


	INCLUDE	Irvine32.inc
	INCLUDE	Helpers.inc

	INCLUDE	UI.inc
	INCLUDE	Graph_UI.inc
	INCLUDE	Graph_castle.inc
	INCLUDE	Graph_soldier.inc
	INCLUDE	Graph_turret.inc
	INCLUDE	Graph_Monster.inc
	INCLUDE	Graph_StartUp.inc
	
	INCLUDE	Object.inc
	INCLUDE	Status.inc
	INCLUDE Collision.inc
	INCLUDE Attack.inc
	INCLUDE	Draw.inc
	INCLUDE	Build.inc
	INCLUDE	Function.inc

	INCLUDE	AI.inc

.Code
MAIN:

	StartUp
	StartUpLogo
	LoopTimes 0FFFH
	CLS
	DrawPanel
	Introduce


	DR:
		;AnyKeyToContinue
		Draw
		AI
		;DumpBothList
		;DumpList
		KeyHandler
		Translate 60, 28
		
		PauseTime 250
		
		Clear

		Beats
		MoveOnSoldiers
		LevelUpCheck

		LoopTimes 0FFFH
		.IF ( Gaming == 1 )
			NEXT DR
		.ELSE
		.ENDIF
ExitMain
END MAIN