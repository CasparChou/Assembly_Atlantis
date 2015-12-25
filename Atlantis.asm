	

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

	StartUp
	LoopTimes 0FFFH
	CLS
	;Initial
	DR:

		DrawPanel
		Draw
		;AI
		KeyHandler
		;DumpList
		Translate 15, 2
		;WriteD Timer1
		;Write 	' '
		;WriteD Timer_UserBuild
		
		PauseTime 800

		Clear

		Beats
		MoveOnSoldiers
		LevelUpCheck

		LoopTimes 0FFFH
		NEXT DR
ExitMain
END MAIN