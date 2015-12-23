.Data

	AtlantisTitle 	DB 		"Atlantis",0
	AtlantisSize	DB		8 DUP(0AH), 3 DUP(09H),"The best window size is 120 X 30, Press any key if you adjust done.",0

	StartUp MACRO
		CLS
		INVOKE		SetConsoleTitle, 	OFFSET AtlantisTitle
		WriteS 		AtlantisSize
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



	Beats5x 	DWORD 	1
	Beats4x 	DWORD 	1
	Beats3x 	DWORD 	1
	Beats2x 	DWORD 	1
	

	Beats MACRO
		.IF( Timer_UserBuild > 0 && Beats2x == 1 )
			INC Timer_UserBuild
			UserBuildTimerCheck
		.ENDIF
		.IF( Timer_CompBuild > 0 && Beats2x == 1 )
			INC Timer_CompBuild
			CompBuildTimerCheck
		.ENDIF
		INC Beats2x
		INC Beats3x
		INC Beats4x
		INC Beats5x
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
	ENDM


	ClearOn 	DWORD 0
	KeyPress 	DWORD 0



	Timer1		DWORD 0
	Timer_UserBuild	DWORD 0
	Timer_CompBuild	DWORD 0


	User_BuildQueue		DWORD	0,0,0,0,0,-1	;5 DUP(0)
	Comp_BuildQueue		DWORD	0,0,0,0,0,-1	;5 DUP(0)


	UserBuildTimerCheck MACRO
		PUSHA
			MOV ESI, OFFSET User_BuildQueue
			MOV EAX, [ESI]
			GettingSoldierTime EAX,	UserCurrLevel, GetterHandler
			MOV EAX,	GetterHandler 
			.IF( Timer_UserBuild == EAX )
				TriggleBuild 0, [ESI]
				POPArray User_BuildQueue
				MOV EAX, User_BuildQueue
				.IF( EAX != 0 )
					CopyFrom Timer_UserBuild, 1
				.ELSE
					CopyFrom Timer_UserBuild, 0
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





