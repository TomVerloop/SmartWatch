/*
 * FrameGraphics.c
 *
 *  Created on: Apr 21, 2015
 *      Author: tom
 */

#include "FrameGraphics.h"
#include "china_lcd.h"
#include "gfx.h"
#include "GlobalDefines.h"

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

void drawTime(int minutes,int hours)
{
	setTextColor(ForeGroundColor, BackGroundColor);
	setTextSize(2);
	setCursor(10, _height - 22);
	char thour = 0;
	char hour = 0;
	char minute = 0;
	char tminute = 0;
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


