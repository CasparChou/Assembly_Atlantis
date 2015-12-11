.Data


	Beats5x 	DWORD 	1
	Beats3x 	DWORD 	1
	Beats2x 	DWORD 	1
	Soilder STRUCT
		HP			DWORD ?
		XY			COORD <>
		ATK			DWORD ?
		SPD			DWORD ?
		LV			DWORD ?
		KIND		DWORD ?
		Fram_Curr 	DWORD ?
		Fram_MAX 	DWORD ?
	Soilder ENDS
	
	Soilder1 Soilder <>
	Soilder2 Soilder <>
	Soilder3 Soilder <>
	Soilder4 Soilder <>
	Soilder5 Soilder <>
	Soilder6 Soilder <>
	Soilder7 Soilder <>
	Soilder8 Soilder <>

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