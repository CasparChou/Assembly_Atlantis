.Code



	KEY_A_1		DB	"�z�w�{"	,0
	KEY_A_2		DB	"���ߡ�"	,0
	KEY_A_3		DB	"�|�w�}"	,0	
	KEY_A	MACRO
		Translate 5, 22
		GraphDisplay	KEY_A_1
		GraphDisplay	KEY_A_2
		GraphDisplay	KEY_A_3
		ENDM
	KEY_B_1		DB	"�z�w�{"	,0
	KEY_B_2		DB	"�����"	,0
	KEY_B_3		DB	"�|�w�}"	,0
	KEY_B	MACRO
		Translate 12, 22
		GraphDisplay	KEY_B_1
		GraphDisplay	KEY_B_2
		GraphDisplay	KEY_B_3		
		ENDM
	KEY_C_1		DB	"�z�w�{"	,0
	KEY_C_2		DB	"���ӡ�"	,0
	KEY_C_3		DB	"�|�w�}"	,0
	KEY_C	MACRO
		Translate 19, 22
		GraphDisplay	KEY_C_1
		GraphDisplay	KEY_C_2
		GraphDisplay	KEY_C_3		
		ENDM
		
		
	
	DrawInfo	MACRO
	
		.IF(KeyPress == 1)
			SettingColor Gray*16+White
			KEY_A
			DefaultColor
		.ELSE
			DefaultColor
			KEY_A
		.ENDIF	
		.IF(KeyPress == 2)
			SettingColor Gray*16+White
			KEY_B
			DefaultColor
		.ELSE
			DefaultColor
			KEY_B
		.ENDIF	
		.IF(KeyPress == 3)
			SettingColor Gray*16+White
			KEY_C
			DefaultColor
		.ELSE
			DefaultColor
			KEY_C
		.ENDIF
		
		ENDM
		
		
	INFO_Panel_1	DB "����", 56 DUP("��"),		"����",0
	INFO_Panel_2	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_3	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_4	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_5	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_6	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_7	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_8	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_9	DB "�x", 116 DUP(" "),		"�x",0
	INFO_Panel_10	DB "��", 58 DUP("�X"),		"��",0
	
	
	
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