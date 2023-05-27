// #############################################################################################
//  Assignment: 1 
//  Milestone : 2
// #############################################################################################
//   Student Name  : Tejider Singh
//  Student ID    : 129121216
//  Student Email :ktejinder-singh@myseneca.ca
//  Course Section: IPC144ZDD
// #############################################################################################
#define _CRT_SECURE_NO_WARNINGS
//Structures
struct Person
{
	char Full_name[31];
	int YOB;
	double household_income;
	char country[31];
};
struct UserLogin
{
	char Login_Name[11];
	char password[9];
};
struct Account
{
	int Acc_num;
	char* Acc_type;
};