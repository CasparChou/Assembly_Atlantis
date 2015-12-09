;███████████████████████████████████████
;This is a file defined Soldier .
;
;EXAMPLE
;	BOY_1_1    DB     "		█████ 	",0
;	BOY_1_2    DB     "		█ 　█　 ",0
;	BOY_1_3    DB     "		█████ 	",0
;	BOY_1_4    DB     "		  █ 	",0
;	BOY_1_5    DB     "		█████ 	",0
;	BOY_1_6    DB     "		  █ 	",0
;	BOY_1_7    DB     "		█████   ",0
;	BOY_1_8    DB     "		 █ █ 	",0
;
;███████████████████████████████████████
.Data

	BOY_1_1    DB     "		IIIII 	",0
	BOY_1_2    DB     "		I   I   ",0
	BOY_1_3    DB     "		IIIII 	",0
	BOY_1_4    DB     "		  I 	",0
	BOY_1_5    DB     "		IIIII 	",0
	BOY_1_6    DB     "		  I 	",0
	BOY_1_7    DB     "		IIIII   ",0
	BOY_1_8    DB     "		 I I 	",0

	DrawSolider MACRO X, Y

		Translate X, Y
		CALL GoToXY

		GraphDisplay BOY_1_1
		GraphDisplay BOY_1_2
		GraphDisplay BOY_1_3
		GraphDisplay BOY_1_4
		GraphDisplay BOY_1_5
		GraphDisplay BOY_1_6
		GraphDisplay BOY_1_7
		GraphDisplay BOY_1_8

		ENDM