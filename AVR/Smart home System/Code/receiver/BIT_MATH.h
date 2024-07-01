#ifndef BIT_MATH_H
#define BIT_MATH_H

// set a specific bit in a register
#define SET_BIT(reg, bit)        ((reg) |= (1UL << (bit)))

// clear a specific bit in a register
#define CLR_BIT(reg, bit)        ((reg) &= ~(1UL << (bit)))

// toggle a specific bit in a register
#define TOGGLE_BIT(reg, bit)    ((reg) ^= (1UL << (bit)))

// get the value of a specific bit in a register
#define GET_BIT(reg, bit)       (((reg) >> (bit)) & 1U)

#endif
