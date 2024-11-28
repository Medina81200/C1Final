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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdint.h> // Types as: uint8_t, int32_t
#include <stddef.h> // All type of size_t

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a block of memory without handling overlaps
 *
 * Copies a block of memory from the source to the destination. Overlap
 * between the source and destination may cause undefined behavior.
 *
 * @param src Pointer to the source memory block
 * @param dst Pointer to the destination memory block
 * @param length Number of bytes to copy
 *
 * @return Pointer to the destination memory block.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a block of memory to a specific value
 *
 * Fills a block of memory with a given value. Each byte in the block
 * is set to the specified value.
 *
 * @param src Pointer to the memory block
 * @param length Number of bytes to set
 * @param value Value to set each byte to
 *
 * @return Pointer to the memory block.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a block of memory to zero
 *
 * Fills a block of memory with zeroes. Each byte in the block is set to zero.
 *
 * @param src Pointer to the memory block
 * @param length Number of bytes to zero out
 *
 * @return Pointer to the memory block.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes in a memory block
 *
 * Reverses the order of bytes in a memory block. The first byte becomes
 * the last, the second becomes the second to last, and so on.
 *
 * @param src Pointer to the memory block
 * @param length Number of bytes to reverse
 *
 * @return Pointer to the memory block.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates memory for a specified number of words
 *
 * Dynamically allocates memory for a given number of words (4 bytes each).
 *
 * @param length Number of words to allocate
 *
 * @return Pointer to the allocated memory, or NULL if allocation fails.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees allocated dynamic memory
 *
 * Frees a dynamically allocated block of memory.
 *
 * @param src Pointer to the memory block to free
 *
 * @return void.
 */
void free_words(int32_t * src);


#endif /* __MEMORY_H__ */
