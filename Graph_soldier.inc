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



	DrawSoldierA	MACRO Object, Fram
	
		.IF ( Object.Level == 1)
			DrawSoldierA1 Object.X, Fram
		.ELSEIF ( Object.Level == 2)
			DrawSoldierA2 Object.X, Fram
		.ELSEIF ( Object.Level == 3)
			DrawSoldierA3 Object.X, Fram
		.ENDIF
		
		ENDM
	



	SoldierA1_1_1		DB	"£»  ",0
	SoldierA1_1_2		DB	"¢p¡÷ ",0
	SoldierA1_1_3		DB	"£J  ",0	
           
	SoldierA1_2_1		DB	"£» ",0
	SoldierA1_2_2		DB	"¢p¡÷",0
	SoldierA1_2_3		DB	"¢Ï",0

	DrawSoldierA1 MACRO X, Fram
		
		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay SoldierA1_1_1
			GraphDisplay SoldierA1_1_2
			GraphDisplay SoldierA1_1_3
		.ELSEIF (Fram == 2)
			GraphDisplay SoldierA1_2_1
			GraphDisplay SoldierA1_2_2
			GraphDisplay SoldierA1_2_3
		.ENDIF
		
		ENDM

	SoldierA2_1_1		DB "    £K     ",0
	SoldierA2_1_2		DB "¡ø¢p¢p¢p¡ù",0
	SoldierA2_1_3		DB "  ¢ª¢f¢«  ",0
	SoldierA2_1_4		DB "    £J     ",0


	DrawSoldierA2 MACRO X, Fram
		
		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay SoldierA2_1_1
			GraphDisplay SoldierA2_1_2
			GraphDisplay SoldierA2_1_3
			GraphDisplay SoldierA2_1_4
		.ELSEIF (Fram == 2)
			GraphDisplay SoldierA2_1_1
			GraphDisplay SoldierA2_1_2
			GraphDisplay SoldierA2_1_3
			GraphDisplay SoldierA2_1_4
		.ENDIF
		
		ENDM
	
	SoldierA3_1_1 		DB "      ¡¿       ",0
	SoldierA3_1_2 		DB "¢ª¢©¢p¢p¢p¢¨¢«",0
	SoldierA3_1_3 		DB "  ¢ªù÷¢pùõ¢«    ",0
	SoldierA3_1_4 		DB "     ¡¶¡¶       ",0

	DrawSoldierA3 MACRO X, Fram
		
		Translate X, 14
		.IF (Fram == 1)
			GraphDisplay SoldierA3_1_1
			GraphDisplay SoldierA3_1_2
			GraphDisplay SoldierA3_1_3
			GraphDisplay SoldierA3_1_4
		.ELSEIF (Fram == 2)
			GraphDisplay SoldierA3_1_1
			GraphDisplay SoldierA3_1_2
			GraphDisplay SoldierA3_1_3
			GraphDisplay SoldierA3_1_4
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


	DrawSoldierB	MACRO Object, Fram
	
		.IF ( Object.Level == 1)
			DrawSoldierB1 Object.X, Fram
		.ELSEIF ( Object.Level == 2)
			DrawSoldierB2 Object.X, Fram
		.ELSEIF ( Object.Level == 3)
			DrawSoldierB3 Object.X, Fram
		.ENDIF
		
		ENDM
	


	SoldierB1_1_1		DB	"£N  ",0
	SoldierB1_1_2		DB	"¢pù÷",0
	SoldierB1_1_3		DB	"£S  ",0
            
	SoldierB1_2_1		DB	"£N  ",0
	SoldierB1_2_2		DB	"¢pù÷",0
	SoldierB1_2_3		DB	"¢æ  ",0

	DrawSoldierB1 MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay SoldierB1_1_1
			GraphDisplay SoldierB1_1_2
			GraphDisplay SoldierB1_1_3
		.ELSEIF (Fram == 2)     
			GraphDisplay SoldierB1_2_1
			GraphDisplay SoldierB1_2_2
			GraphDisplay SoldierB1_2_3
		.ENDIF
		ENDM
		
	SoldierB2_1_1		DB	" £[  ",0
	SoldierB2_1_2		DB	" ¢pù÷",0
	SoldierB2_1_3		DB	" £J  ",0
	
	SoldierB2_2_1		DB	" £[  ",0
	SoldierB2_2_2		DB	" ¢pù÷",0
	SoldierB2_2_3		DB	" I  ",0


	DrawSoldierB2 MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay SoldierB2_1_1
			GraphDisplay SoldierB2_1_2
			GraphDisplay SoldierB2_1_3
		.ELSEIF (Fram == 2)     
			GraphDisplay SoldierB2_2_1
			GraphDisplay SoldierB2_2_2
			GraphDisplay SoldierB2_2_3
		.ENDIF
		ENDM
		
		
	SoldierB3_1_1		DB	"  £Z ",0
	SoldierB3_1_2		DB	"£X¢p£X",0
	SoldierB3_1_3		DB	"  £S ",0
	       
	SoldierB3_2_1		DB	"  £Z ",0
	SoldierB3_2_2		DB	"£X¢p¢Ç",0
	SoldierB3_2_3		DB	"  I ",0
	       
	SoldierB3_3_1		DB	"  £Z ",0
	SoldierB3_3_2		DB	"£X¢p¢Ç",0
	SoldierB3_3_3		DB	"  £S ",0
	       
	SoldierB3_4_1		DB	"  £Z ",0
	SoldierB3_4_2		DB	"¢Ç¢p£X",0
	SoldierB3_4_3		DB	"  I ",0
    
	DrawSoldierB3 MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay SoldierB3_1_1
			GraphDisplay SoldierB3_1_2
			GraphDisplay SoldierB3_1_3
		.ELSEIF (Fram == 2)     
			GraphDisplay SoldierB3_2_1
			GraphDisplay SoldierB3_2_2
			GraphDisplay SoldierB3_2_3
		.ELSEIF (Fram == 3)     
			GraphDisplay SoldierB3_3_1
			GraphDisplay SoldierB3_3_2
			GraphDisplay SoldierB3_3_3
		.ELSEIF (Fram == 4)     
			GraphDisplay SoldierB3_4_1
			GraphDisplay SoldierB3_4_2
			GraphDisplay SoldierB3_4_3
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



	DrawSoldierC	MACRO Object, Fram
		.IF ( Object.Level == 1)
			DrawSoldierC1 Object.X, Fram
		.ELSEIF ( Object.Level == 2)
			DrawSoldierC2 Object.X, Fram
		.ELSEIF ( Object.Level == 3)
			DrawSoldierC3 Object.X, Fram
		.ENDIF
		
		ENDM



		SoldierC1_1_1	DB "  £»£»  ",0
		SoldierC1_1_2	DB "¡i¢p¢p¡j",0
		SoldierC1_1_3	DB "  ¡ä¡ä  ",0
		
		SoldierC1_2_1	DB "  ¢â  ",0
		SoldierC1_2_2	DB "¡i¢p¢p¡j",0
		SoldierC1_2_3	DB "  ¡ä¡ä  ",0
		
		SoldierC1_3_1	DB "    ¢â  ",0
		SoldierC1_3_2	DB "¡i¢p¢p¡j",0
		SoldierC1_3_3	DB "  ¡ä¡ä  ",0
		
		SoldierC1_4_1	DB "  ¢â¢â  ",0
		SoldierC1_4_2	DB "¡i¢p¢p¡j",0
		SoldierC1_4_3	DB "  ¡ä¡ä  ",0

		DrawSoldierC1 MACRO X, Fram

			Translate X, 15
			.IF (Fram == 1)
				GraphDisplay SoldierC1_1_1
				GraphDisplay SoldierC1_1_2
				GraphDisplay SoldierC1_1_3
			.ELSEIF (Fram == 2)     
				GraphDisplay SoldierC1_2_1
				GraphDisplay SoldierC1_2_2
				GraphDisplay SoldierC1_2_3
			.ELSEIF (Fram == 3)     
				GraphDisplay SoldierC1_3_1
				GraphDisplay SoldierC1_3_2
				GraphDisplay SoldierC1_3_3
			.ELSEIF (Fram == 4)     
				GraphDisplay SoldierC1_4_1
				GraphDisplay SoldierC1_4_2
				GraphDisplay SoldierC1_4_3
			.ENDIF
			ENDM
			
		
		SoldierC2_1_1	DB "  ¡¶¡¶  ",0
		SoldierC2_1_2	DB "¢¨¢p¢p¢©",0
		SoldierC2_1_3	DB "¡i£»£»¡j ",0
		SoldierC2_1_4	DB "  ¢E¢E ",0
		
		DrawSoldierC2 MACRO X, Fram

			Translate X, 14
			
			GraphDisplay SoldierC2_1_1
			GraphDisplay SoldierC2_1_2
			GraphDisplay SoldierC2_1_3
			GraphDisplay SoldierC2_1_4
			
			ENDM

		SoldierC3_1_1 	DB "  ¢¨¢©   ",0
		SoldierC3_1_2 	DB "¢¨£»£»¢© ",0
		SoldierC3_1_3 	DB "¡i¢p¢p¡j  ",0
		SoldierC3_1_4 	DB "  ¢p¢p   ",0
		SoldierC3_1_5 	DB "  ¡¶¡¶    ",0
  
 		
		DrawSoldierC3 MACRO X, Fram

			Translate X, 13
				GraphDisplay SoldierC3_1_1
				GraphDisplay SoldierC3_1_2
				GraphDisplay SoldierC3_1_3
				GraphDisplay SoldierC3_1_4
				GraphDisplay SoldierC3_1_5
			ENDM 
  
  
  