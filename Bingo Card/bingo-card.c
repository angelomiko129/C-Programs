/*Group 9 Coding Challenge 4 (Bingo Card)
Val D. Angbengco
James Aizard B. Ramirez
Angelo Miko A. Botabara
Mark Andrei B. Muyna
Christian Joseph C. Ramirez*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//defining a constant variable for 2d array
#define ROWS 5
#define COLS 5

//function declaration
void generateBingoCard(int bingoCard[ROWS][COLS]);
void displayBingoCard(int bingoCard[ROWS][COLS]);
void choosePattern(int bingoCard[ROWS][COLS]);
void displayTopRow(int bingoCard[ROWS][COLS]);
void displayBottomRow(int bingoCard[ROWS][COLS]);
void displayMiddleRow(int bingoCard[ROWS][COLS]);
void displayLeftColumn(int bingoCard[ROWS][COLS]);
void displayRightColumn(int bingoCard[ROWS][COLS]);
void displayMiddleColumn(int bingoCard[ROWS][COLS]);
void displayDiagonalLeftToRight(int bingoCard[ROWS][COLS]);
void displayDiagonalRightToLeft(int bingoCard[ROWS][COLS]);
void displaySquareTopLeftRows(int bingoCard[ROWS][COLS]);
void displaySquareBottomRightRows(int bingoCard[ROWS][COLS]);

//global variable declaration
int bingoCard[ROWS][COLS];
int choice;

int main()
{
	//function call
	printf ("BINGO Sosyal App\n\n");
	generateBingoCard(bingoCard);
	displayBingoCard(bingoCard);

	// will prompt until user inputs a 0 or are not in the choosePattern function
	do
	{
		printf("\nPattern #1. Top Row\n");
        printf("* * * * *\n\n");
        printf("\nPattern #2. Bottom Row\n");
        printf("* * * * *\n\n");
        printf("\nPattern #3. Middle Row\n");
        printf("* * * * *\n\n");
        printf("\nPattern #4. Left Column\n");
        printf("*\n*\n*\n*\n*\n");
        printf("\nPattern #5. Right Column\n");
        printf("*\n*\n*\n*\n*\n");
        printf("\nPattern #6. Middle Column\n");
        printf("*\n*\n*\n*\n*\n");
        printf("\nPattern #7. From Left to Right Diagonal\n");
        printf("*\n *\n  F\n   *\n    *\n");
        printf("\nPattern #8. From Right to Left Diagonal\n");
        printf("    *\n   *\n  F\n *\n*\n");
        printf("\nPattern #9. Square Top-Left Rows\n");
        printf("* *\n* *\n");
        printf("\nPattern #10. Square Bottom-Right Rows\n");
        printf("* *\n* *\n");

		printf("\n-----------------------------------\n");
		printf("\nEnter pattern number: ");
		scanf("%d", &choice);
		if (choice == 0)
			break;
		choosePattern(bingoCard);
		printf("\n-----------------------------------\n");
	} while (choice != 0);

	return 0;
}

//function to generate bingo card from random numbers without repetition
void generateBingoCard(int bingoCard[ROWS][COLS])
{
	srand(time(NULL));
	int numbers[75] = {0};

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i == 2 && j == 2)
			{
				bingoCard[i][j] = -1;
			}
			else
			{
				int minNumber, maxNumber;
				if (j == 0)
				{
					minNumber = 1;
					maxNumber = 15;
				}
				else if (j == 1)
				{
					minNumber = 16;
					maxNumber = 30;
				}
				else if (j == 2)
				{
					minNumber = 31;
					maxNumber = 45;
				}
				else if (j == 3)
				{
					minNumber = 46;
					maxNumber = 60;
				}
				else if (j == 4)
				{
					minNumber = 61;
					maxNumber = 75;
				}

				int randomNumber;
				do
				{
					randomNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
				} while (numbers[randomNumber - 1] != 0);
				numbers[randomNumber - 1] = 1;
				bingoCard[i][j] = randomNumber;
			}
		}
	}
}

//function to display bingo card
void displayBingoCard(int bingoCard[ROWS][COLS])
{
	printf("B\tI\tN\tG\tO\n\n");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i == 2 && j == 2)
			{
				printf("FREE	");
			}
			else
			{
				printf("%d\t", bingoCard[i][j]);
			}
		}
		printf("\n");
	}
}

//function to choose a pattern
void choosePattern(int bingoCard[ROWS][COLS])
{
	switch (choice)
	{
	case 1:
		displayTopRow(bingoCard);
		break;
	case 2:
		displayBottomRow(bingoCard);
		break;
	case 3:
		displayMiddleRow(bingoCard);
		break;
	case 4:
		displayLeftColumn(bingoCard);
		break;
	case 5:
		displayRightColumn(bingoCard);
		break;
	case 6:
		displayMiddleColumn(bingoCard);
		break;
	case 7:
		displayDiagonalLeftToRight(bingoCard);
		break;
	case 8:
		displayDiagonalRightToLeft(bingoCard);
		break;
	case 9:
		displaySquareTopLeftRows(bingoCard);
		break;
	case 10:
		displaySquareBottomRightRows(bingoCard);
		break;
	default:
		printf("Invalid choice. Please try again.");
		break;
	}
}

//function to display top row
void displayTopRow(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #1. Top Row\n");
	for (int j = 0; j < COLS; j++)
	{
		printf("%d\t", bingoCard[0][j]);
	}
	printf("\n\n\n\n");
}

//function to display bottom row
void displayBottomRow(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #2. Bottom Row\n");
	printf("\n\n\n\n");
	for (int j = 0; j < COLS; j++)
	{
		printf("%d\t", bingoCard[4][j]);
	}
}

//function to display middle row
void displayMiddleRow(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #3. Middle Row\n");
	printf("\n\n");
	for (int j = 0; j < COLS; j++)
	{
		if (j == 2)
		{
			printf("FREE	");
		}
		else
		{
			printf("%d\t", bingoCard[2][j]);
		}
	}
	printf("\n\n");
}

//function to display left column
void displayLeftColumn(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #4. Left Column\n");
	for (int i = 0; i < COLS; i++)
	{
		printf("%d\n", bingoCard[i][0]);
	}
}

//function to display right column
void displayRightColumn(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #5. Right Column\n");
	
	for (int i = 0; i < COLS; i++)
	{
		printf("\t\t\t\t%d\n", bingoCard[i][4]);
	}
}

//function to display middle column
void displayMiddleColumn(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #6. Middle Column\n");
	for (int i = 0; i < ROWS; i++)
	{
		if (i == 2)
		{
			printf("\t\tFREE\n");
		}
		else
		{
			printf("\t\t%d\n", bingoCard[i][2]);
		}
	}
}

//function to display diagonal from left to right
void displayDiagonalLeftToRight(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #7. From Left to Right Diagonal\n");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i == j)
				if (i == 2)
				{
					printf("FREE\n");
				}
				else
				{
					printf("%d\t", bingoCard[i][j]);
				}
			else
			{
				printf("\t");
			}
		}
		printf("\n");
	}
}

//function to display diagonal from right to left
void displayDiagonalRightToLeft(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #8. From Right to Left Diagonal\n");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i + j == COLS - 1)
				if (i == 2)
				{
					printf("FREE\n");
				}
				else
				{
					printf("%d\t", bingoCard[i][j]);
				}
			else
			{
				printf("\t");
			}
		}
		printf("\n");
	}
}

//function to display square top-left row
void displaySquareTopLeftRows(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #9. Square Top-Left Rows\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d\t", bingoCard[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//function to display square bottom-right row
void displaySquareBottomRightRows(int bingoCard[ROWS][COLS])
{
	printf("\nPattern #10. Square Bottom-Right Rows\n");
	printf("\n\n\n");
	for (int i = 3; i < ROWS; i++)
	{
		printf("\t\t\t");
		for (int j = 3; j < COLS; j++)
		{

			printf("%d\t", bingoCard[i][j]);
		}
		printf("\n");
	}
}