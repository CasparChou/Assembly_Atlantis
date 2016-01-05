;	Version 3
.Data

	DebugMode 		DWORD	0

	AtlantisTitle 	DB 		"Atlantis",0
	AtlantisSize	DB		"The best window size is 120 X 30,",0ah,"Press any key if you adjust done.",0

	StartUp MACRO
		CLS
		INVOKE		SetConsoleTitle, 	OFFSET AtlantisTitle
		DefaultColor
		Translate 	0,5
		WriteSAtCenter 	30,	30, AtlantisSize
		Translate 	0,0
		AnyKeyToContinue
	ENDM

	SetterBuffer 	DWORD ?
	GetterHandler 	DWORD ?

	User_Curr_Soldier DWORD ?
	Comp_Curr_Soldier DWORD ?

	UserCurrLevel 	DWORD	1
	CompCurrLevel 	DWORD	1

	UserLevelUpFlag	DWORD	0
	CompLevelUpFlag	DWORD	0



	Beats6x 	DWORD 	1
	Beats5x 	DWORD 	1
	Beats4x 	DWORD 	1
	Beats3x 	DWORD 	1
	Beats2x 	DWORD 	1
	

	Beats MACRO
		TimerCheck 	Timer_UserBuild,	Beats2x,	UserBuildTimerCheck
		TimerCheck 	Timer_CompBuild,	Beats2x,	CompBuildTimerCheck
		TimerCheck 	UserAttackTimer,	Beats2x,	UserAttack
		TimerCheck 	CompAttackTimer,	Beats2x,	CompAttack
		
		INC Beats2x
		INC Beats3x
		INC Beats4x
		INC Beats5x
		INC Beats6x
		.IF Beats2x == 3
			CopyFrom Beats2x, 1
		.ENDIF
		.IF Beats3x == 4
			CopyFrom Beats3x, 1
		.ENDIF
		.IF Beats4x == 5
			CopyFrom Beats4x, 1
		.ENDIF
		.IF Beats5x == 6
			INC Timer1
			CopyFrom Beats5x, 1
		.ENDIF
		.IF Beats6x == 7
			CopyFrom Beats6x, 1
		.ENDIF
	ENDM

	TimerCheck MACRO	Timer,	BeatsX,	CallBack
		.IF( Timer > 0 && BeatsX == 1)
			INC Timer
			CallBack
		.ENDIF
		ENDM

	TimerInc MACRO	Timer,	BeatsX
		.IF( Timer > 0 && BeatsX == 1)
			INC Timer
		.ENDIF
		ENDM

	ClearOn 	DWORD 0
	Building	DWORD 0



	Timer1				DWORD 0
	Timer_UserBuild		DWORD 0
	Timer_CompBuild		DWORD 0
	Timer_Build_Goal 	DWORD 0
	UserAttackTimer		DWORD 0
	CompAttackTimer		DWORD 0

	User_BuildQueue		DWORD	0,0,0,0,0,-1	;5 DUP(0)
	Comp_BuildQueue		DWORD	0,0,0,0,0,-1	;5 DUP(0)


	UserBuildTimerCheck MACRO
		PUSHA
			MOV ESI, OFFSET User_BuildQueue
			MOV EAX, [ESI]		;Arms
			GettingSoldierTime EAX,	UserCurrLevel, GetterHandler
			MOV EAX,	GetterHandler
			CopyFrom 	Timer_Build_Goal, 	GetterHandler
			CopyFrom 	Building, [ESI]
			.IF( Timer_UserBuild == EAX )
				TriggleBuild 0, [ESI]
				POPArray 	User_BuildQueue
				MOV EAX, User_BuildQueue
				.IF( EAX != 0 )
					CopyFrom Timer_UserBuild, 1
				.ELSE
					CopyFrom Timer_UserBuild, 	0
					CopyFrom Timer_Build_Goal, 	0
					CopyFrom Building, 0
				.ENDIF
			.ENDIF
		POPA
		ENDM

	CompBuildTimerCheck MACRO
		PUSHA
			MOV ESI, OFFSET Comp_BuildQueue
			MOV EAX, [ESI]
			GettingSoldierTime EAX,	CompCurrLevel, GetterHandler
			MOV EAX,	GetterHandler 
			.IF( Timer_CompBuild == EAX )
				TriggleBuild 1, [ESI]
				POPArray Comp_BuildQueue
				MOV EAX, Comp_BuildQueue
				.IF( EAX != 0 )
					CopyFrom Timer_CompBuild, 1
				.ELSE
					CopyFrom Timer_CompBuild, 0
				.ENDIF
			.ENDIF
		POPA
		ENDM

	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Dump 	 Soldiers 	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data
	DumpList MACRO 
		CopyFrom DebugMode, 1
		CALL DumpSoldierList
		ENDM
	DumpBothList MACRO 
		CopyFrom DebugMode, 1
		CALL DumpBothSoldierList
		ENDM
	DumpSoldier 	MACRO	Object, ID
		ObjectOffset ID
		Write  09H
		WriteD	Object[EBX].HP
		Write  09H
		WriteD	Object[EBX].X
		Write  09H
		WriteD	Object[EBX].Y
		Write  09H
		WriteD	Object[EBX].ATK
		Write  09H
		WriteD	Object[EBX].Level
		Write  09H
		WriteD	Object[EBX].ARMS
		Write  09H
		WriteD	Object[EBX].League
		Write  09H
		WriteI	Object[EBX].AttackTo
		Write  09H
		WriteI	Object[EBX].WaitFor
		Write  09H
		WriteI	Object[EBX].State
		Write  09H
		WriteD	Object[EBX].Alive
		Write  09H
	ENDM
	DumpBoth 	MACRO	ID
		ObjectOffset ID
		Write  09H
		WriteD	UserSoldiers[EBX].HP
		Write  09H
		WriteD	UserSoldiers[EBX].X
		Write  09H
		WriteD	UserSoldiers[EBX].Y
		Write  09H
		WriteI	UserSoldiers[EBX].AttackTo
		Write  09H
		WriteI	UserSoldiers[EBX].WaitFor
		Write  09H
		WriteD	UserSoldiers[EBX].Alive
		Write  09H
		WriteD	CompSoldiers[EBX].HP
		Write  09H
		WriteD	CompSoldiers[EBX].X
		Write  09H
		WriteD	CompSoldiers[EBX].Y
		Write  09H
		WriteI	CompSoldiers[EBX].AttackTo
		Write  09H
		WriteI	CompSoldiers[EBX].WaitFor
		Write  09H
		WriteD	CompSoldiers[EBX].Alive
		Write  09H

