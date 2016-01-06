;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	   	Timers	 	    ;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.Data

	; counter -> AI_Timer
	AI_Timer 		DWORD 0

	Mod_A_Timer 	DWORD 0



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
	;isUpGrading	DWORD 1
	;ResetUpGradeFlag	EQU <CopyFrom isUpGrading, 0>
	;Mod_When_Attack	MACRO	isUpGrading
	;
	;	MOV 	EAX,	isUpGrading
	;	.IF ( EAX == 1 )
	;		BuildOnce	AI_Timer,	0,	Beats2x,	ResetUpGradeFlag
	;	.ENDIF
	;
	;ENDM
	

	Mod_A 	MACRO 	Time_Open,	Time_Close
		.IF ( AI_Timer >= Time_Open && AI_Timer <= Time_Close )

			AutoBuild	Mod_A_Timer, 4, 	Beats2x,	BuildCompSoldierA
			AutoBuild	Mod_A_Timer, 8, 	Beats2x,	BuildCompSoldierB
			LoopBuild 	Mod_A_Timer, 8,		Beats2x
			
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
		TimerInc 	AI_Timer,	Beats2x

		Mod_A 	0,	60


		ENDM



