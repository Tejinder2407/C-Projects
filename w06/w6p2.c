/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ipc144ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
// System Libraries
#include <stdio.h>
// User Libraries
#include "w6p2.h"
// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* i_num)
{
	int intNum = 0;
	do
	{
		scanf("%d", &intNum);
		if (intNum < 1)
			printf("ERROR: Enter a positive value: ");
	} while (intNum < 1);
	if (i_num != NULL)
		*i_num = intNum;
	return intNum;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* d_num)
{
	double doubl_num = 0;
	do
	{
		scanf("%lf", &doubl_num);
		if (doubl_num <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (doubl_num <= 0);
	if (d_num != NULL)
		*d_num = doubl_num;
	return doubl_num;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of"
		" product data for analysis.\n", NPA);
	printf("NOTE: A 'serving' is %dg\n", GRAM_S);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seq_num)
{
	printf("Cat Food Product #%d\n", seq_num);
	printf("--------------------\n");
	struct CatFoodInfo Data;
	printf("SKU           : ");
	do
	{
		scanf("%d", &Data.sku);
		if (Data.sku < 1)
			printf("ERROR: Enter a positive value: ");
	} while (Data.sku < 1);
	printf("PRICE         : $");
	do
	{
		scanf("%lf", &Data.rate);
		if (Data.rate <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (Data.rate <= 0);
	printf("WEIGHT (LBS)  : ");
	do
	{
		scanf("%lf", &Data.weight);
		if (Data.weight <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (Data.weight <= 0);
	printf("CALORIES/SERV.: ");
	do
	{
		scanf("%d", &Data.calories);
		if (Data.calories < 1)
			printf("ERROR: Enter a positive value: ");
	} while (Data.calories < 1);
	printf("\n");
	return Data;
}
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}
// 6. Display a formatted record of cat food data
void displayCatFoodInfo(const int sku, const double price, const int calories,
	const double weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calories);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* wieght_lbs, double* wieght_kg)
{
	double endResult;
	endResult = *wieght_lbs / KgtoLbs;
	if (wieght_kg != NULL)
		*wieght_kg = endResult;
	return endResult;
};
// 9. convert lbs: g
int convertLbsG(const double* wieght_lb, int* wieght_grams)
{
	int endResult;
	endResult = (*wieght_lb / KgtoLbs) * 1000;
	if (wieght_grams != NULL)
		*wieght_grams = endResult;
	return endResult;
}
// 10. convert lbs: kg and g
void convertLbs(const double* wieght_lbs, double* wieght_kg, int* wieght_grams)
{
	double Lbstokg, Lbstograms;
	Lbstokg = convertLbsKg(wieght_lbs, wieght_kg);
	Lbstograms = convertLbsG(wieght_lbs, wieght_grams);
	*wieght_kg = Lbstokg;
	*wieght_grams = Lbstograms;
}
// 11. calculate: servings based on gPerServ
double calculateServings(const int serv_g, const int tg_product, double* nos)
// serv_g is seving size in grams; tg_product is total grams for a product; nos is number of servings
{
	double GperServ;
	GperServ = (double)tg_product / GRAM_S;
	if (nos != NULL)
		*nos = GperServ;
	return GperServ;
}
// 12. calculate: cost per serving
double calculateCostPerServing(const double* ProductPrice, const double* Num_Servings, double* CostPerServing)
{
	double CostS;
	CostS = *ProductPrice / *Num_Servings;
	if (CostPerServing != NULL)
		*CostPerServing = CostS;
	return CostS;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ProductPrice, const double* TotalCal, double* CostPerCal)
{
	double CostC;
	CostC = *ProductPrice / *TotalCal;
	if (CostPerCal != NULL)
		*CostPerCal = CostC;
	return CostC;
}
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo catfoodInfo)
{
	struct ReportData data;
	data.sku = catfoodInfo.sku;
	data.price = catfoodInfo.rate;
	data.calories = catfoodInfo.calories;
	data.weight_Lbs = catfoodInfo.weight;
	data.weight_kgs = convertLbsKg(&catfoodInfo.weight, &data.weight_kgs);
	data.weight_gm = convertLbsG(&catfoodInfo.weight, &data.weight_gm);
	data.TotalServe = calculateServings(NPA, data.weight_gm, &data.TotalServe);
	data.CostServe = calculateCostPerServing(&data.price, &data.TotalServe, &data.CostServe);
	double cal = data.TotalServe * data.calories;
	data.CostCal = calculateCostPerCal(&data.price, &cal, &data.CostCal);
	return data;
}
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", GRAM_S);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}
// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const double cheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data.sku,
		data.price, data.weight_Lbs, data.weight_kgs, data.weight_gm, data.calories,
		data.TotalServe, data.CostServe, data.CostCal);
	if (data.CostServe == cheapest)
	{
		printf(" ***\n");
	}
	else
		printf("\n");
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheaper_product)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%0.2lf\n", cheaper_product.sku, cheaper_product.rate);
	printf("\n");
	printf("Happy shopping!\n");
}
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int a;
	struct CatFoodInfo catfoodInfo[NPA + 1];
	openingMessage(NPA);
	printf("\n");
	for (a = 0; a < NPA; a++)
	{
		catfoodInfo[a + 1] = getCatFoodInfo(a + 1);
	}
	displayCatFoodHeader();
	for (a = 0; a < NPA; a++)
	{
		displayCatFoodInfo(catfoodInfo[a + 1].sku, catfoodInfo[a + 1].rate,
			catfoodInfo[a + 1].calories, catfoodInfo[a + 1].weight);
	}
	printf("\n");
	struct ReportData data[NPA + 1];
	for (a = 0; a < NPA; a++)
	{
		data[a + 1] = calculateReportData(catfoodInfo[a + 1]);
	}
	displayReportHeader();
	double cheapest = data[1].CostServe;
	for (a = 0; a < NPA; a++)
	{
		if (data[a + 1].CostServe < cheapest)
		{
			cheapest = data[a + 1].CostServe;
		}
	}
	for (a = 0; a < NPA; a++)
	{
		displayReportData(data[a + 1], cheapest);
	}
	printf("\n");
	for (a = 0; a < NPA; a++)
	{
		if (cheapest == data[a + 1].CostServe)
		{
			displayFinalAnalysis(catfoodInfo[a + 1]);
		}
	}
}

