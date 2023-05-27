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
// ----------------------------------------------------------------------------
// defines/macros
#define NPA 3
// here npa is maximum number of products to analyze.
#define GRAM_S 64
// here gram_s is gram per serving.
#define KgtoLbs 2.20462
// ----------------------------------------------------------------------------
// structures
struct  CatFoodInfo
{
	int sku;
	double rate;
	int calories;
	double weight;
};
struct ReportData
{
	int sku;
	double price;
	int calories;
	double weight_Lbs;
	double weight_kgs;
	int weight_gm;
	double TotalServe;
	double CostServe;
	double CostCal;
};
// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* i_num);
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* d_num);
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num);
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seq_num);
// 5. Display the formatted table header
void displayCatFoodHeader(void);
// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);
// ----------------------------------------------------------------------------

// PART-2
// 8. convert lbs: kg
double convertLbsKg(const double* wieght_lbs, double* wieght_kg);
// 9. convert lbs: g
int convertLbsG(const double* wieght_lb, int* wieght_grams);
// 10. convert lbs: kg / g
void convertLbs(const double* wieght_lbs, double* wieght_kg, int* wieght_grams);
// 11. calculate: servings based on gPerServ
double calculateServings(const int serv_g, const int tg_product, double* nos);
// 12. calculate: cost per serving
double calculateCostPerServing(const double* ProductPrice, const double* Num_Servings, double* CostPerServing);
// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ProductPrice, const double* TotalCal, double* CostPerCal);
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo catfoodInfo);
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);
// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const double cheapest);
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheaper_product);
// ----------------------------------------------------------------------------
// 7. Logic entry point 
void start(void);

