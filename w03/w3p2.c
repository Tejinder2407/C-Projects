/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: IPC144-ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
int main()
{
	const int JAN = 1, DEC = 12;
	int Year, Month , day = 1;
	float morrating1 = 0, everating1 = 0, morrating = 0, everating = 0;
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
	for (day = 1; day <= LOG_DAYS; day++)
	{
		printf("%d-", Year);
		if (Month == 1)
		{
			printf("JAN-0%d", day);
		}
		if (Month == 2)
		{
			printf("FEB-0%d", day);
		}
		if (Month==3)
		{
			printf("MAR-0%d", day);
		}
		if (Month == 4)
		{
			printf("APR-0%d", day);
		}
		if (Month == 5)
		{
			printf("MAY-0%d", day);
		}
		if (Month == 6)
		{
			printf("JUN-0%d", day);
		}
		if (Month==7)
		{
			printf("JUL-0%d", day);
		}
		if (Month==8)
		{
			printf("AUG-0%d", day);
		}
		if (Month==9)
		{
			printf("SEP-0%d", day);
		}
		if (Month == 10)
		{
			printf("OCT-0%d", day);
		}
		if (Month==11)
		{
			printf("NOV-0%d", day);
		}
		if (Month==12)
		{
			printf("DEC-0%d", day);

		}
		printf("\n");
		printf("   Morning rating (0.0-5.0): ");
		scanf("%f", &morrating1);
		while (morrating1 < 0 || morrating1>5)
		{
			if (morrating1 < 0 || morrating1>5)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				printf("   Morning rating (0.0-5.0): ");
				scanf("%f", &morrating1);
			}
		}
		morrating= morrating+ morrating1;
		printf("   Evening rating (0.0-5.0): ");
		scanf("%f", &everating1);
		while (everating1 < 0 || everating1>5)
		{
			if (everating1 < 0 || everating1>5)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				printf("   Evening rating (0.0-5.0): ");
				scanf("%f", &everating1);
			}
		}
		everating =everating + everating1;
		printf("\n");
	}
	printf("Summary\n=======\n");
	printf("Morning total rating: %.3lf\n", morrating);
	printf("Evening total rating: %.3lf\n", everating);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n", morrating + everating);
	printf("\n");
	printf("Average morning rating:  %0.1lf\n", morrating / LOG_DAYS);
	printf("Average evening rating:  %0.1lf\n", everating / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %0.1lf\n", ((morrating / LOG_DAYS) + (everating / LOG_DAYS)) / 2);
	return 0;
}

