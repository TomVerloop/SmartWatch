#include "clock.h"
#include "GlobalDefines.h"
#include "china_lcd.h"

void draw_arm(int position_x, int position_y, int arm_angle, int arm_length,
		int color)
{
	arm_angle = (arm_angle + 45) % 60;
	int x = arm_length * coslist[arm_angle];
	int y = arm_length * sinlist[arm_angle];
	x += position_x;
	y += position_y;
	drawLine(position_x, position_y, x, y, color);

}

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
