/*
	==================================================

	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ipc144-ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w6p1.h"

int getIntPositive(int* g)
{
	int d;


	do
	{
		scanf("%d", &d);
		if (d <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (d <= 0);

	if (g != 0)
		*g = d;


	return d;

}
double getDoublePositive(double* h)
{
	double k;
	do
	{
		
		scanf("%lf", &k);
		if (k <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}


	} while (k <= 0);
	if (h != 0)
	{

		*h = k;
	}
	return k;

}


void openingMessage(const int noproduct)
{
	printf("Cat Food Cost Analysis\n");


	printf("======================\n\n");


	printf("Enter the details for %d dry food bags of product data for analysis.\n", noproduct);


	printf("NOTE: A 'serving' is %dg\n", no_grams);



}


struct CatFoodInfo getCatFoodInfo(const int sku_num)


{
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sku_num);

	printf("--------------------\n");

	printf("SKU           : ");

	getIntPositive(&food.Sku);

	printf("PRICE         : $");

	getDoublePositive(&food.Price);

	printf("WEIGHT (LBS)  : ");

	getDoublePositive(&food.Weight);

	printf("CALORIES/SERV.: ");

	getIntPositive(&food.Calories);

	return food;
}



void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{
	
	
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);

}

void start()
{
	
	
	struct CatFoodInfo cats[proproduct] = { {0} };
	openingMessage(proproduct);
	int no;
	for (no = 0; no < proproduct; no++)
	{
		cats[no] = getCatFoodInfo(no + 1);
	}
	printf("\n");
	
	
	
	displayCatFoodHeader();
	
	
	for (no = 0; no < proproduct; no++)
	{
		displayCatFoodData(cats[no].Sku, &cats[no].Price, cats[no].Calories, &cats[no].Weight);
	}
}