.Data



	LoopBuild	MACRO	Timer, Limit
		.IF ( Timer > Limit)
			CopyFrom Timer, 0
			
		.ENDIF
		ENDM
	AutoBuild	MACRO	Timer, When, Soldier
		.IF ( Timer == When && Beats4X == 1 )
			Soldier
		.ENDIF
		ENDM

	AI MACRO

		AutoBuild	Timer1, 1, BuildCompSoldierA
		AutoBuild	Timer1, 2, BuildCompSoldierB
		AutoBuild	Timer1, 3, BuildCompSoldierC
		LoopBuild Timer1, 3



		ENDM



