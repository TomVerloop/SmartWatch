#define __PROG_TYPES_COMPAT__
#define F_CPU 16000000L
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <math.h>
#include "china_lcd.h"
#include "uart.h"
#include "clock.h"

#define BackGroundColor ST7735_BLACK
#define ForeGroundColor ST7735_GREEN

void myDelay(int16_t ms);

void drawClock(int Seconds, int Minutes)
{
	static int seconds = 0;
	static int minutes = 0;

	draw_arm((_width / 2), (_height / 2), seconds, _width / 2 - 30,
	BackGroundColor);

	draw_arm((_width / 2), (_height / 2), minutes, _width / 2 - 40,
	BackGroundColor);
	seconds = Seconds;
	minutes = Minutes;
	draw_arm((_width / 2), (_height / 2), seconds, _width / 2 - 30,
	ForeGroundColor);

	draw_arm((_width / 2), (_height / 2), minutes, _width / 2 - 40,
	ForeGroundColor);
}

void drawFrame()
{
	drawLine(30, 20, _width - 5, 20, ForeGroundColor);
	drawLine(5, 45, 30, 20, ForeGroundColor);
	drawLine(5, 45, 5, _height - 30, ForeGroundColor);
	drawLine(5, _height - 30, _width / 2 + 10, _height - 30, ForeGroundColor);
	drawLine(_width / 2 + 10, _height - 30, _width / 2 + 10, _height - 5,
	ForeGroundColor);
	drawLine(_width / 2 + 10, _height - 5, _width - 5, _height - 5,
	ForeGroundColor);

	drawLine(_width - 5, _height - 5, _width - 5, 20, ForeGroundColor);

}

void drawTime()
{
	setTextColor(ForeGroundColor, BackGroundColor);
	setTextSize(2);
	setCursor(10, _height - 22);
	print("00:00");
}

void drawBluetoothConnected(uint8_t connected)
{
	drawRect(_width - 5, 4, _width - 15, 16, BackGroundColor);
	drawLine(_width - 10, 4, _width - 10, 16, ST7735_BLUE);
	drawLine(_width - 10, 4, _width - 7, 7, ST7735_BLUE);
	drawLine(_width - 7, 7, _width - 13, 13, ST7735_BLUE);
	drawLine(_width - 13, 7, _width - 7, 13, ST7735_BLUE);
	drawLine(_width - 7, 13, _width - 10, 16, ST7735_BLUE);
	if (connected)
	{
		drawLine(_width - 15, 4, _width - 5, 16, ST7735_RED);
		drawLine(_width - 5, 4, _width - 15, 16, ST7735_RED);
	}
}

void drawBattery(uint8_t percentage)
{
	drawLine(_width - 20, 6, _width - 30, 6, ForeGroundColor);
	drawLine(_width - 20, 14, _width - 30, 14, ForeGroundColor);
	drawLine(_width - 20, 6, _width - 20, 14, ForeGroundColor);
	drawLine(_width - 30, 6, _width - 30, 14, ForeGroundColor);
	drawLine(_width - 31, 8, _width - 31, 12, ForeGroundColor);
	drawLine(_width - 30, 8, _width - 32, 12, ForeGroundColor);
	fillRect(_width - 29, 7, 9, 7, BackGroundColor);
	if (percentage >= 90)
	{
		fillRect(_width - 29, 7, 9, 7, ST7735_GREEN);
	}
	else if (percentage >= 80)
	{
		fillRect(_width - 29, 7, 8, 7, ST7735_GREEN);
	}
	else if (percentage >= 70)
	{
		fillRect(_width - 29, 7, 7, 7, ST7735_GREEN);
	}
	else if (percentage >= 60)
	{
		fillRect(_width - 29, 7, 6, 7, ST7735_YELLOW);
	}
	else if (percentage >= 50)
	{
		fillRect(_width - 29, 7, 5, 7, ST7735_YELLOW);
	}
	else if (percentage >= 40)
	{
		fillRect(_width - 29, 7, 4, 7, ST7735_YELLOW);
	}
	else if (percentage >= 30)
	{
		fillRect(_width - 29, 7, 3, 7, ST7735_RED);
	}
	else if (percentage >= 20)
	{
		fillRect(_width - 29, 7, 2, 7, ST7735_RED);
	}
	else if (percentage >= 10)
	{
		fillRect(_width - 29, 7, 1, 7, ST7735_RED);
	}
}

int main(void)
{
	// init the 1.8 lcd display
	init();
	constructor(_width, _height);
	fillScreen(BackGroundColor);
	drawFrame();
	drawTime();
	drawBluetoothConnected(0);
	drawBattery(50);
	initUART();
	int seconds = 0;
	int minutes = 0;
	drawCircle(_width / 2, _height / 2, _width / 2 - 26, ForeGroundColor);
	while (1)
	{

		drawClock(seconds, minutes);
		myDelay(10000);
		seconds = (seconds + 1);
		if (seconds == 60)
		{
			minutes = (minutes + 1) % 60;
			seconds %= 60;
		}
	}
	return 0;
}
