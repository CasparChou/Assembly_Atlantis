.Data

	AtlantisTitle 	DB 		"Atlantis",0
	AtlantisSize	COORD	<10,10>
	GetterHandler 	DWORD ?

	User_Curr_Soilder DWORD ?
	Comp_Curr_Soilder DWORD ?


	Beats5x 	DWORD 	1
	Beats3x 	DWORD 	1
	Beats2x 	DWORD 	1
	

	Beats MACRO
		INC Beats2x
		INC Beats3x
		INC Beats5x
		.IF Beats2x == 3
			CopyFrom Beats2x, 1
		.ENDIF
		.IF Beats3x == 4
			CopyFrom Beats3x, 1
		.ENDIF
		.IF Beats5x == 6
			CopyFrom Beats5x, 1
		.ENDIF
	ENDM