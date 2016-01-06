;	Version 3
.Data

;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i      ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i      ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i        ¢i¢i¢i¢i¢i      ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i



	UserCastle_1_1    	DB     "       ¢i  ¢i       ",0
	UserCastle_1_2    	DB     "     ¢i¢i¢i¢i¢i        ",0
	UserCastle_1_3    	DB     "     ¢i¢«  ¢ª¢i     ",0
	UserCastle_1_4    	DB     "     ¢i      ¢i     ",0
	UserCastle_1_5    	DB     " ¢d¢d¢i      ¢i¢d¢d ",0
	
	UserCastle_2_1    	DB     "           ¢«     ",0
	UserCastle_2_2    	DB     "           ¢k     ",0
	UserCastle_2_3    	DB     "          ¢i       ",0
	UserCastle_2_4    	DB     "        ¢i¢i¢i       ",0
	UserCastle_2_5    	DB     "      ¢i¢i¢i¢i¢i       ",0
	UserCastle_2_6    	DB     "      ¢i¢«  ¢ª¢i    ",0
	UserCastle_2_7    	DB     "    ¢i¢i      ¢i¢i    ",0
	UserCastle_2_8    	DB     "  ¢d¢i¢i      ¢i¢i¢d  ",0
	
	UserCastle_3_1 		DB	   "          ¢«     ",0
	UserCastle_3_2 		DB	   "      ¢«  ¢k  ¢« ",0
	UserCastle_3_3 		DB	   "      ¢k ¡¶   ¢k   	",0
	UserCastle_3_4 		DB	   "     ¡¶  ¢i  ¡¶     ",0
	UserCastle_3_5 		DB	   "     ¢i¢i¢i¢i¢i       ",0
	UserCastle_3_6 		DB	   "     ¢i¢i¢i¢i¢i       ",0
	UserCastle_3_7 		DB	   " ¡¶  ¢i¢«  ¢ª¢i  ¡¶    ",0
	UserCastle_3_8 		DB	   " ¢i¢i¢i      ¢i¢i¢i    ",0
	UserCastle_3_9 		DB	   " ¢i¢i¢i      ¢i¢i¢i    ",0

	DrawUserCastle1 MACRO X
		
		Translate X, 13

		GraphDisplay UserCastle_1_1
		GraphDisplay UserCastle_1_2
		GraphDisplay UserCastle_1_3
		GraphDisplay UserCastle_1_4
		GraphDisplay UserCastle_1_5

		ENDM
	
	DrawUserCastle2 MACRO X

		Translate X, 10

		GraphDisplay UserCastle_2_1
		GraphDisplay UserCastle_2_2
		GraphDisplay UserCastle_2_3
		GraphDisplay UserCastle_2_4
		GraphDisplay UserCastle_2_5
		GraphDisplay UserCastle_2_6
		GraphDisplay UserCastle_2_7
		GraphDisplay UserCastle_2_8

		ENDM
		
	DrawUserCastle3 MACRO X
	
		Translate X, 9

		GraphDisplay UserCastle_3_1
		GraphDisplay UserCastle_3_2
		GraphDisplay UserCastle_3_3
		GraphDisplay UserCastle_3_4
		GraphDisplay UserCastle_3_5
		GraphDisplay UserCastle_3_6
		GraphDisplay UserCastle_3_7
		GraphDisplay UserCastle_3_8
		GraphDisplay UserCastle_3_9

		ENDM
	
	
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i         ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i       ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i  ¢i¢i          ¢i¢i¢i
;¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i  ¢i¢i  ¢i¢i  ¢i¢i  ¢i¢i¢i
;¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i       ¢i¢i  ¢i¢i  ¢i¢i  ¢i¢i¢i
;¢i¢i¢i¢i¢i¢i         ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i  ¢i¢i  ¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i

	
	CompCastle_1_1 DB "¡¶¡¶¡¶¡¶¡¶¡¶   ",0
	CompCastle_1_2 DB "¢g¢g¢g¢g¢g¢g",0
	CompCastle_1_3 DB "¢g¢g    ¢g¢g",0
	CompCastle_1_4 DB "¢g¢«    ¢ª¢g",0
	CompCastle_1_5 DB "¢g        ¢p",0
	CompCastle_1_6 DB "¢g        ¢g",0
		
	
	CompCastle_2_1 DB "      ¡¶¡¶",0
	CompCastle_2_2 DB "      ¢g¢g",0
	CompCastle_2_3 DB "  ¡¶¢g¢g¢g¢g¡¶",0
	CompCastle_2_4 DB "  ¢g¢g¡¿¡¿¢g¢g",0
	CompCastle_2_5 DB "¡¶¢g¢g    ¢g¢g¡¶",0
	CompCastle_2_6 DB "¢p¢g¢«    ¢ª¢g¢p",0
	CompCastle_2_7 DB "  ¢g        ¢g",0
	CompCastle_2_8 DB "  ¢p        ¢p",0

	
	CompCastle_3_1 DB "    ¡¶    ¡¶      ",0
	CompCastle_3_2 DB "    ¢g¡¶¡¶¢g        ",0
	CompCastle_3_3 DB "    ¢g¢g¢g¢g    ",0
	CompCastle_3_4 DB "  ¡¶¢g¢g¢g¢g¡¶       ",0
	CompCastle_3_5 DB "  ¢g¢g¡¿¡¿¢g¢g       ",0
	CompCastle_3_6 DB "¡¶¢g¢g    ¢g¢g¡¶     ",0
	CompCastle_3_7 DB "¢p¢g¡¿    ¡¿¢g¢p      ",0
	CompCastle_3_8 DB "¢p¢g        ¢g¢p",0
	CompCastle_3_9 DB "¢p¢p        ¢p¢p",0

	DrawCompCastle1 MACRO X
	
		Translate X, 12

		GraphDisplay CompCastle_1_1
		GraphDisplay CompCastle_1_2
		GraphDisplay CompCastle_1_3
		GraphDisplay CompCastle_1_4
		GraphDisplay CompCastle_1_5
		GraphDisplay CompCastle_1_6

		ENDM	
	
	DrawCompCastle2 MACRO X
	
		Translate X, 10

		GraphDisplay CompCastle_2_1
		GraphDisplay CompCastle_2_2
		GraphDisplay CompCastle_2_3
		GraphDisplay CompCastle_2_4
		GraphDisplay CompCastle_2_5
		GraphDisplay CompCastle_2_6
		GraphDisplay CompCastle_2_7
		GraphDisplay CompCastle_2_8

		ENDM	
	
	DrawCompCastle3 MACRO X
	
		Translate X, 9

		GraphDisplay CompCastle_3_1
		GraphDisplay CompCastle_3_2
		GraphDisplay CompCastle_3_3
		GraphDisplay CompCastle_3_4
		GraphDisplay CompCastle_3_5
		GraphDisplay CompCastle_3_6
		GraphDisplay CompCastle_3_7
		GraphDisplay CompCastle_3_8
		GraphDisplay CompCastle_3_9

		ENDM	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	DrawCastle MACRO League, X 
		DrawCastleHP League
		MOV EAX,	League
		.IF ( EAX == 0 )
			SettingColor Yellow
			.IF ( UserCurrLevel == 1)
				DrawUserCastle1 X
			.ELSEIF ( UserCurrLevel == 2)
				DrawUserCastle2 X
			.ELSEIF ( UserCurrLevel == 3)
				DrawUserCastle3 X
			.ENDIF
			DefaultColor
		.ELSE
			SettingColor LightRed
			.IF ( CompCurrLevel == 1)
				DrawCompCastle1 X
			.ELSEIF ( CompCurrLevel == 2)
				DrawCompCastle2 X
			.ELSEIF ( CompCurrLevel == 3)
				DrawCompCastle3 X
			.ENDIF
			DefaultColor
		.ENDIF	

		ENDM