;		WriteD	Object[EBX].ATK
;		Write  09H
;		WriteD	Object[EBX].Level
;		Write  09H
;		WriteD	Object[EBX].ARMS
;		Write  09H
;		WriteD	Object[EBX].League
;		Write  09H
;		WriteI	Object[EBX].State
	ENDM

	TableHead DB 	0AH,
					"ID",		09H,
					"HP",		09H,
					"X",		09H,
					"Y",		09H,
					"ATK",		09H,
					"Level",	09H,
					"AR",		09H,
					"Leag",		09H,
					"Attack",	09H,
					"Wait",		09H,
					"State",	09H,
					"Alive",	09H, 0
	TableHeadBoth DB 	0AH,
					"ID",		09H,
					"HP",		09H,
					"X",		09H,
					"Y",		09H,
					"Attack",	09H,
					"Wait",		09H,
					"Alive",	09H,
					"HP",		09H,
					"X",		09H,
					"Y",		09H,
					"Attack",	09H,
					"Wait",		09H,
					"Alive",	09H,0

.Code
	DumpSoldierList		PROC
		PUSHA
			Translate 5, 20
			CopyFrom DebugMode, 1
			WriteS TableHead
			LoopTimes 0
			DSs:
				NL
				WriteD ECX
				DumpSoldier UserSoldiers, ECX
				NextInc	8, DSs
			TranslatePrevious
		POPA

		RET
	DumpSoldierList		ENDP
	DumpBothSoldierList		PROC
		PUSHA
			Translate 5, 20
			CopyFrom DebugMode, 1
			WriteS TableHeadBoth
			LoopTimes 0
			DSs:
				NL
				WriteD ECX
				DumpBoth ECX
				NextInc	8, DSs
			TranslatePrevious
		POPA

		RET
	DumpBothSoldierList		ENDP



