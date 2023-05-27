/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca 
	Section: ipc144-ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float amount, Nt, Nl, Nq, Nd, Nn, Np, servicefee;
	int toonie, loonie, quarter, dime, nickel, penny;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%f", &amount);
	servicefee = amount * 5 / 100;
	amount -= servicefee;
	amount *= 100;
	toonie = amount / 200;
	Nt = (int)amount % 200;
	loonie = Nt / 100;
	Nl = (int)Nt % 100;
	quarter = Nl / 25;
	Nq = (int)Nl % 25;
	dime = Nq / 10;
	Nd = (int)Nq % 10;
	nickel = Nd / 5;
	Nn = (int)Nd % 5;
	penny = Nn / 1;
	Np = (int)Nn % 1;
	printf("Service fee (5.0 percent): %1.2lf\n", servicefee);
	printf("Balance to dispense: $%1.2lf\n", (double)amount / 100);
	printf("\n");
	printf("$2.00 Toonies  X ");
	printf("%d", toonie);
	printf(" (remaining: $%1.2lf)\n", (double)Nt / 100);
	printf("$1.00 Loonies  X ");
	printf("%d", loonie);
	printf(" (remaining: $%1.2lf)\n", (double)Nl / 100);
	printf("$0.25 Quarters X ");
	printf("%d", quarter);
	printf(" (remaining: $%1.2lf)\n", (double)Nq / 100);
	printf("$0.10 Dimes    X ");
	printf("%d", dime);
	printf(" (remaining: $%1.2lf)\n", (double)Nd / 100);
	printf("$0.05 Nickels  X ");
	printf("%d", nickel);
	printf(" (remaining: $%1.2lf)\n", (double)Nn / 100);
	printf("$0.01 Pennies  X ");
	printf("%d", penny);
	printf(" (remaining: $%1.2lf)\n", (double)Np / 100);
	printf("\n");
	return 0;
}