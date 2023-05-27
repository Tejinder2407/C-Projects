/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
int main()
{
	int JAN = 1, DEC = 12;
	int Year, Month;
	printf("General Well-being Log\n");
	printf("======================\n");
	printf("Set the year and month for the well-being log (YYYY MM): ");
	scanf("%d", &Year);
	scanf("%d", &Month);
	while (Year<MIN_YEAR || Year>MAX_YEAR || Month<JAN || Month>DEC)
	{
		if (Year<MIN_YEAR || Year>MAX_YEAR)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
		if (Month<JAN || Month>DEC)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d", &Year);
		scanf("%d", &Month);
	}

	printf("\n");
	printf("*** Log date set! ***\n");
	printf("\n");
	printf("Log starting date: %d-", Year);
	if(Month == 1)
	{
		printf("JAN-01");
	}

	if(Month == 2)
	{
		printf("FEB-01");
	}

	if(Month == 3)
	{
		printf("MAR-01");
	}

	if(Month == 4)
	{
		printf("APR-01");
	}

	if(Month == 5)
	{
		printf("MAY-01");
	}

	if(Month == 6)
	{
		printf("JUN-01");
	}

	if(Month == 7)
	{
		printf("JUL-01");
	}

	if(Month == 8)
	{
		printf("AUG-01");
	}

	if(Month == 9)
	{
		printf("SEP-01");
	}

	if(Month == 10)
	{
		printf("OCT-01");
	}

	if(Month == 11);
	{
		printf("NOV-01");
	}
	if(Month == 12)
	{
		printf("DEC-01");

	}

	return 0;
}