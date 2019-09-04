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
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base)
{
    uint8_t i = 0; 
    uint8_t Negative = 0;
	int32_t rem;
	uint8_t start; 
    uint8_t end;
 	uint8_t tmp;
    if (data == 0) 
    { 
        *(ptr+i) = '0';
		i++; 
        *(ptr+i) = '\0'; 
        return i+1; 
    }
    if (data < 0 && base == 10) 
    { 
        Negative = 1; 
        data = -1 * data; 
    } 
  
    while (data != 0) 
    { 
        rem = data % base; 
        *(ptr+i) = (rem > 9) ? (rem-10) + 'a' : rem + '0';
		i++; 
        data = data/base; 
    } 
   
    if (Negative)
	{ 
        	*(ptr+i) = '-';
		i++; 
  	}
    *(ptr+i) = '\0'; 
  
    start = 0; 
    end = i - 1;
    while (start < end) 
    { 
        tmp = *(ptr+start);
		*(ptr+start) =  *(ptr+end);
		*(ptr+end) = tmp;
        start++; 
        end--; 
    }
    return i+1;
}

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base)
{
	int32_t result = 0;
	uint32_t multiplier = 1;
	int8_t i;
	uint8_t Negative = 0;
	uint8_t tmp;
	if(*ptr == '-') 
	{
		Negative = 1;
	}
	for(i = digits-2; i >= 0; i--)
	{	if(Negative && i == 0) break;
		if(*(ptr+i) <= '9') tmp = '0';
		else tmp = 'a'-10;
		result += (*(ptr+i) - tmp) * multiplier;
		multiplier *= base;
	}
	if(Negative == 1) result = -1*result;
	return result;
}
