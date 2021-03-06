;	Version 3
.Code


	Building_Dialog_1	DB 	"�m �m   �m Building Soldier �n   �n �n ",0
	Building_Dialog_2	DB 	"  �m   �m  Building Soldier  �n   �n   ",0
	Building_Dialog_3	DB 	" �m  �m    Building Soldier    �n  �n  ",0
	Building_Dialog_4	DB 	"�m�m       Building Soldier        �n�n",0
	Building_Dialog_5	DB 	" �m        Building Soldier         �n ",0
	Building_Dialog_6	DB 	"           Building Soldier            ",0
	NoEnoughMoney_Dialog	DB 	"           Not Enough Money           ",0
	UnderAttack_Dialog		DB 	"         Your Castle is under attack         ",0

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
		
	
	NoEnough_Dialog		MACRO
		.IF( EnoughTimer == 0 )
			
		.ELSEIF( EnoughTimer < 10)
			SettingColor LightRed
			WriteSAtCenter	60,	23,	NoEnoughMoney_Dialog
			INC EnoughTimer
			
		.ELSE
			CopyFrom EnoughTimer, 0
		.ENDIF
		
		ENDM
	
;	StartUp_1 	DB " A�n�f�\�h�nis  ",0
;	StartUpLogo 	MACRO
;		CLS
;		SettingColor 	gray
;		Translate 		50,13
;		GraphDisplay 	StartUp_1
;		
;		PauseTime 		500
;		SettingColor 	lightgray
;		Translate 		50,13
;		GraphDisplay 	StartUp_1
;		
;		PauseTime 		500
;		SettingColor 	white
;		Translate 		50,13
;		GraphDisplay 	StartUp_1
;		
;		PauseTime 		500
;		SettingColor 	lightgray
;		Translate 		50,13
;		GraphDisplay 	StartUp_1
;		
;		PauseTime 		500
;		SettingColor 	gray
;		Translate 		50,13
;		GraphDisplay 	StartUp_1
;		
;		PauseTime 		500
;		SettingColor 	black
;		Translate 		50,13
;		GraphDisplay 	StartUp_1
;	
;		ENDM
	

	KEY_A_1		DB	"�z�w�{"	,0
	KEY_A_2		DB	"�x�ߢx"	,0
	KEY_A_3		DB	"�|�w�}"	,0	
	KEY_A_4		DB	" $100 "	,0	
	KEY_A	MACRO
		Translate 5, 22
		GraphDisplay	KEY_A_1
		GraphDisplay	KEY_A_2
		GraphDisplay	KEY_A_3
		GraphDisplay	KEY_A_4
		ENDM
	KEY_B_1		DB	"�z�w�{"	,0
	KEY_B_2		DB	"�x��x"	,0
	KEY_B_3		DB	"�|�w�}"	,0
	KEY_B_4		DB	" $300 "	,0
	KEY_B	MACRO
		Translate 12, 22
		GraphDisplay	KEY_B_1
		GraphDisplay	KEY_B_2
		GraphDisplay	KEY_B_3		
		GraphDisplay	KEY_B_4	
		ENDM
	KEY_C_1		DB	"�z�w�{"	,0
	KEY_C_2		DB	"�x�Ӣx"	,0
	KEY_C_3		DB	"�|�w�}"	,0
	KEY_C_4		DB	" $600 "	,0
	KEY_C	MACRO
		Translate 19, 22
		GraphDisplay	KEY_C_1
		GraphDisplay	KEY_C_2
		GraphDisplay	KEY_C_3		
		GraphDisplay	KEY_C_4	
		ENDM
	
	
	KEY_Z_1		DB	"�z�w�{"	,0
	KEY_Z_2		DB	"�x��x Upgrade"	,0
	KEY_Z_3		DB	"�|�w�}"	,0
	
	KEY_Z_M_1 	DB "$1000",0
	KEY_Z_M_2 	DB "$3000",0
	KEY_Z_M_3 	DB "$5000",0
	KEY_Z	MACRO
		Translate 29, 24
		GraphDisplay	KEY_Z_1
		GraphDisplay	KEY_Z_2
		GraphDisplay	KEY_Z_3		
		.IF( UserCurrLevel == 1 )
			GraphDisplay KEY_Z_M_1
		.ELSEIF( UserCurrLevel == 2 )
			GraphDisplay KEY_Z_M_2
		.ELSEIF( UserCurrLevel == 3 )
			GraphDisplay KEY_Z_M_3
		.ENDIF
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

		.IF( UserCurrLevel == 1 )
			.IF( UserMoney > 1000)
				DefaultColor
				KEY_Z
			.ELSE
				SettingColor Gray
				KEY_Z
				DefaultColor
			.ENDIF
		.ELSEIF( UserCurrLevel == 2 )
			.IF( UserMoney > 3000)
				DefaultColor
				KEY_Z
			.ELSE
				SettingColor Gray
				KEY_Z
				DefaultColor
			.ENDIF
		.ELSEIF( UserCurrLevel == 3 )
			.IF( UserMoney > 5000 )
				DefaultColor
				KEY_Z
			.ELSE
				SettingColor Gray
				KEY_Z
				DefaultColor
			.ENDIF
		.ENDIF
		
		
		ENDM
		
		
	INFO_Panel_1	DB "�@�@�@", 	54 DUP("�p"),		"�@�@�@",0
	INFO_Panel_2	DB "�@�@�p", 	108 DUP(" "),		"�p�@�@",0
	INFO_Panel_3	DB "�@�p�@", 		108 DUP(" "),		"�@�p",0
	INFO_Panel_4	DB "�p", 		116 DUP(" "),		"�p",0
	INFO_Panel_5	DB "�p", 		116 DUP(" "),		"�p",0
	INFO_Panel_6	DB "�p", 		116 DUP(" "),		"�p",0
	INFO_Panel_7	DB "�p", 		116 DUP(" "),		"�p",0
	INFO_Panel_8	DB "�@�p�@", 		108 DUP(" "),		"�@�p�@",0
	INFO_Panel_9	DB "�@�@�p", 	108 DUP(" "),		"�p�@�@",0
	INFO_Panel_10	DB "�@�@�@", 	54 DUP("�p"),		"�@�@�@",0
	
	
	
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
		
		
	Loading_1 	DB 	"�@�@�ա��֡@�@" ,0
	Loading_2 	DB 	"�@�ա@���@�֡@" ,0
	Loading_3 	DB 	"�@�ա@���@�֡@" ,0
	Loading_4 	DB 	"�@�ա@���@�֡@" ,0
	
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
		
		