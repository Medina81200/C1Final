/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Edgar Medina
 * @date November 28, 2024
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h> // Types as: uint8_t, int32_t
#include <stddef.h> // Type: size_t

/**
 * @brief Converts an integer to an ASCII string
 *
 * Converts a signed 32-bit integer into an ASCII string based on the specified base (2 to 16).
 * The resulting string is stored at the location pointed to by the `ptr` parameter, with a null
 * terminator at the end.
 *
 * @param data Signed 32-bit integer to convert
 * @param ptr Pointer to a buffer where the resulting ASCII string will be stored
 * @param base Base for conversion (supports bases 2 to 16)
 *
 * @return Length of the converted string, including the null terminator and sign (if negative).
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts an ASCII string to an integer
 *
 * Converts an ASCII string (representing a number in a given base) into a signed 32-bit integer.
 *
 * @param ptr Pointer to the ASCII string
 * @param digits Number of digits in the string, including the sign if present
 * @param base Base of the number represented in the string (supports bases 2 to 16)
 *
 * @return The converted signed 32-bit integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */

