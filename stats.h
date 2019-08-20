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
 * @brief statistical functions declaration
 *
 * a brief description of every function and their decterations
 *
 * @author Mark Attia
 * @date 20/8/2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief This function prints the results
 *
 * The function calls the other functions and prints their results after
 * after being excuted
 *
 * @param arr		a pointer to unsigned char of the test array
 * @param n		an unsigned integer representing the size of the array
 *
 * @return 		no return value
 */

void print_statistics(unsigned char* arr, unsigned int n);

/**
 * @brief This function prints the array
 *
 * The function prints a single array values
 *
 * @param arr		a pointer to unsigned char of the test array
 * @param n		an unsigned integer representing the size of the array
 *
 * @return 		no return value
 */
void print_array(unsigned char* arr, unsigned int n);

/**
 * @brief This function finds the median
 *
 * The function finds the median value of a set of numbers in an array
 *
 * @param arr		a pointer to unsigned char of the test array
 * @param n		an unsigned integer representing the size of the array
 *
 * @return 		unsigned char represents the result
 */
unsigned char find_median(unsigned char* arr, unsigned int n);

/**
 * @brief This function finds the mean
 *
 * The function finds the mean value of a set of numbers in an array
 *
 * @param arr		a pointer to unsigned char of the test array
 * @param n		an unsigned integer representing the size of the array
 *
 * @return 		unsigned char represents the result
 */
unsigned char find_mean(unsigned char* arr, unsigned int n);

/**
 * @brief This function finds the maximum
 *
 * The function finds the maximum value in a set of numbers in an array
 *
 * @param arr		a pointer to unsigned char of the test array
 * @param n		an unsigned integer representing the size of the array
 *
 * @return 		unsigned char represents the result
 */
unsigned char find_maximum(unsigned char* arr, unsigned int n);

/**
 * @brief This function finds the minimum
 *
 * The function finds the minimum value in a set of numbers in an array
 *
 * @param arr		a pointer to unsigned char of the test array
 * @param n		an unsigned integer representing the size of the array
 *
 * @return 		unsigned char represents the result
 */
unsigned char find_minimum(unsigned char* arr, unsigned int n);

/**
 * @brief This function sorts an array
 *
 * The function sorts an array where the largest value is put in the smallest
 * index
 *
 * @param arr		a pointer to unsigned char of the test array
 * @param n		an unsigned integer representing the size of the array
 *
 * @return 		a pointer to unsigned char which represents the sorted
 * array
 */
unsigned char* sort_array(unsigned char* arr, unsigned int n);




#endif /* __STATS_H__ */
