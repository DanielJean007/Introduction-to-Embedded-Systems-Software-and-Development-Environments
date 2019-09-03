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
 * @brief stats functions implementation
 *
 * Stats.c file contains the implementation for several statistical functions
 * such as median, mean, sorting, minimum and maximum in addition to the main
 * function that calls a print function to print the excuted functions results
 *
 *
 * @author Mark Attia
 * @date 20/8/2019
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_statistics(test, SIZE);

}

void print_statistics(unsigned char* arr, unsigned int n)
{
	unsigned char median, mean, max, min;
	printf("The Array: \n");
	print_array(arr,n);	
	median = find_median(arr, n);
	mean   = find_mean(arr, n);
	max	   = find_maximum(arr, n);
	min	   = find_minimum(arr, n);
	printf("The Median  = %u\n", median);
	printf("The Mean    = %u\n", mean);
	printf("The Maximum = %u\n", max);
	printf("The Minimum = %u\n", min);
	printf("The Sorted Array: \n");
	sort_array(arr, n);
	print_array(arr, n);
}

void print_array(unsigned char* arr, unsigned int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}

unsigned char find_median(unsigned char* arr, unsigned int n)
{
	unsigned char* tmp1 = (unsigned char*)malloc(sizeof(unsigned char)*n);
	unsigned char* tmp2 = (unsigned char*)malloc(sizeof(unsigned char)*n);
	unsigned char min; 
	unsigned char min_index;
	for(int i=0; i<n; i++)
	{
		tmp1[i]=arr[i];
	}
	for(int i=0; i<n; i++)
	{
		min = 255;
		for(int j=0; j<n; j++)
		{
			if(tmp1[j]<min) 
			{ 
				min = tmp1[j];
				min_index = j;
			}
		}
		tmp1[min_index] = 255;
		tmp2[i] = min;
	}
	if(n%2==0) return(((unsigned int)(tmp2[n/2])+(unsigned int)(tmp2[(n/2)-1]))/2);
	else return tmp2[n/2];
}

unsigned char find_mean(unsigned char* arr, unsigned int n)
{
	unsigned int sum = 0;
	for(int i=0; i<n; i++)
		sum += (unsigned int)(arr[i]);
	return (unsigned char)(sum/n);
}

unsigned char find_maximum(unsigned char* arr, unsigned int n)
{
	unsigned char max = 0;
	for(int i=0; i<n; i++)
		if(max<arr[i]) max = arr[i];
	return max;
}

unsigned char find_minimum(unsigned char* arr, unsigned int n)
{
	unsigned char min = 255;
	for(int i=0; i<n; i++)
		if(min>arr[i]) min = arr[i];
	return min;
}

unsigned char* sort_array(unsigned char* arr, unsigned int n)
{
	unsigned char temp;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	return arr;
}
