/*
	==================================================

	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ipc144-ZDD
*/
#define proproduct 3 
#define no_grams 64
struct CatFoodInfo
{
	int Sku;
	double Price;
	int Calories;
	double Weight;
};
int getIntPositive(int* n);
double getDoublePositive(double* h);
void openingMessage(const int noproduct);
struct CatFoodInfo getCatFoodInfo(const int seq_num);
void displayCatFoodHeader();
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight);
void start();