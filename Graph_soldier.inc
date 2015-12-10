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
	BOY_1_1    DB     "¢i¢i¢i",0
	BOY_1_2    DB     "¢i¢i¢i",0
	BOY_1_3    DB     "¢i¢i¢i",0
	BOY_1_4    DB     "  ¢i",0
	BOY_1_5    DB     "  ¢i",0
	BOY_1_6    DB     "  ¢i",0
	BOY_1_7    DB     "  ¢i",0



	DrawSolider MACRO X, Y

		Translate X, Y

		GraphDisplay BOY_1_1
		GraphDisplay BOY_1_2
		GraphDisplay BOY_1_3
		GraphDisplay BOY_1_4
		GraphDisplay BOY_1_5
		GraphDisplay BOY_1_6
		GraphDisplay BOY_1_7

		ENDM