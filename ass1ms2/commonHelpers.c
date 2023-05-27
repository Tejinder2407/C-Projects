// #############################################################################################
//  Assignment: 1 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Tejider Singh
//  Student ID    : 129121216
//  Student Email :ktejinder-singh@myseneca.ca
//  Course Section: IPC144ZDD
// #############################################################################################
#define _CRT_SECURE_NO_WARNINGS
// SYSTEM LIBRARY
#include<stdio.h>
#include <time.h>
// USER LIBRARY
#include "commonHelpers.h"
// Function 1: currentYear
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}
// Function 2: clearStandardInputBuffer
void clearStandardInputBuffer(void)
{
	do
	{
		;
	} while (getchar() != '\n');
}
// Function 3: getInteger
int getInteger(void)
{
	int int_num = 0;
	char newLineCheck = 0;
	while (newLineCheck != '\n')
	{
		scanf("%d%c", &int_num, &newLineCheck);
		if (newLineCheck != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	}
	return int_num;
}
// Function 4: getPositiveInteger
int getPositiveInteger(void)
{
	int count = 1;
	int pint_num = 0;
	while (count)
	{
		pint_num = getInteger();
		if (pint_num <= 0)
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
		else
		{
			count = 0;
		}
	}
	return pint_num;
}
// Function 5: getDouble
double getDouble(void)
{
	double doubl_num = 0.0;
	char newLineCheck = 0;
	do
	{
		scanf("%lf%c", &doubl_num, &newLineCheck);
		if (newLineCheck != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (newLineCheck != '\n');
	return doubl_num;
}
// Function 6: getPositiveDouble
double getPositiveDouble(void)
{
	double pos_num = 0.0;
	int banner = 1;
	while (banner)
	{
		pos_num = getDouble();
		if (pos_num > 0)
		{
			banner = 0;
		}
		else
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	}
	return pos_num;
}
// Function 7: getIntFromRange
int getIntFromRange(int min, int max)
{
	int scale = 0;
	int banner = 1;
	while (banner)
	{
		scale = getInteger();
		if (scale < min || scale > max)
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", min, max);
		}
		else
		{
			banner = 0;
		}
	}
	return scale;
}
// Function 8: getCharOption
char getCharOption(const char checkString[])
{
	char str = 0;
	
	int a = 0;
	
	int banner = 1;
	
	int count = 0;
	
	char newlineCheck = 0;
	for (a = 0; checkString[a] != '\0'; a++)
	{
		count++;
	}
	while (banner)
	{
		scanf("%c%c", &str, &newlineCheck);
		
		if (newlineCheck == '\n')
		{
			
			for (a = 0; a < count && banner; a++)
			{
				if (str == checkString[a])
				{
					banner = 0;
				}
			}
			if (banner)
			{
				printf("ERROR: Character must be one of [%s]: ", checkString);
			}
		}
		else
		{
			
			printf("ERROR: Character must be one of [%s]: ", checkString);
			
			clearStandardInputBuffer();
		}
	}
	return str;
}
// Function 9: getCString
void getCString(char charPointer[], int minimum, int maximum)
{
	int a = 0, b = 0;
	int count = 0;
	int banner = 1;
	char inputCString[31];
	do
	{
		scanf("%31[^\n]", inputCString);
		clearStandardInputBuffer();
		count = 0;
		for (a = 0; inputCString[a] != '\0'; a++)
		{
			count++;
		}
		if (count < minimum && (minimum != maximum))
		{
		
			printf("ERROR: String length must be between %d and %d chars: ", minimum, maximum);
		
		}
		else if (count > maximum && (minimum != maximum))
		{
			
			printf("ERROR: String length must be no more than %d chars: ", maximum);
		
		}

		else if ((count <minimum || count> maximum)
			&& minimum == maximum)
		{
			printf("ERROR: String length must be exactly %d chars: ",
				minimum);
		}
	
		else
		{
			for (b = 0; b < count + 1; b++)
			{
				charPointer[b] = inputCString[b];
			}
			
			banner = 0;
		}
	
	
	} while (banner);
}