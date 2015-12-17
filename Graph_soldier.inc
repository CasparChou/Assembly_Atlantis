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


	SoldierA1_1_1		DB	"£»  ",0
	SoldierA1_1_2		DB	"¢p¡÷ ",0
	SoldierA1_1_3		DB	"£J  ",0	
           
	SoldierA1_2_1		DB	"£» ",0
	SoldierA1_2_2		DB	"¢p¡÷",0
	SoldierA1_2_3		DB	"¢Ï",0

	DrawSoilderA1 MACRO X, Fram
		
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


	DrawSoilderB	MACRO X, Fram
		
		.IF ( CurrLevel == 1)
			DrawSoilderB1 X, Fram
		.ELSEIF ( CurrLevel == 2)
			DrawSoilderB2 X, Fram
		.ELSEIF ( CurrLevel == 3)
			DrawSoilderB3 X, Fram
		.ENDIF
		
		ENDM
	


	SoldierB1_1_1		DB	"£N  ",0
	SoldierB1_1_2		DB	"¢pù÷",0
	SoldierB1_1_3		DB	"£S  ",0
            
	SoldierB1_2_1		DB	"£N  ",0
	SoldierB1_2_2		DB	"¢pù÷",0
	SoldierB1_2_3		DB	"I  ",0

	DrawSoilderB1 MACRO X, Fram

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


	DrawSoilderB2 MACRO X, Fram

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
    
	DrawSoilderB3 MACRO X, Fram

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

