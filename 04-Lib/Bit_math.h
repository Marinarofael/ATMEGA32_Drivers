/*
 * Bit_math.h
 *
 *  Created on: Dec 7, 2022
 *      Author: lenovo
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit) ((reg) |= (1 << bit))
#define CLR_BIT(reg, bit) ((reg) &= ~(1 << bit))
#define TGL_BIT(reg, bit) ((reg) ^= (1 << bit))
#define GET_BIT(reg, bit) ((reg >> bit) & (0x01))
#define SET_HIG_NIB(reg) ((reg) |= (0xF0))
#define CLR_HIG_NIB(reg) ((reg) &= (0x0F))
#define GET_HIG_NIB(reg) (((reg) >> 4) & (0x0F))
#define TGL_HIG_NIB(reg) ((reg) ^= (0xF0))
#define SET_LOW_NIB(reg) ((reg) |= (0x0F))
#define CLR_LOW_NIB(reg) ((reg) &= (0xF0))
#define GET_LOW_NIB(reg) ((reg) & (0x0F))
#define TGL_LOW_NIB(reg) ((reg) ^= (0x0F))
#define ASSIGN_REG(reg, value) (reg = value)
#define ASSIGN_HIG_NIB(reg, value) (reg = (reg & (0x0F)) + (value << 4))
#define ASSIGN_LOW_NIB(reg, value) (reg = (reg & (0xF0)) + (value))
#define SHIFT_RIGHT(reg, value) (reg >> value)
#define SHIFT_LEFT(reg, value) (reg << value)
#define CLR_RIGHT_SHIFT(reg, value) ((reg >> value) | (reg << 8-value))
#define CLR_LEFT_SHIFT(reg, value) ((reg << value) | (reg >> 8-value))

#endif /* BIT_MATH_H_ */
