;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;This is a file defined Monster .
;
;EXAMPLE
;	BOY_1_1    DB     "¢i¢i¢i¢i¢i¢i¢i¡@     ",0
;	BOY_1_2    DB     "¢i          ¢i  ",0
;	BOY_1_3    DB     "¢i  ¢i  ¢i  ¢i    ",0
;	BOY_1_4    DB     "¢i    ¢i    ¢i¡@ ",0
;	BOY_1_5    DB     "¢i          ¢i  ",0
;	BOY_1_6    DB     "¢i¢i¢i¢i¢i¢i¢i       ",0
;	BOY_1_7    DB     "      ¢i 	     ",0
;	BOY_1_8    DB     "      ¢i 	     ",0
;	BOY_1_9    DB     "      ¢i 	     ",0
;	BOY_1_10    DB    "  ¢i¢i¢i¢i¢i       ",0
;	BOY_1_11   DB     "  ¢i      ¢i    ",0
;
;
;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
.Data

	Monster_1_1_1    	DB     	"    ",0
	Monster_1_1_2    	DB     	"    ",0
	Monster_1_1_3   	DB     	"=¡ó=",0
	
	Monster_1_2_1    	DB     	"    ",0
	Monster_1_2_2    	DB     	"=¡ó=",0
	Monster_1_2_3    	DB     	"    ",0
	
	Monster_1_3_1    	DB     	"=¡ó=",0
	Monster_1_3_2    	DB     	"    ",0
	Monster_1_3_3    	DB     	"    ",0
		
	Monster_2_1		DB 		"  ¡å    ",0
	Monster_2_2		DB 		"<=¡ó=> ",0
	Monster_2_3		DB 		"  ¡Ð   ",0
	
	
	
	
	;Monster_2_1    DB     "",0
	;Monster_2_2    DB     "¢i¢i¢i",0
	;Monster_2_3    DB     "¢i¢i¢i",0
	;Monster_2_4    DB     "  ¢i",0
	;Monster_2_5    DB     "  ¢i",0
	;Monster_2_6    DB     "  ¢i",0
	;Monster_2_7    DB     "  ¢i",0


	DrawMonster MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1 || Fram == 5)
			GraphDisplay Monster_1_1_1
			GraphDisplay Monster_1_1_2
			GraphDisplay Monster_1_1_3
		.ELSEIF  (Fram == 2 || Fram == 4)
			GraphDisplay Monster_1_2_1
			GraphDisplay Monster_1_2_2
			GraphDisplay Monster_1_2_3
		.ELSE
			GraphDisplay Monster_1_3_1
			GraphDisplay Monster_1_3_2
			GraphDisplay Monster_1_3_3
		.ENDIF
		ENDM

	DrawMonster2 MACRO X

		Translate X, 15

		GraphDisplay Monster_2_1
		GraphDisplay Monster_2_2
		GraphDisplay Monster_2_3

		ENDM
		
		
		
		
		