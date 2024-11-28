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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdlib.h> // 

/***********************************************************
 Function Definitions
***********************************************************/

void set_value(char * ptr, unsigned int index, char value) {
    *(ptr + index) = value;
}

void clear_value(char * ptr, unsigned int index) {
    set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index) {
    return *(ptr + index);
}

void set_all(char * ptr, char value, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        set_value(ptr, i, value);
    }
}

void clear_all(char * ptr, unsigned int size) {
    set_all(ptr, 0, size);
}

/**
 *Moves a block of memory, handling overlaps
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
    if (src == dst || length == 0) {
        return dst;
    }

    if (dst > src && dst < src + length) {
        // Overlap
        src += length - 1;
        dst += length - 1;
        while (length--) {
            *dst-- = *src--;
        }
    } else {
        // No overlap
        while (length--) {
            *dst++ = *src++;
        }
    }

    return dst;
}

/**
 *Copies a block of memory without overlap handling
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    while (length--) {
        *dst++ = *src++;
    }
    return dst;
}

/**
 * Sets a block of memory to a specified value
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    uint8_t * start = src;
    while (length--) {
        *src++ = value;
    }
    return start;
}

/**
 * Sets a block of memory to zero
 */
uint8_t * my_memzero(uint8_t * src, size_t length) {
    uint8_t * start = src;
    while (length--) {
        *src++ = 0;
    }
    return start;
}

/**
 * Reverses a block of memory
 */
uint8_t * my_reverse(uint8_t * src, size_t length) {
    uint8_t * start = src;
    uint8_t * end = src + length - 1;
    uint8_t temp;

    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    return src;
}

/**
 *Allocates a block of memory for a specified number of words
 */
int32_t * reserve_words(size_t length) {
    return (int32_t *)malloc(length * sizeof(int32_t));
}

/**
 *Frees a block of allocated memory
 */
void free_words(int32_t * src) {
    free(src);
}


