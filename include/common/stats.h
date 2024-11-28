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
 * @file stats.h
 * @brief Declarations for functions for an array data analizer 
 *
 * Ths file has the functions declarations that helps to perform an analysis on
 * an array unsigned char data. The functions calculate the mean, median, maximum, 
 * and minimum values, as well as sort the data.
 *
 * @author Edgar Medina
 * @date Nov 5, 2024 
 *
 */

#ifndef STATS_H
#define STATS_H

unsigned char find_minimum(unsigned char *array, unsigned int size);

/**
 * @brief Finds the minimum value on the array
 *
 * Return the minimum value in the array.
 *
 * @param array: Pointer to the unsigned char array
 * @param size: Size of the array 
 *
 * @return min
 */

unsigned char find_maximum(unsigned char *array, unsigned int size);

/**
 * @brief Finds the maximum value in the array
 *
 * Returns the maximum value in the array.
 *
 * @param array Pointer to the unsigned char array
 * @param size Size of the array 
 *
 * @return The maximum value in the array
 */

unsigned char find_mean(unsigned char *array, unsigned int size);

/**
 * @brief Calculates the mean of the array
 *
 * Calculates and returns the mean of the array, rounded down to the nearest integer.
 *
 * @param array Pointer to the unsigned char array
 * @param size Size of the array 
 *
 * @return The mean value of the array
 */

unsigned char find_median(unsigned char *array, unsigned int size);

/**
 * @brief Finds the median of the array
 *
 * Calculates and returns the median of the array. If the array has an even number of elements, 
 * the median is the average of the two middle elements, rounded down to the nearest integer.
 *
 * @param array Pointer to the unsigned char array
 * @param size Size of the array 
 *
 * @return The median value of the array
 */

void print_statistics(unsigned char *array, unsigned int size);

/**
 * @brief Prints the statistics of the array
 *
 * Prints the minimum, maximum, mean, and median of the array in a nicely formatted manner.
 *
 * @param array Pointer to the unsigned char array
 * @param size Size of the array
 */


void print_array(unsigned char *array, unsigned int size);

/**
 * @brief Prints the array
 *
 * Prints each element in the array in a formatted grid, making it easier to read.
 *
 * @param array Pointer to the unsigned char array
 * @param size Size of the array
 */

void sort_array(unsigned char *array, unsigned int size);

/**
 * @brief Sorts the array in descending order
 *
 * Sorts the elements of the array from the largest to the smallest value.
 *
 * @param array Pointer to the unsigned char array
 * @param size Size of the array
 */

#endif // STATS_H
