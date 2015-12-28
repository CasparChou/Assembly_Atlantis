.Code


	Building_Dialog_1	DB 	"¡m ¡m   ¡m Building Soldier ¡n   ¡n ¡n ",0
	Building_Dialog_2	DB 	"  ¡m   ¡m  Building Soldier  ¡n   ¡n   ",0
	Building_Dialog_3	DB 	" ¡m  ¡m    Building Soldier    ¡n  ¡n  ",0
	Building_Dialog_4	DB 	"¡m¡m       Building Soldier        ¡n¡n",0
	Building_Dialog_5	DB 	" ¡m        Building Soldier         ¡n ",0
	Building_Dialog_6	DB 	"           Building Soldier            ",0

	Building_Dialog		MACRO Fram
		
		.IF Fram == 1
			WriteSAtCenter	60,	21,	Building_Dialog_1
		.ELSEIF Fram == 2
			WriteSAtCenter	60,	21,	Building_Dialog_2
		.ELSEIF Fram == 3
			WriteSAtCenter	60,	21,	Building_Dialog_3
		.ELSEIF Fram == 4
			WriteSAtCenter	60,	21,	Building_Dialog_4
		.ELSEIF Fram == 5
			WriteSAtCenter	60,	21,	Building_Dialog_5
		.ELSEIF Fram == 6
			WriteSAtCenter	60,	21,	Building_Dialog_6
		.ENDIF
		MOV EAX,	Timer_Build_Goal
		MOV EBX,	Timer_UserBuild
		.IF (EAX !=0 && EBX !=0)
			SUB EAX,	EBX
			MOV SetterBuffer,	EAX
			DecAtCoord 59,23, SetterBuffer
		.ENDIF
		ENDM
	
	StartUp_1 	DB " A£n£f£\£h£nis  ",0
	StartUpLogo 	MACRO
		CLS
		SettingColor 	gray
		Translate 		50,13
		GraphDisplay 	StartUp_1
		
		PauseTime 		500
		SettingColor 	lightgray
		Translate 		50,13
		GraphDisplay 	StartUp_1
		
		PauseTime 		500
		SettingColor 	white
		Translate 		50,13
		GraphDisplay 	StartUp_1
		
		PauseTime 		500
		SettingColor 	lightgray
		Translate 		50,13
		GraphDisplay 	StartUp_1
		
		PauseTime 		500
		SettingColor 	gray
		Translate 		50,13
		GraphDisplay 	StartUp_1
		
		PauseTime 		500
		SettingColor 	black
		Translate 		50,13
		GraphDisplay 	StartUp_1
	
		ENDM
	

	KEY_A_1		DB	"¢z¢w¢{"	,0
	KEY_A_2		DB	"¢x¢ß¢x"	,0
	KEY_A_3		DB	"¢|¢w¢}"	,0	
	KEY_A	MACRO
		Translate 5, 22
		GraphDisplay	KEY_A_1
		GraphDisplay	KEY_A_2
		GraphDisplay	KEY_A_3
		ENDM
	KEY_B_1		DB	"¢z¢w¢{"	,0
	KEY_B_2		DB	"¢x¢å¢x"	,0
	KEY_B_3		DB	"¢|¢w¢}"	,0
	KEY_B	MACRO
		Translate 12, 22
		GraphDisplay	KEY_B_1
		GraphDisplay	KEY_B_2
		GraphDisplay	KEY_B_3		
		ENDM
	KEY_C_1		DB	"¢z¢w¢{"	,0
	KEY_C_2		DB	"¢x¢Ó¢x"	,0
	KEY_C_3		DB	"¢|¢w¢}"	,0
	KEY_C	MACRO
		Translate 19, 22
		GraphDisplay	KEY_C_1
		GraphDisplay	KEY_C_2
		GraphDisplay	KEY_C_3		
		ENDM
		
		
	
	DrawInfo	MACRO
	
		.IF(Building == 1)
			SettingColor Gray*16+White
			KEY_A
			DefaultColor
		.ELSE
			DefaultColor
			KEY_A
		.ENDIF	
		.IF(Building == 2)
			SettingColor Gray*16+White
			KEY_B
			DefaultColor
		.ELSE
			DefaultColor
			KEY_B
		.ENDIF	
		.IF(Building == 3)
			SettingColor Gray*16+White
			KEY_C
			DefaultColor
		.ELSE
			DefaultColor
			KEY_C
		.ENDIF
		
		ENDM
		
		
	INFO_Panel_1	DB "¡º¡»", 56 DUP("¡Ë"),		"¡»¡º",0
	INFO_Panel_2	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_3	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_4	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_5	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_6	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_7	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_8	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_9	DB "¢x", 116 DUP(" "),		"¢x",0
	INFO_Panel_10	DB "ùõ", 58 DUP("¡X"),		"ù÷",0
	
	
	
	DrawPanel MACRO
		Translate 0, 19
		GraphDisplay INFO_Panel_1
		GraphDisplay INFO_Panel_2
		GraphDisplay INFO_Panel_3
		GraphDisplay INFO_Panel_4
		GraphDisplay INFO_Panel_5
		GraphDisplay INFO_Panel_6
		GraphDisplay INFO_Panel_7
		GraphDisplay INFO_Panel_8
		GraphDisplay INFO_Panel_9
		GraphDisplay INFO_Panel_10
	
		ENDM
		
		
	Loading_1 	DB 	"¡@¡@¡Õ¡»¡Ö¡@¡@" ,0
	Loading_2 	DB 	"¡@¡Õ¡@¡¼¡@¡Ö¡@" ,0
	Loading_3 	DB 	"¡@¡Õ¡@¡»¡@¡Ö¡@" ,0
	Loading_4 	DB 	"¡@¡Õ¡@¡¼¡@¡Ö¡@" ,0
	
	DrawLoading MACRO Fram
	
		Translate 53, 25
		.IF( Fram == 1 || Fram == 5 )
			GraphDisplay Loading_1
		.ELSEIF( Fram == 2 )
			GraphDisplay Loading_2
		.ELSEIF( Fram == 3 )
			GraphDisplay Loading_3
		.ELSEIF( Fram == 4 )
			GraphDisplay Loading_4
		.ENDIF
		ENDM
		
		