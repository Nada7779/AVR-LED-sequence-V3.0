# AVR LED Sequence V3.0 Project
## Project Description:
This is a system that controls some LEDs lighting sequence according to button pressing by using External Interrupts.<br />
The aim of this project is to create [GPIO-LED-BUTTON-EXT_INT-Timer] drivers for ATmega32 Microcontroller.<br />
### Hardware Components
ATmega32 Microcontroller.<br />
Four LEDs (LED0, LED1, LED2, LED3).<br />
Two buttons (BUTTON0 and BUTTON1).<br />
## Project sequence :
Initially, all LEDs are OFF<br />
Once BUTTON0 is pressed, LED0 will blink with BLINK_1 mode<br />
Each press further will make another LED blinks BLINK_1 mode<br />
At the fifth press, LED0 will changed to be OFF<br />
Each press further will make only one LED is OFF<br />
This will be repeated forever<br />
The sequence is described below <br />
Initially (OFF, OFF, OFF, OFF)<br />
Press 1 (BLINK_1, OFF, OFF, OFF)<br />
Press 2 (BLINK_1, BLINK_1, OFF, OFF)<br />
Press 3 (BLINK_1, BLINK_1, BLINK_1, OFF)<br />
Press 4 (BLINK_1, BLINK_1, BLINK_1, BLINK_1)<br />
Press 5 (OFF, BLINK_1, BLINK_1, BLINK_1)<br />
Press 6 (OFF, OFF, BLINK_1, BLINK_1)<br />
Press 7 (OFF, OFF, OFF, BLINK_1)<br />
Press 8 (OFF, OFF, OFF, OFF)<br />
Press 9 (BLINK_1, OFF, OFF, OFF)<br />
When BUTTON1 has pressed the blinking on and off durations will be changed<br />
No press → BLINK_1 mode (ON: 100ms, OFF: 900ms)<br />
First press → BLINK_2 mode (ON: 200ms, OFF: 800ms)<br />
Second press → BLINK_3 mode (ON: 300ms, OFF: 700ms)<br />
Third press → BLINK_4 mode (ON: 500ms, OFF: 500ms)<br />
Fourth  press → BLINK_5 mode (ON: 800ms, OFF: 200ms)<br />
Fifth press → BLINK_1 mode<br />
