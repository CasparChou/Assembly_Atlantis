;¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
;This is a file defined Soldier .
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



	Soldier_1_1_1		DB	"£»  ",0
	Soldier_1_1_2		DB	"¢p¡÷ ",0
	Soldier_1_1_3		DB	"£J  ",0

	Soldier_1_2_1		DB	"£» ",0
	Soldier_1_2_2		DB	"¢p¡÷",0
	Soldier_1_2_3		DB	"¢Ï",0

	DrawSoilder MACRO X, Fram

		Translate X, 15
		.IF (Fram == 1)
			GraphDisplay Soldier_1_1_1
			GraphDisplay Soldier_1_1_2
			GraphDisplay Soldier_1_1_3
		.ELSEIF (Fram == 2)
			GraphDisplay Soldier_1_2_1
			GraphDisplay Soldier_1_2_2
			GraphDisplay Soldier_1_2_3
		.ENDIF
		ENDM
		
		
		
		
		
		