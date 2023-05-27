/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ipc144-ZDD
*/
#include<stdio.h>
#define MAX 10
#define MIN 1
#define log 5
#define _CRT_SECURE_NO_WARNINGS





int main()
{
	double total, item;
	int priorityValue, nA, nB, nC, nD, nE, nF, numwish, values, nJ = 1, nQ, selectnum;
	char decision;
	const double leasttotal = 500.00, mosttotal = 400000.00;
	int priority[5] = { 1, 3 ,2, 1 ,3 };
	char finance[5] = { 'n', 'y', 'n', 'y', 'n' };
	double cost[5] = { 39030.15, 1200000.00, 350500.25, 15500.75, 6575.55 };



	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");
	for (nB = 0; nB <= 1; nB++)
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &total);



		if (total < leasttotal)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
			nB = 0;
		}
		else if (total > mosttotal)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
			nB = 0;
		}
		else if (total >= 500.00 && total <= 400000.00)
		{
			nB = 1;
		}
	}
	for (nC = 0; nC <= 1; nC++)
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf(" %d", &numwish);



		if (numwish < MIN || numwish > MAX)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
			nC = 0;
		}
		else
		{
			nC = 1;
		}
	}
	for (nE = 0; nE <= log - 1; nE++)
	{


		printf("\nItem-%d Details:", nJ);

		for (nA = 0; nA <= 1; nA++)
		{
			nJ++;
			printf("\n   Item cost: $");
			scanf(" %lf", &item);
			if (item < 100.00)
			{
				printf("      ERROR: Cost must be at least $100.00");
				nA = 0;
				nJ--;
			}
			else if (item > 100)
			{



				nA = 1;
			}
		}
		for (nD = 0; nD <= 1; nD++)
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &values);



			if (values < 1 || values>3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
				nD = 0;
			}
			else
			{
				nD = 1;
			}



		}



		for (nF = 0; nF <= 1; nF++)
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %s", &decision);
			if (decision == 'y' || decision == 'n')
			{



				nF = 1;
			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				nF = 0;
			}



		}



	}
	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	printf("  1      %d        %c       %.2lf\n", priority[0], finance[0], cost[0]);
	printf("  2      %d        %c     %.2lf\n", priority[1], finance[1], cost[1]);
	printf("  3      %d        %c      %.2lf\n", priority[2], finance[2], cost[2]);
	printf("  4      %d        %c       %.2lf\n", priority[3], finance[3], cost[3]);
	printf("  5      %d        %c        %.2lf\n", priority[4], finance[4], cost[4]);
	printf("---- -------- -------- -----------\n");
	printf("                      $ %.2lf", cost[0] + cost[1] + cost[2] + cost[3] + cost[4]);



	for (nQ = 0; nQ < 2; nQ++) {


		printf("\n\nHow do you want to forecast your wish list?");
		printf("\n 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\n");
		printf("Selection: ");
		scanf(" %d", &selectnum);

		switch (selectnum) {

		case 1:
			printf("\n====================================================");
			printf("\nFilter:   All items\n");
			printf("Amount:   $%.2lf\n", cost[0] + cost[1] + cost[2] + cost[3] + cost[4]);
			printf("Forecast: 21 years, 7 months\n");
			printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
			printf("====================================================");
			nQ = 0;
			break;
		case 2:
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf(" %d", &priorityValue);


			if (priorityValue == 1) {
				printf("\n====================================================\n");
				printf("Filter:   by priority (1)\n");
				printf("Amount:   $%.2lf\nForecast: 0 years, 9 months\nNOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.", cost[3] + cost[0]);
				printf("\n====================================================");

			}
			else if (priorityValue == 2) {
				printf("\n====================================================\n");
				printf("Filter:   by priority (2)\nAmount:   $%.2lf\nForecast: 4 years, 9 months", cost[2]);
				printf("\n====================================================");

			}
			else if (priorityValue == 3) {
				printf("\n====================================================\n");
				printf("Filter:   by priority (3)\nAmount:   $%.2lf\nForecast: 16 years, 2 months\nNOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.", cost[1] + cost[4]);
				printf("\n====================================================");
			}

			nQ = 0;
			break;

		case 0:
			nQ = 2;
			break;

		default:
			printf("\nERROR: Invalid menu selection.");

		}

	}

	printf("\nBest of luck in all your future endeavours!");
	return 0;
}


