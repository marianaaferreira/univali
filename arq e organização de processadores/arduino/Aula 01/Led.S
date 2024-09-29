; Assembly Code Used to toggle the On-Board LED on Pin 13 (PB5). 
; https://www.rkessler.com/UCI/StudyGroup/Lessons/Lesson11/UNO_BoardAssembly/ALL%20ABOUT%20ARDUINO%20ASSEMBLY%20PROGRAMMING.pdf
; https://akuzechie.blogspot.com/2021/09/assembly-programming-via-arduino-uno.html
; Tells where to start storing code in IO registers.

#define __SFR_OFFSET 0x00      

;This is used to upload code to the UNO using AVRDUDE which comes with the IDE.
#include "avr/io.h"  
           
                              ;Declare global variables so it can be accessed from INO code. 

.global start                 
.global led

;------------------------------------------------------------------------------------------- 
start: 
SBI   DDRB, 5              
    ;SBI(Set Bit in IO Register) sets PB5 (D13) to output mode so we can write. 
RET                        
    ;return to setup() function 
;------------------------------------------------------------------------------------------- 
                              ;The argument sent to led()in the INO code is stored in R24.

led:                                
  CPI   R24, 0x00              
                              ;CPI(Compare I/O bit) to 0     
  BREQ  ledOFF           
                              ;If R24 is equal to 0 jump to subroutine ledOFF
  SBI   PORTB, 5 
                              ;SBI (Set Bit in IO Register) D13 to high   
  RCALL myDelay  
  RET

ledOFF:    
  CBI   PORTB, 5             ;set D13 to low 
  RCALL myDelay  
  RET                       
;return to loop() function

;-------------------------------------------------------------------------------------------
.equ  delayVal, 10000        ;initial count value for inner loop
;-------------------------------------------------------------------------------------------
myDelay:
  LDI   R20, 100            ;initial count value for outer loop
outerLoop:
  LDI   R30, lo8(delayVal)  ;low byte of delayVal in R30
  LDI   R31, hi8(delayVal)  ;high byte of delayVal in R31
innerLoop:
  SBIW  R30, 1              ;subtract 1 from 16-bit value in R31, R30
  BRNE  innerLoop           ;jump if countVal not equal to 0
  ;--------------
  SUBI  R20, 1              ;subtract 1 from R20
  BRNE  outerLoop           ;jump if R20 not equal to 0
  RET
;-------------------------------------------------------------------------------------------
