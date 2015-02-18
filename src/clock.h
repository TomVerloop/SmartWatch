/*
 * clock.h
 *
 *  Created on: Feb 17, 2015
 *      Author: tom
 */

#ifndef CLOCK_H_
#define CLOCK_H_

static const double coslist[] =
{ 1, 0.994522, 0.978148, 0.951057, 0.913545, 0.866025, 0.809017, 0.743145,
		0.669131, 0.587785, 0.5, 0.406737, 0.309017, 0.207912, 0.104528,
		2.83275e-016, -0.104528, -0.207912, -0.309017, -0.406737, -0.5,
		-0.587785, -0.669131, -0.743145, -0.809017, -0.866025, -0.913545,
		-0.951057, -0.978148, -0.994522, -1, -0.994522, -0.978148, -0.951057,
		-0.913545, -0.866025, -0.809017, -0.743145, -0.669131, -0.587785, -0.5,
		-0.406737, -0.309017, -0.207912, -0.104528, -1.83691e-016, 0.104528,
		0.207912, 0.309017, 0.406737, 0.5, 0.587785, 0.669131, 0.743145,
		0.809017, 0.866025, 0.913545, 0.951057, 0.978148, 0.994522, 1 };

static const double sinlist[] =
{ 0, 0.104528, 0.207912, 0.309017, 0.406737, 0.5, 0.587785, 0.669131, 0.743145,
		0.809017, 0.866025, 0.913545, 0.951057, 0.978148, 0.994522, 1, 0.994522,
		0.978148, 0.951057, 0.913545, 0.866025, 0.809017, 0.743145, 0.669131,
		0.587785, 0.5, 0.406737, 0.309017, 0.207912, 0.104528, -7.65718e-016,
		-0.104528, -0.207912, -0.309017, -0.406737, -0.5, -0.587785, -0.669131,
		-0.743145, -0.809017, -0.866025, -0.913545, -0.951057, -0.978148,
		-0.994522, -1, -0.994522, -0.978148, -0.951057, -0.913545, -0.866025,
		-0.809017, -0.743145, -0.669131, -0.587785, -0.5, -0.406737, -0.309017,
		-0.207912, -0.104528, -4.68581e-015 };

void draw_arm(int position_x, int position_y, int arm_angle, int arm_length,
		int color);



#endif /* CLOCK_H_ */