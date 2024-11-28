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
 * @file stats.c
 * @brief Array analizer 
 *
 * This code provides functions to analyze an array of unsigned char data, 
 * calculating its minimum, maximum, mean, and median. It also sorts the array 
 * in descending order and displays it in a 5x8 grid format for readability.
 *
 * @author Edgar Medina Martinez
 * @date Nov 11, 2024
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

int main(void) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  PRINTF("Verbose: Original array.\n");
  print_array(test, SIZE);
  print_statistics(test, SIZE);

  sort_array(test, SIZE);
  printf("Sorted Array:\n");
  print_array(test, SIZE);

  return 0;
}

void print_statistics(unsigned char * array, unsigned int size) {

  if (array == NULL || size == 0) {
    printf("Error: Invalid array or size.\n");
    return;
  }

  printf("Statistics: \n");
  printf("Minimum: %d\n", find_minimum(array, size));
  printf("Maximum: %d\n", find_maximum(array, size));
  printf("Mean: %d\n", find_mean(array, size));
  printf("Median: %d\n", find_median(array, size));
}

void print_array(unsigned char * array, unsigned int size) {
  if (array == NULL || size == 0) {
    printf("Error: Invalid array or size.\n");
    return;
  }

  #ifdef VERBOSE
  printf("Verbose: Printing array of size %d.\n", size);
  #endif

  printf("Array:\n");
  for (unsigned int i = 0; i < size; i++) {
    printf("%3d", array[i]);
    if (i < size - 1) {
      printf(", ");
    }
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}

unsigned char find_median(unsigned char * array, unsigned int size) {
  if (array == NULL || size == 0) {
    printf("Error: Invalid array or size.\n");
    return 0;
  }

  sort_array(array, size);
  if (size % 2 == 0) {
    return (array[size / 2] + array[(size / 2) - 1]) / 2;
  } else {
    return array[size / 2];
  }
}

unsigned char find_mean(unsigned char * array, unsigned int size) {
  if (array == NULL || size == 0) {
    printf("Error: Invalid array or size.\n");
    return 0;
  }

  unsigned int sum = 0;
  for (unsigned int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum / size;
}

unsigned char find_maximum(unsigned char * array, unsigned int size) {
  if (array == NULL || size == 0) {
    printf("Error: Invalid array or size.\n");
    return 0;
  }

  unsigned char max = array[0];
  for (unsigned int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char * array, unsigned int size) {
  if (array == NULL || size == 0) {
    printf("Error: Invalid array or size.\n");
    return 0;
  }

  unsigned char min = array[0];
  for (unsigned int i = 1; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

void sort_array(unsigned char * array, unsigned int size) {
  if (array == NULL || size == 0) {
    printf("Error: Invalid array or size.\n");
    return;
  }

  for (unsigned int i = 1; i < size; i++) {
    unsigned char key = array[i];
    int j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}







