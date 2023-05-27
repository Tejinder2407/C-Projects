/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : Tejinder singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: IPC144-ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float amount, Nt, Nl, Nq;
	int toonie, loonie, quarter;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%f", &amount);
	printf("\n");
	amount *= 100;
	toonie = amount / 200;
	Nt = (int)amount % 200;
	loonie = Nt / 100;
	Nl = (int)Nt % 100;
	quarter = Nl / 25;
	Nq = (int)Nl % 25;
		printf("$2.00 Toonies  X ");
		printf("%d", toonie);
		printf(" (remaining: $%1.2lf)\n", (double)Nt / 100);
		printf("$1.00 Loonies  X ");
		printf("%d", loonie);
		printf(" (remaining: $%1.2lf)\n", (double)Nl / 100);
		printf("$0.25 Quarters X ");
		printf("%d", quarter);
		printf(" (remaining: $%1.2lf)\n", (double)Nq / 100);
		printf("\n");
		printf("Machine error! Thank you for letting me keep $");
		printf("%1.2lf!\n", (double)Nq / 100);
	return 0;
}

