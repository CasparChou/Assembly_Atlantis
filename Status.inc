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

	GetterHandler 	DWORD ?

	User_Curr_Soilder DWORD ?
	Comp_Curr_Soilder DWORD ?


	Beats5x 	DWORD 	1
	Beats4x 	DWORD 	1
	Beats3x 	DWORD 	1
	Beats2x 	DWORD 	1
	

	Beats MACRO
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
			CopyFrom Beats5x, 1
		.ENDIF
	ENDM