

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
		;Draw

		SettingSolderLV UserSoilders, 2, 3
		SettingSolderLV UserSoilders, 1, 5
		SettingSolderLV UserSoilders, 0, 4

		GettingSolderLV UserSoilders, 1, GetterHandler
		WriteD	GetterHandler
		NL
		GettingSolderLV UserSoilders, 0, GetterHandler
		WriteD	GetterHandler
		NL
		GettingSolderLV UserSoilders, 2, GetterHandler
		WriteD	GetterHandler

		PauseTime 1000
		NEXT DR
ExitMain
END MAIN