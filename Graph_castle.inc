;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;This is a file defined Castle .
;
;EXAMPLE
;	BOX_1_1    DB     "¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i",0
;	BOX_1_2    DB     "¢i¡@¢i¡@¡@¡@¢i¡@¢i",0
;	BOX_1_3    DB     "¢i¡@¢i¢i¢i¢i¢i¢i¢i¢i¡@¢i",0
;	BOX_1_4    DB     "¢i¡@¢i¡@¡@¡@¢i¡@¢i",0
;	BOX_1_5    DB     "¢i¡@¢i¢i¢i¢i¢i¢i¢i¢i¡@¢i",0
;	BOX_1_6    DB     "¢i¡@¢i¡@¡@¡@¢i¡@¢i",0
;	BOX_1_7    DB     "¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i",0
;
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i

.Data



	Castle_1_1    	DB     "      ¢i  ¢i      ",0
	Castle_1_2    	DB     "    ¢i¢i¢i¢i¢i       ",0
	Castle_1_3    	DB     "    ¢i¢«  ¢ª¢i    ",0
	Castle_1_4    	DB     "    ¢i      ¢i    ",0
	Castle_1_5    	DB     "¢d¢d¢i      ¢i¢d¢d",0
	
	Castle_2_1    	DB     "         ¢«    ",0
	Castle_2_2    	DB     "         ¢k      ",0
	Castle_2_3    	DB     "        ¢i        ",0
	Castle_2_4    	DB     "      ¢i¢i¢i        ",0
	Castle_2_5    	DB     "    ¢i¢i¢i¢i¢i        ",0
	Castle_2_6    	DB     "    ¢i¢«  ¢ª¢i     ",0
	Castle_2_7    	DB     "  ¢i¢i      ¢i¢i     ",0
	Castle_2_8    	DB     "¢d¢i¢i      ¢i¢i¢d   ",0
	
	Castle_3_1 		DB	   "         ¢«      ",0
	Castle_3_2 		DB	   "     ¢«  ¢k  ¢«  ",0
	Castle_3_3 		DB	   "     ¢k ¡¶   ¢k   ",0
	Castle_3_4 		DB	   "    ¡¶  ¢i  ¡¶      ",0
	Castle_3_5 		DB	   "    ¢i¢i¢i¢i¢i        ",0
	Castle_3_6 		DB	   "    ¢i¢i¢i¢i¢i        ",0
	Castle_3_7 		DB	   "¡¶  ¢i¢«  ¢ª¢i  ¡¶   ",0
	Castle_3_8 		DB	   "¢i¢i¢i      ¢i¢i¢i     ",0
	Castle_3_9 		DB	   "¢i¢i¢i      ¢i¢i¢i     ",0

	DrawCastle MACRO X, Y

		Translate X, Y

		GraphDisplay Castle_1_1
		GraphDisplay Castle_1_2
		GraphDisplay Castle_1_3
		GraphDisplay Castle_1_4
		GraphDisplay Castle_1_5

		ENDM
	
	DrawCastle2 MACRO X, Y

		Translate X, Y

		GraphDisplay Castle_2_1
		GraphDisplay Castle_2_2
		GraphDisplay Castle_2_3
		GraphDisplay Castle_2_4
		GraphDisplay Castle_2_5
		GraphDisplay Castle_2_6
		GraphDisplay Castle_2_7
		GraphDisplay Castle_2_8

		ENDM
		
	DrawCastle3 MACRO X, Y

		Translate X, Y

		GraphDisplay Castle_3_1
		GraphDisplay Castle_3_2
		GraphDisplay Castle_3_3
		GraphDisplay Castle_3_4
		GraphDisplay Castle_3_5
		GraphDisplay Castle_3_6
		GraphDisplay Castle_3_7
		GraphDisplay Castle_3_8
		GraphDisplay Castle_3_9

		ENDM