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
 * @file data.c
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Edgar Medina
 * @date November 28, 2024
 *
 */

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    if (base < 2 || base > 16) {
        return 0; // Base fuera de rango
    }

    uint8_t *start = ptr; // Initial pointer
    uint8_t is_negative = 0;

    //Manage negative numbers
    if (data < 0 && base == 10) {
        is_negative = 1;
        data = -data; // Convertir a positivo
    }

    // Convert to a specific base
    do {
        int32_t remainder = data % base;
        *ptr++ = (uint8_t)(remainder < 10 ? remainder + '0' : remainder - 10 + 'A');
        data /= base;
    } while (data > 0);

    // add negative sign if it is a negative number
    if (is_negative) {
        *ptr++ = '-';
    }

    // null terminator
    *ptr = '\0';

    uint8_t *end = ptr - 1;
    while (start < end) {
        uint8_t temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    // Long of the secuence
    return (uint8_t)(ptr - start + 1);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    if (base < 2 || base > 16) {
        return 0;
    }

    int32_t result = 0;
    uint8_t is_negative = 0;

    // Manage of negative sign
    if (*ptr == '-') {
        is_negative = 1;
        ptr++;
        digits--;
    }

    // convert to an integer
    while (digits-- > 0) {
        uint8_t digit = *ptr++;
        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'A' && digit <= 'F') {
            digit = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            digit = digit - 'a' + 10;
        } else {
            return 0; // Invalid charecter
        }

        if (digit >= base) {
            return 0; // Invalid base
        }

        result = result * base + digit;
    }

    // Apply negative sign if it necessary 
    return is_negative ? -result : result;
}

