#define __PROG_TYPES_COMPAT__
#define F_CPU 16000000L

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "china_lcd.h"
#include "uart.h"
#include "clock.h"
#include "FrameGraphics.h"
#include "GlobalDefines.h"

 unsigned char x = 0;
 int milliseconds = 0;
 char seconds = 0;
 char minutes = 0;
 char hours = 0;

ISR (TIMER2_COMPA_vect)
{
	x++;
	if(x == 16)
	{
		x = 0;
		milliseconds++;
		if(milliseconds == 1000)
		{
			milliseconds = 0;
			seconds++;
			if(seconds == 60)
			{
				minutes++;
				if(minutes == 60)
				{
					hours = (hours + 1) % 24;
				}
			}
		}

	}
}

void initTime()
{
    OCR2A = 62;

    TCCR2A |= (1 << WGM21);
    // Set to CTC Mode

    TIMSK2 |= (1 << OCIE2A);
    //Set interrupt on compare match

    TCCR2B |= (1 << CS21);
    // set prescaler to 64 and starts PWM

    sei();
    // enable interrupts

}


void myDelay(int16_t ms);

int main(void)
{
	// init the 1.8 lcd display
	init();
	constructor(_width, _height);
	fillScreen(BackGroundColor);
	drawFrame();
	drawTime(0,0);
	drawBluetoothConnected(0);
	drawBattery(50);
	initTime();
	initUART();
	drawCircle(_width / 2, _height / 2, _width / 2 - 26, ForeGroundColor);
	int drawnminutes = 0;
	int drawnhours = 0;
	while (1)
	{
		if(byteAvailable())
		{
			print(readString());
		}
		if(drawnminutes != seconds || drawnhours != minutes)
		{
			drawnminutes = seconds;
			drawnhours = minutes;
			drawClock(seconds, minutes);
			//drawTime(seconds,minutes);
		}
	}

	return 0;
}
