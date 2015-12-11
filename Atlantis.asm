

	INCLUDE	Irvine32.inc
	INCLUDE	Helpers.inc

	INCLUDE	Object.inc
	INCLUDE	Status.inc
	INCLUDE	Function.inc

	INCLUDE	UI.inc
	INCLUDE	Graph_castle.inc
	INCLUDE	Graph_soldier.inc
	INCLUDE	Graph_turret.inc
	INCLUDE	Graph_Monster.inc

.Code
MAIN:
	RegisterObjects
	LoopTimes 0FFFH
	DR:
		CLS
		Draw

		;SettingSoilderX UserSoilders, 2, 1
		;SettingSoilderY UserSoilders, 2, 2
		;SettingSoilderY UserSoilders, 1, 3
		;SettingSoilderX UserSoilders, 1, 4
		;SettingSoilderX UserSoilders, 1, 5
		
		NL
		NL
		NL
		PauseTime 1000
		NEXT DR
ExitMain
END MAIN