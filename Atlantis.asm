

	INCLUDE	Irvine32.inc
	INCLUDE	Helpers.inc
	
	INCLUDE	Motion.inc
	INCLUDE	Status.inc
	INCLUDE	Function.inc

	INCLUDE	UI.inc
	INCLUDE	Graph_castle.inc
	INCLUDE	Graph_soldier.inc
	INCLUDE	Graph_turret.inc
	INCLUDE	Graph_Monster.inc

	TitleS 	DB	"Atlantis",0
	HAND	DWORD	?	
	DWS		COORD <200,200>
.Code
MAIN:
	LoopTimes 0FFFH
	DR:
		Draw
		PauseTime 1000
		;CALL ForceCLS
		;AnyKeyToContinue
		CALL ClrScr
		;AnyKeyToContinue
		NEXT DR
ExitMain
END MAIN