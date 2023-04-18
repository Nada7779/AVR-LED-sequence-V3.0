/*
 * application.h
 *
 * Created: 4/8/2023 10:08:38 AM
 *  Author: Nada
 */ 

#include "application.h"

// Macros
#define Number_of_sequence 8
#define Number_of_modes    5
// Variables
uint8_t sequence= 0;
uint8_t mode    = 1;

void APP_init(void)
{
	// LEDs init
	LED_init(led_1_port, led_1_pin);
	LED_init(led_2_port, led_2_pin);
	LED_init(led_3_port, led_3_pin);
	LED_init(led_4_port, led_4_pin);
	// button init
	Button_init(BUTTON_1_PORT, BUTTON_1_PIN);
	Button_init(BUTTON_2_PORT, BUTTON_2_PIN);
	// Enable global interrupts
	Global_interrupt_enable ();
	// Choose the external interrupt 0 sense - sense in rising edge
	External_interrupt0_mode (rising_edge);
	// Enable External interrupt 0 - INT0
	Exit_enable0 ();
    // Choose the external interrupt 1 sense - sense in rising edge
    External_interrupt1_mode (rising_edge);
    // Enable External interrupt 1 - INT1
    Exit_enable1 ();
}
void APP_start(void){
	while(1)
	{
		switch (mode){
			case 1:
			       BLINK_1_mode();
				   break;
			case 2:
			       BLINK_2_mode();
			       break;
			case 3:
			       BLINK_3_mode();
			       break;
			case 4:
			       BLINK_4_mode();
			       break;
			case 5:
			       BLINK_5_mode();
			       break;				   
		}
		
	
	}
}

ISR (EXT_INT_0)
{
	
	if (sequence < Number_of_sequence)
	{
		sequence++;
	}
	else
	{
		sequence = 1;
	}
}
ISR (EXT_INT_1)
{
	
	if (mode < Number_of_modes)
	{
		mode++;
	}
	else
	{
		mode = 1;
	}
}

void BLINK_1_mode (void)
{
	//ON: 100ms, OFF: 900ms
	if (sequence>0 && sequence<5)LED_on(led_1_port,led_1_pin);
	if (sequence>1 && sequence<6) LED_on(led_2_port,led_2_pin);
	if (sequence>2 && sequence<7) LED_on(led_3_port,led_3_pin);
	if (sequence>3 && sequence<8) LED_on(led_4_port,led_4_pin);
	delay_ms(100);
	LED_off(led_1_port,led_1_pin);
	LED_off(led_2_port,led_2_pin);
	LED_off(led_3_port,led_3_pin);
	LED_off(led_4_port,led_4_pin);
	delay_ms(900);
}
void BLINK_2_mode (void)
{
	//ON: 100ms, OFF: 900ms
	if (sequence>0 && sequence<5)LED_on(led_1_port,led_1_pin);
	if (sequence>1 && sequence<6) LED_on(led_2_port,led_2_pin);
	if (sequence>2 && sequence<7) LED_on(led_3_port,led_3_pin);
	if (sequence>3 && sequence<8) LED_on(led_4_port,led_4_pin);
	delay_ms(200);
	LED_off(led_1_port,led_1_pin);
	LED_off(led_2_port,led_2_pin);
	LED_off(led_3_port,led_3_pin);
	LED_off(led_4_port,led_4_pin);
	delay_ms(800);
}
void BLINK_3_mode (void)
{
	//ON: 100ms, OFF: 900ms
	if (sequence>0 && sequence<5)LED_on(led_1_port,led_1_pin);
	if (sequence>1 && sequence<6) LED_on(led_2_port,led_2_pin);
	if (sequence>2 && sequence<7) LED_on(led_3_port,led_3_pin);
	if (sequence>3 && sequence<8) LED_on(led_4_port,led_4_pin);
	delay_ms(300);
	LED_off(led_1_port,led_1_pin);
	LED_off(led_2_port,led_2_pin);
	LED_off(led_3_port,led_3_pin);
	LED_off(led_4_port,led_4_pin);
	delay_ms(700);
}
void BLINK_4_mode (void)
{
	//ON: 100ms, OFF: 900ms
	if (sequence>0 && sequence<5)LED_on(led_1_port,led_1_pin);
	if (sequence>1 && sequence<6) LED_on(led_2_port,led_2_pin);
	if (sequence>2 && sequence<7) LED_on(led_3_port,led_3_pin);
	if (sequence>3 && sequence<8) LED_on(led_4_port,led_4_pin);
	delay_ms(500);
	LED_off(led_1_port,led_1_pin);
	LED_off(led_2_port,led_2_pin);
	LED_off(led_3_port,led_3_pin);
	LED_off(led_4_port,led_4_pin);
	delay_ms(500);
}
void BLINK_5_mode (void)
{
	//ON: 100ms, OFF: 900ms
	if (sequence>0 && sequence<5)LED_on(led_1_port,led_1_pin);
	if (sequence>1 && sequence<6) LED_on(led_2_port,led_2_pin);
	if (sequence>2 && sequence<7) LED_on(led_3_port,led_3_pin);
	if (sequence>3 && sequence<8) LED_on(led_4_port,led_4_pin);
	delay_ms(800);
	LED_off(led_1_port,led_1_pin);
	LED_off(led_2_port,led_2_pin);
	LED_off(led_3_port,led_3_pin);
	LED_off(led_4_port,led_4_pin);
	delay_ms(200);
}		
		
