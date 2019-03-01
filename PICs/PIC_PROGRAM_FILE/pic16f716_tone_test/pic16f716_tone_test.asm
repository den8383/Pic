; PIC16F716
; for 10MHz clock

; licenced under CC0 1.0
; https://creativecommons.org/publicdomain/zero/1.0/deed.ja

    LIST P=PIC16F716
    INCLUDE "p16f716.inc"
    __CONFIG _FOSC_HS & _BOREN_OFF & _WDTE_OFF & _PWRTE_OFF & _CP_OFF

; port map
PORTB_TONE_OUT EQU 3

; variables map
VAR_WAIT1MS_COUNT EQU 0x20
VAR_SOUND_COUNT EQU 0x21

; program start
    ORG 0
MAIN
    ; use Bank1
    BSF STATUS,RP0
    ; disable interrupts
    BCF INTCON,GIE
    ; port config
    ; set all ports to input
    CLRF TRISA
    CLRF TRISB
    COMF TRISA,F
    COMF TRISB,F
    ; set output ports
    BCF TRISB,PORTB_TONE_OUT
    ; use Bank0
    BCF STATUS,RP0

LOOP
    MOVLW D'200'
    MOVWF VAR_SOUND_COUNT
LOOP_A
    BSF PORTB,PORTB_TONE_OUT
    CALL DELAY_1MS
    BCF PORTB,PORTB_TONE_OUT
    CALL DELAY_1MS
    DECFSZ VAR_SOUND_COUNT,F
    GOTO LOOP_A

    MOVLW D'100'
    MOVWF VAR_SOUND_COUNT
LOOP_B
    BSF PORTB,PORTB_TONE_OUT
    CALL DELAY_1MS
    CALL DELAY_1MS
    BCF PORTB,PORTB_TONE_OUT
    CALL DELAY_1MS
    CALL DELAY_1MS
    DECFSZ VAR_SOUND_COUNT,F
    GOTO LOOP_B

    GOTO LOOP

DELAY_1MS
    ; delay about 1ms
    ; for 10MHz clock
    MOVLW D'249'
    MOVWF VAR_WAIT1MS_COUNT
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
WAIT1MS_LOOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    DECFSZ VAR_WAIT1MS_COUNT,F
    GOTO WAIT1MS_LOOP
    ; delay 1ms end
    RETURN

    END
