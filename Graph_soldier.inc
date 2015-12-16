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
			
		
	SoldierA2_1_1		DB	"£N  ",0
	SoldierA2_1_2		DB	"¢pù÷",0
	SoldierA2_1_3		DB	"£S  ",0
           
	SoldierA2_2_1		DB	"£N  ",0
	SoldierA2_2_2		DB	"¢pù÷",0
	SoldierA2_2_3		DB	"I  ",0

	DrawSoilderB1 MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay SoldierA2_1_1
			GraphDisplay SoldierA2_1_2
			GraphDisplay SoldierA2_1_3
		.ELSEIF (Fram == 2)
			GraphDisplay SoldierA2_2_1
			GraphDisplay SoldierA2_2_2
			GraphDisplay SoldierA2_2_3
		.ENDIF
		ENDM
		
		
	SoldierA3_1_1		DB	"  £Z ",0
	SoldierA3_1_2		DB	"£X¢p£X",0
	SoldierA3_1_3		DB	"  £S ",0
	        
	SoldierA3_2_1		DB	"  £Z ",0
	SoldierA3_2_2		DB	"£X¢p¢Ç",0
	SoldierA3_2_3		DB	"  I ",0
	        
	SoldierA3_3_1		DB	"  £Z ",0
	SoldierA3_3_2		DB	"£X¢p¢Ç",0
	SoldierA3_3_3		DB	"  £S ",0
	        
	SoldierA3_4_1		DB	"  £Z ",0
	SoldierA3_4_2		DB	"¢Ç¢p£X",0
	SoldierA3_4_3		DB	"  I ",0
    
	DrawSoilderA3 MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay SoldierA3_1_1
			GraphDisplay SoldierA3_1_2
			GraphDisplay SoldierA3_1_3
		.ELSEIF (Fram == 2)    
			GraphDisplay SoldierA3_2_1
			GraphDisplay SoldierA3_2_2
			GraphDisplay SoldierA3_2_3
		.ELSEIF (Fram == 3)     
			GraphDisplay SoldierA3_3_1
			GraphDisplay SoldierA3_3_2
			GraphDisplay SoldierA3_3_3
		.ELSEIF (Fram == 4)     
			GraphDisplay SoldierA3_4_1
			GraphDisplay SoldierA3_4_2
			GraphDisplay SoldierA3_4_3
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

