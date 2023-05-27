






/*
==================================================
Workshop #5 (Part-1):
==================================================
Name   : Tejinder Singh
ID     : 129121216
Email  : ktejinder-singh@myseneca.ca
Section: ipc144-ZDD
*/
//
#define _CRT_SECURE_NO_WARNINGS
#define maximum 70

#include<stdio.h>
struct PlayerInfo
{
	char player;// name of player
	int treasures;
	int life;// number of lives
	int allhistory[maximum];
};
struct GameInfo
{
	int path;
	int moves;
	int bombs[maximum];
	int treasures[maximum];
};

int main()
{
	struct PlayerInfo playerinfo;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerinfo.player);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &playerinfo.life);


		if (playerinfo.life < 1 || playerinfo.life > 10)
			printf("     Must be between 1 and 10!\n");
	} while (playerinfo.life < 1 || playerinfo.life > 10);
	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	struct GameInfo gameinfo;
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &gameinfo.path);
		if ((gameinfo.path < 10 || gameinfo.path >70) || !(gameinfo.path % 5 == 0))
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
	} while ((gameinfo.path < 10 || gameinfo.path >70) || !(gameinfo.path % 5 == 0));

	int path;

	path = (75 * gameinfo.path) / 100;

	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameinfo.moves);
		if (gameinfo.moves < playerinfo.life || gameinfo.moves > path)

			printf("    Value must be between %d and %d\n", playerinfo.life, path);

	} while (gameinfo.moves < playerinfo.life || gameinfo.moves > path);

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.path);

	int a, b;

	for (a = 0; a < gameinfo.path; a = a + 5)
	{
		printf("   Positions [%2d-%2d]: ", a + 1, a + 5);

		for (b = a; b < a + 5; b++)
		{
			scanf("%d", &gameinfo.bombs[b]);
		}
	}

	printf("BOMB placement set\n\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.");
	printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.path);


	int c, d;

	for (c = 0; c < gameinfo.path; c = c + 5)
	{
		printf("   Positions [%2d-%2d]: ", c + 1, c + 5);
		for (d = c; d < c + 5; d++)
		{
			scanf("%d", &gameinfo.treasures[d]);
		}
	}
	printf("TREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", playerinfo.player);
	printf("   Lives      : %d\n", playerinfo.life);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", gameinfo.path);
	printf("   Bombs      : ");
	for (b = 0; b < gameinfo.path; b++)
	{
		printf("%d", gameinfo.bombs[b]);
	}
	printf("\n   Treasure   : ");
	for (d = 0; d < gameinfo.path; d++)
	{
		printf("%d", gameinfo.treasures[d]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");


	return 0;

}


