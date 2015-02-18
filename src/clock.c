#include "clock.h"

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
