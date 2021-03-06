

	ORG	0000H
	LJMP	MAIN

	ORG	0003H
	LJMP	INT0_ISR

 	ORG	000BH
	LJMP	TIMER0_ISR

	ORG	0013H
	LJMP	INT1_ISR

	ORG	001BH
	LJMP	TIMER1_ISR

	        
///////////////////////////////////////////	
ORG	0033H
DB	0FFH,0FFH,0FFH,0FFH,0FFH,0FFH
///////////////////////////////////////////	
	ORG	0100H
MAIN:
	MOV	SP,	#0C0H

	LCALL	SYSTEM_INITIAL

MAIN_LOOP:
	LCALL	DISPLAY_ROUTINE

	LCALL	KEY_SCAN
	
	LCALL	FUNCTION_CONTROL
	
	SJMP	MAIN_LOOP

SYSTEM_INITIAL:
 	CLR   	PX0      ;PRIORITY  0 
	;SETB   	PX0    ;PRIORITY  1

 	;CLR   	IT0       
	SETB   	IT0

	
	SETB	EX0	;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 	;CLR   	PX1      ;PRIORITY  0 
	SETB   	PX1    ;PRIORITY  1

        CLR   	IT1
	;SETB	IT1

	
	SETB	EX1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	MOV	TMOD,	#00100001B;  GATE C/T M1 M0  GATE C/T M1 M0 0010,0001
				  ;  TIMER1 MODE 2,8-BIT Reload;   TIMER0 MODE 1,16-bit timer
 
	MOV	TH1,	#(256-200)
	MOV	TL1,	#(256-200)
	SETB	ET1
	SETB	TR1




	SETB	EA	;NOP

	RET


INT0_ISR:
	NOP
	
	CLR	P1.2;  //X0 P3.2
	
	NOP
	NOP
	NOP
	
	SETB	P1.2
	
	NOP
	RETI
	
INT1_ISR:
	NOP
	
	CLR	P1.3;  //X0 P3.3
	
	NOP
	NOP
	NOP
	
	SETB	P1.3
	
	NOP
	RETI

TIMER0_ISR:

	NOP
	NOP
	RETI

TIMER1_ISR:

	CLR	P3.5
	NOP
	NOP
	NOP
	SETB	P3.5
	NOP
	NOP
	RETI

DISPLAY_ROUTINE:
	NOP
	NOP
	NOP
	RET

KEY_SCAN:
	NOP
	NOP
	NOP
	RET	
	
FUNCTION_CONTROL:
	NOP
	NOP
	NOP
	RET


	END
