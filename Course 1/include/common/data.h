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
 * @author Mark Attia
 * @date September 4, 2019
 *
 */

#include <inttypes.h>

/**
 * @brief converts the integer to string 
 *
 * This function converts the integer values into an array of characters which
 * ends  with a '\0'
 *
 *
 * @param data the integer
 * @param ptr  A pointer to the array of characters which represents the string
 * @param base the base of convergence
 *
 * @return the size of the array.
 */
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

/**
 * @brief converts the string to integer 
 *
 * This function converts an array of characters which ends 
 * with a '\0' to an integer value
 *
 * @param digits the number of elements in the array
 * @param ptr  A pointer to the array of characters which represents the string
 * @param base the base of convergence
 *
 * @return the integer value.
 */
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);


