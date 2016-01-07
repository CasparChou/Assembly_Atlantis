;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	   	Timers	 	    ;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data

	; counter -> AI_Timer
	AI_Timer 		DWORD 1

	Mod_A_Timer 	DWORD 0
	Mod_B_Timer 	DWORD 0
	Mod_C_Timer 	DWORD 0



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;		Rule Mods 	    ;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data

	;You can design the ai mods here
	;here is an example

	;	[[	Ative by Certain Event	]]
	;ResetEvent	EQU <CopyFrom isAttacked, 0>
	;Mod_When_Attack	MACRO	isAttacked
	;	MOV 	EAX,	isAttacked
	;	.IF ( EAX == 1 )
	;		
	;		AutoBuild 	Mod_When_Attack_Timer,	0,		BuildCompSoldierB
	;		AutoBuild 	Mod_When_Attack_Timer,	2,		BuildCompSoldierB
	;		AutoBuild 	Mod_When_Attack_Timer,	4,		BuildCompSoldierB
	;		AutoBuild 	Mod_When_Attack_Timer,	6,		BuildCompSoldierC
	;		BuildOnce	Mod_When_Attack_Timer,	6,		Beats4x,	ResetEvent
	;	.ENDIF
	;ENDM
	

	;	[[	Ative by Time Range	]]
	;Mod_B	MACRO	Time_Open,	Time_Close
	;	.IF ( AI_Timer >= Time_Open && AI_Timer <= Time_Close )
	;		
	;
	;		AutoBuild	Mod_B_Timer, 8, 	Beats4X,	BuildCompSoldierA
	;		AutoBuild	Mod_B_Timer, 16, 	Beats4X,	BuildCompSoldierB
	;		LoopBuild 	Mod_B_Timer, 16,	Beats4x
	;
	;	.ENDIF
	;ENDM

	;	[[	 UpGrade	]]
	Mod_UpGrade	MACRO	When
		.IF ( AI_Timer ==  When )
			.IF( CompCurrLevel < 3)
				CopyFrom CompLevelUpFlag, 1
			.ENDIF
		.ENDIF	
	ENDM

	;	[[	 UpGrade	]]
	Mod_Reset	MACRO	When
		.IF ( AI_Timer ==  When )
			CopyFrom AI_Timer, 0
		.ENDIF	
	ENDM
	

	Mod_A 	MACRO 	Time_Open,	Time_Close
		.IF ( AI_Timer >= Time_Open && AI_Timer <= Time_Close )

			AutoBuild	Mod_A_Timer, 0, 	Beats4x,	BuildCompSoldierA
			AutoBuild	Mod_A_Timer, 4, 	Beats4x,	BuildCompSoldierA
			AutoBuild	Mod_A_Timer, 8, 	Beats4x,	BuildCompSoldierB
			LoopBuild 	Mod_A_Timer, 8,		Beats4x
			
		.ENDIF
		ENDM

	Mod_B 	MACRO 	Time_Open,	Time_Close
		.IF ( AI_Timer >= Time_Open && AI_Timer <= Time_Close )

			AutoBuild	Mod_B_Timer, 0, 	Beats4x,	BuildCompSoldierA
			AutoBuild	Mod_B_Timer, 4, 	Beats4x,	BuildCompSoldierA
			AutoBuild	Mod_B_Timer, 8, 	Beats4x,	BuildCompSoldierC
			LoopBuild 	Mod_B_Timer, 8,	Beats4x
			
		.ENDIF
		ENDM

	Mod_C 	MACRO 	Time_Open,	Time_Close
		.IF ( AI_Timer >= Time_Open && AI_Timer <= Time_Close )

			AutoBuild	Mod_C_Timer, 2, 	Beats4x,	BuildCompSoldierB
			AutoBuild	Mod_C_Timer, 2, 	Beats4x,	BuildCompSoldierC
			LoopBuild 	Mod_C_Timer, 4,	Beats4x
			
		.ENDIF
		ENDM			


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	Main 	Functions	;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data

	LoopBuild	MACRO	Timer, Limit, BeatsX
		.IF ( BeatsX == 1 )
			INC Timer
		.ENDIF
		.IF ( Timer > Limit )
			CopyFrom Timer, 0
		.ENDIF
		ENDM

	BuildOnce	MACRO	Timer, Limit, BeatsX, 	WhenTimesUp
		.IF ( Timer < Limit )
			.IF ( BeatsX == 1 )
				INC Timer
			.ENDIF
		.ELSE
			WhenTimesUp
		.ENDIF
		ENDM

	AutoBuild	MACRO	Timer, When, isTrigger, Soldier
		.IF ( Timer == When && isTrigger == 1)
			Soldier
		.ENDIF
		ENDM


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;    ;;;;;;;;;        ;;;;;;;;;;;
;;;;  ;  ;;;;;;;;;;;  ;;;;;;;;;;;;;;
;;;;  ;;  ;;;;;;;;;;;  ;;;;;;;;;;;;;
;;;;  ;;;  ;;;;;;;;;;;  ;;;;;;;;;;;;
;;;;  ;;;;  ;;;;;;;;;;;  ;;;;;;;;;;;
;;;;         ;;;;;;;;;;;  ;;;;;;;;;;
;;;;  ;;;;;;  ;;;;;;;;;;;  ;;;;;;;;;
;;;;  ;;;;;;;  ;;;;;;;        ;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.Data
	AI MACRO
		TimerBeat 	AI_Timer,	Beats4x

				;DefaultColor
				;WriteSAtCenter	60,	10,	Attacking
				;Translate 20,10
				;Write '['
;
				;WriteI AI_Timer
				;Write ']'
				;;AnyKeyToContinue
				;TranslatePrevious




		Mod_A 	0,	10
		Mod_A 	12,	22
		Mod_B 	24,	34
		Mod_C 	38,	48

		Mod_A 	50,	60
		Mod_A 	62,	72
		Mod_B 	74,	84
		Mod_C 	88,	98

		Mod_UpGrade 101
		Mod_Reset	101


		ENDM



