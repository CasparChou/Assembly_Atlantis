;	Version 3
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;This is a file defined Turrent .
;
;EXAMPLE
;	Turrent_1_1    DB     "	  ¢i¢i¢i¢i	 	",0
;	Turrent_1_2    DB     "	¢i¢i	  ¢i¢i 	",0
;	Turrent_1_3    DB     "	  ¢i¢i    ¢i¢i	",0
;	Turrent_1_4    DB     "		¢i¢i	  ¢i¢i",0
;	Turrent_1_5    DB     "		¢i ¢i¢i¢i¢i¢i¢i",0
;	Turrent_1_6    DB     "		¢i 		",0
;	Turrent_1_7    DB     "		¢i  		",0
;
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i

.Data

	Turrent_1_1 	DB "  ¡ï ",0
	Turrent_1_2 	DB "  ¢i ",0
	Turrent_1_3 	DB "  ¢i ",0
	Turrent_1_4		DB "¡¶¡¿¡¶ ",0

	DrawTurrent MACRO X, Y

		Translate X, Y

		GraphDisplay Turrent_1_1
		GraphDisplay Turrent_1_2
		GraphDisplay Turrent_1_3
		GraphDisplay Turrent_1_4

		ENDM