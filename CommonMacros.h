/*
 * CommonMacros.h
 *
 *  Created on: Feb 14, 2018
 *      Author: Michael Tharwat
 */

#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_

#define SET_BIT(REG,BitNumber)		REG|=(1<<BitNumber)
#define CLR_BIT(REG,BitNumber)		REG&=~(1<<BitNumber)
#define TOGGLE_BIT(REG,BitNumber)	REG^=(1<<BitNumber)
#define GET_BIT(REG,BitNumber)		(REG>>BitNumber)&0x01
#define SET_REG(REG)				REG=0xFF
#define CLR_REG(REG)				REG=0x00

#endif /* COMMONMACROS_H_ */
