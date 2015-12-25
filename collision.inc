;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;						;;;;
;;;;	   collision 	    ;;;;
;;;;						;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.DATA
Compare_S 	DWORD 	?
Compare_M	DWORD 	?

collision	MACRO	S_num, M_num, Check
	PUSHA
		GettingSoldierX		UserSoldiers,S_num,GetterHandler
		CopyFrom		Compare_S,GetterHandler
		GettingSoldierX	CompSoldiers,M_num,GetterHandler
		CopyFrom 		Compare_M,GetterHandler

		mov		eax,Compare_S
		mov		ecx,Compare_M
		.IF		eax != 0 && ecx !=0
			.IF		eax ==  ecx	
			CopyFrom	Check,1
			.ElSE
			CopyFrom	Check,0
			.ENDIF
			WriteD			GetterHandler
		.ENDIF
	POPA
	ENDM	
