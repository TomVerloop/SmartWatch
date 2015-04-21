/*
 * FrameGraphics.h
 *
 *  Created on: Apr 21, 2015
 *      Author: tom
 */

#ifndef FRAMEGRAPHICS_H_
#define FRAMEGRAPHICS_H_

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void drawBattery(uint8_t percentage);

void drawBluetoothConnected(uint8_t connected);

void drawTime(int minutes,int hours);

void drawFrame();


#endif /* FRAMEGRAPHICS_H_ */
