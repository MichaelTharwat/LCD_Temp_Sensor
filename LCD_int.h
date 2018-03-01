/*
 * LCD_int.h
 *
 *  Created on: Feb 19, 2018
 *      Author: Michael Tharwat
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_PORT		D
#define LCD_CTRLPORT	A
#define CLR_LCD			0x01
#define RS	0
#define RW	1
#define E	2

void LCD_vidInit(void);
void LCD_vidSendCommand(u8 Command);
void LCD_vidWriteData(u8 Data);
void LCD_vidWriteString(u8 * Pu8str);
void LCD_vidGOTO(u8 Row,u8 Col);

#endif /* LCD_INT_H_ */
