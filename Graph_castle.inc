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

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	DrawCastle MACRO League, X 
		MOV EAX,	League
		.IF ( EAX == 0 )
			.IF ( UserCurrLevel == 1)
				DrawUserCastle1 X
			.ELSEIF ( UserCurrLevel == 2)
				DrawUserCastle2 X
			.ELSEIF ( UserCurrLevel == 3)
				DrawUserCastle3 X
			.ENDIF
		.ELSE
			;.IF ( CompCurrLevel == 1)
			;	DrawMonsterCastle1 X
			;.ELSEIF ( CompCurrLevel == 2)
			;	DrawMonsterCastle2 X
			;.ELSEIF ( CompCurrLevel == 3)
			;	DrawMonsterCastle3 X
			;.ENDIF
		.ENDIF	

		ENDM