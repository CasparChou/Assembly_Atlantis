.Data


;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i    ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i          ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i


	DrawMonsterA	MACRO	Object, Fram
		
		.IF ( Object.Level == 1)
			DrawMonsterA1 Object.X, Fram
		.ELSEIF ( Object.Level == 2)
			DrawMonsterA2 Object.X, Fram
		.ELSEIF ( Object.Level == 3)
			DrawMonsterA3 Object.X, Fram
		.ENDIF
		
		ENDM




	MonsterA1_1_1 		DB 		" ¢¬¢­ " ,0
	MonsterA1_1_2 		DB 		"¡ü¡ü¡ü   "	,0
	MonsterA1_1_3 		DB 		"ùõ¡óù÷ " ,0
	MonsterA1_1_4 		DB 		"  ¢p " ,0

	DrawMonsterA1 MACRO X, Fram

		Translate X, 14
		.IF (Fram == 1)
			GraphDisplay MonsterA1_1_1
			GraphDisplay MonsterA1_1_2
			GraphDisplay MonsterA1_1_3
			GraphDisplay MonsterA1_1_4
		.ELSEIF  (Fram == 2)
			GraphDisplay MonsterA1_1_1
			GraphDisplay MonsterA1_1_2
			GraphDisplay MonsterA1_1_3
			GraphDisplay MonsterA1_1_4
		.ENDIF
		ENDM
		
		

	MonsterA2_1_1 		DB	" ¢¨¢© ",0
	MonsterA2_1_2 		DB	"¡ü¡ó¡ü    ",0
	MonsterA2_1_3 		DB	"ùã¢pùå  ",0
	MonsterA2_1_4 		DB	"  ¡ü		",0
		

	DrawMonsterA2 MACRO X, Fram

		Translate X, 14
		.IF (Fram == 1)
			GraphDisplay MonsterA2_1_1
			GraphDisplay MonsterA2_1_2
			GraphDisplay MonsterA2_1_3
			GraphDisplay MonsterA2_1_4
			
		.ELSEIF  (Fram == 2)
			GraphDisplay MonsterA2_1_1
			GraphDisplay MonsterA2_1_2
			GraphDisplay MonsterA2_1_3
			GraphDisplay MonsterA2_1_4
		.ENDIF
		ENDM


	MonsterA3_1_1 	DB "   ¡¶   ",0
	MonsterA3_1_2 	DB " ¢¨¢p¢©",0
	MonsterA3_1_3 	DB " ¡ü¡¹¡ü    ",0
	MonsterA3_1_4 	DB " ¡ü¢E¡ü   ",0
	MonsterA3_1_5 	DB "ùã ¡ó ùå ",0
	MonsterA3_1_6 	DB "   ¡¿	",0
			

	DrawMonsterA3 MACRO X, Fram

		Translate X, 12
		.IF (Fram == 1)
			GraphDisplay MonsterA3_1_1
			GraphDisplay MonsterA3_1_2
			GraphDisplay MonsterA3_1_3
			GraphDisplay MonsterA3_1_4
			GraphDisplay MonsterA3_1_5
			GraphDisplay MonsterA3_1_6
		.ELSEIF  (Fram == 2)
			GraphDisplay MonsterA3_1_1
			GraphDisplay MonsterA3_1_2
			GraphDisplay MonsterA3_1_3
			GraphDisplay MonsterA3_1_4
			GraphDisplay MonsterA3_1_5
			GraphDisplay MonsterA3_1_6
		.ENDIF
		ENDM
	
		
	

		
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i          ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i              ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i              ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i


	DrawMonsterB	MACRO	Object, Fram
		
		.IF ( Object.Level == 1)
			DrawMonsterB1 Object.X, Fram
		.ELSEIF ( Object.Level == 2)
			DrawMonsterB2 Object.X, Fram
		.ELSEIF ( Object.Level == 3)
			DrawMonsterB3 Object.X, Fram
		.ENDIF
		
		ENDM



	MonsterB1_1_1    	DB     	"    ",0
	MonsterB1_1_2    	DB     	"    ",0
	MonsterB1_1_3   	DB     	"=¡ó=",0
	       
	MonsterB1_2_1    	DB     	"    ",0
	MonsterB1_2_2    	DB     	"=¡ó=",0
	MonsterB1_2_3    	DB     	"    ",0
	       
	MonsterB1_3_1    	DB     	"=¡ó=",0
	MonsterB1_3_2    	DB     	"    ",0
	MonsterB1_3_3    	DB     	"    ",0
		

	DrawMonsterB1 MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1 || Fram == 5)
			GraphDisplay MonsterB1_1_1
			GraphDisplay MonsterB1_1_2
			GraphDisplay MonsterB1_1_3
		.ELSEIF  (Fram == 2 || Fram == 4)
			GraphDisplay MonsterB1_2_1
			GraphDisplay MonsterB1_2_2
			GraphDisplay MonsterB1_2_3
		.ELSE
			GraphDisplay MonsterB1_3_1
			GraphDisplay MonsterB1_3_2
			GraphDisplay MonsterB1_3_3
		.ENDIF
		ENDM

	MonsterB2_1_1		DB "      ",0
	MonsterB2_1_2		DB "      ",0
	MonsterB2_1_3		DB "  ¡å   ",0
	MonsterB2_1_4		DB "<=¡ó=>",0
	MonsterB2_1_5		DB "  ¡Ð  ",0
	
	MonsterB2_2_1		DB "      ",0
	MonsterB2_2_2		DB "  ¡å   ",0
	MonsterB2_2_3		DB "<=¡ó=>",0
	MonsterB2_2_4		DB "  ¡Ð  ",0
	MonsterB2_2_5		DB "      ",0
	
	MonsterB2_3_1		DB "  ¡å   ",0
	MonsterB2_3_2		DB "<=¡ó=>",0
	MonsterB2_3_3		DB "  ¡Ð  ",0
	MonsterB2_3_4		DB "      ",0
	MonsterB2_3_5		DB "      ",0

	DrawMonsterB2 MACRO X, Fram

		Translate X, 13
		.IF (Fram == 1 || Fram == 5)
			GraphDisplay MonsterB2_1_1
			GraphDisplay MonsterB2_1_2
			GraphDisplay MonsterB2_1_3
			GraphDisplay MonsterB2_1_4
			GraphDisplay MonsterB2_1_5
		.ELSEIF  (Fram == 2 || Fram == 4)
			GraphDisplay MonsterB2_2_1
			GraphDisplay MonsterB2_2_2
			GraphDisplay MonsterB2_2_3
			GraphDisplay MonsterB2_2_4
			GraphDisplay MonsterB2_2_5
		.ELSE
			GraphDisplay MonsterB2_3_1
			GraphDisplay MonsterB2_3_2
			GraphDisplay MonsterB2_3_3
			GraphDisplay MonsterB2_3_4
			GraphDisplay MonsterB2_3_5
		.ENDIF
		ENDM
		

		MonsterB3_1_1 		DB "       ",0
		MonsterB3_1_2 		DB "       ",0
		MonsterB3_1_3 		DB "  £Z    ",0
		MonsterB3_1_4 		DB "¡Ù¡ó¡Ø ",0
		MonsterB3_1_5 		DB "  ùÞ  	",0

		MonsterB3_2_1 		DB "       ",0
		MonsterB3_2_2 		DB "  £Z    ",0
		MonsterB3_2_3 		DB "¡Ù¡ó¡Ø ",0
		MonsterB3_2_4 		DB "  ùÞ  	",0
		MonsterB3_2_5 		DB "       ",0

		MonsterB3_3_1 		DB "  £Z    ",0
		MonsterB3_3_2 		DB "¡Ù¡ó¡Ø ",0
		MonsterB3_3_3 		DB "  ùÞ  	",0
		MonsterB3_3_4 		DB "       ",0
		MonsterB3_3_5 		DB "       ",0

	DrawMonsterB3 MACRO X, Fram

		Translate X, 13
		.IF (Fram == 1 || Fram == 5)
			GraphDisplay MonsterB3_1_1
			GraphDisplay MonsterB3_1_2
			GraphDisplay MonsterB3_1_3
			GraphDisplay MonsterB3_1_4
			GraphDisplay MonsterB3_1_5
		.ELSEIF  (Fram == 2 || Fram == 4)
			GraphDisplay MonsterB3_2_1
			GraphDisplay MonsterB3_2_2
			GraphDisplay MonsterB3_2_3
			GraphDisplay MonsterB3_2_4
			GraphDisplay MonsterB3_2_5
		.ELSE
			GraphDisplay MonsterB3_3_1
			GraphDisplay MonsterB3_3_2
			GraphDisplay MonsterB3_3_3
			GraphDisplay MonsterB3_3_4
			GraphDisplay MonsterB3_3_5
		.ENDIF
		ENDM		
		
		
		
		
		
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i             ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i             ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i





	DrawMonsterC	MACRO	Object, Fram
		
		.IF ( Object.Level == 1)
			DrawMonsterC1 Object.X, Fram
		.ELSEIF ( Object.Level == 2)
			DrawMonsterC2 Object.X
		.ELSEIF ( Object.Level == 3)
			DrawMonsterC3 Object.X, Fram
		.ENDIF
		
		ENDM


	MonsterC1_1_1		DB "£»¢p£»  ",0
	MonsterC1_1_2		DB "¢p¢p¢p",0
		

	DrawMonsterC1 MACRO X, Fram

		Translate X, 16

		GraphDisplay MonsterC1_1_1
		GraphDisplay MonsterC1_1_2
		
		ENDM

	MonsterC2_1_1		DB "¡¶    ¡¶  ",0   
	MonsterC2_1_2		DB "¢p¢p¢p¢p",0
	MonsterC2_1_3		DB "¢p£»£»¢p  ",0
	MonsterC2_1_4		DB "        ",0
	MonsterC2_1_5		DB "¢p¢p¢p¢p",0
	
	MonsterC2_2_1		DB "        ",0
	MonsterC2_2_2		DB "¡¶    ¡¶  ",0   
	MonsterC2_2_3		DB "¢p¢p¢p¢p",0
	MonsterC2_2_4		DB "¢p£»£»¢p  ",0
	MonsterC2_2_5		DB "¢p¢p¢p¢p",0

	DrawMonsterC2 MACRO X

		Translate X, 13
		
		.IF ( Beats2x == 1 )
			GraphDisplay MonsterC2_2_1
			GraphDisplay MonsterC2_2_2
			GraphDisplay MonsterC2_2_3
			GraphDisplay MonsterC2_2_4
			GraphDisplay MonsterC2_2_5
		.ELSEIF ( Beats2x == 2 )
			GraphDisplay MonsterC2_1_1
			GraphDisplay MonsterC2_1_2
			GraphDisplay MonsterC2_1_3
			GraphDisplay MonsterC2_1_4
			GraphDisplay MonsterC2_1_5
		.ENDIF
		ENDM


		MonsterC3_1_1		DB "    ¢¬¢@     ",0
		MonsterC3_1_2		DB "  ¢¨¢p¢p¢©  ",0
		MonsterC3_1_3		DB "  ¢p¡¿¡¿¢p      ",0
		MonsterC3_1_4		DB "¢¨¢p£»£»¢p¢©  ",0
		MonsterC3_1_5		DB "¢«¢p¢p¢p¢p¢ª",0
		MonsterC3_1_6		DB "  ¡¿¡¿¡¿¡¿      ",0

		MonsterC3_2_1		DB "    ¢¬¢@     ",0
		MonsterC3_2_2		DB "  ¢¨¢p¢p¢©  ",0
		MonsterC3_2_3		DB "  ¢p¡¿¡¿¢p      ",0
		MonsterC3_2_4		DB "¢p¢p£»£»¢p¢p  ",0
		MonsterC3_2_5		DB "  ¢p¢p¢p¢p  ",0
		MonsterC3_2_6		DB "  ¡¿¡¿¡¿¡¿      ",0

		MonsterC3_3_1		DB "    ¢¬¢@     ",0
		MonsterC3_3_2		DB "  ¢¨¢p¢p¢©  ",0
		MonsterC3_3_3		DB "¢©¢p¡¿¡¿¢p¢¨     ",0
		MonsterC3_3_4		DB "¢ª¢p£»£»¢p¢«",0
		MonsterC3_3_5		DB "  ¢p¢p¢p¢p  ",0
		MonsterC3_3_6		DB "  ¡¿¡¿¡¿¡¿      ",0




	DrawMonsterC3 MACRO X, Fram

		Translate X, 13
		.IF (Fram == 1 || Fram == 5)
			GraphDisplay MonsterC3_1_1
			GraphDisplay MonsterC3_1_2
			GraphDisplay MonsterC3_1_3
			GraphDisplay MonsterC3_1_4
			GraphDisplay MonsterC3_1_5
			GraphDisplay MonsterC3_1_6
		.ELSEIF  (Fram == 2 || Fram == 4)
			GraphDisplay MonsterC3_2_1
			GraphDisplay MonsterC3_2_2
			GraphDisplay MonsterC3_2_3
			GraphDisplay MonsterC3_2_4
			GraphDisplay MonsterC3_2_5
			GraphDisplay MonsterC3_2_6
		.ELSE
			GraphDisplay MonsterC3_3_1
			GraphDisplay MonsterC3_3_2
			GraphDisplay MonsterC3_3_3
			GraphDisplay MonsterC3_3_4
			GraphDisplay MonsterC3_3_5
			GraphDisplay MonsterC3_3_6
		.ENDIF
		ENDM		