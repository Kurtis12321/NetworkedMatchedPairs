#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//ensures that the system clock is set

void main()
{
	char player1[30];				//this sets the variable for name entry to 30 characters
	srand(time(NULL));				//this command is only required at the start and sets the clock

	printf("Please enter your name? - ");
	scanf("%s", player1);			//this command is used to store the players name for us later on within the game
	printf("\n\n");

	//The following printf commands issue the rules of the game and ensure that they are printed and viewable
	printf("Welcome %s to the Pairs (Matching Game)\n\n", player1);
	printf("The rules of the game are as follows\n\n");
	printf(" 1. The player should enter a location of card 1 and card 2\n\n");
	printf(" 2. The player should only use a numeric format to enter the\n    location of the card i.e. 11 and 44 this would show only\n    Line 1 box 1 and line 4 box 4\n\n");
	printf(" 3. Should the player enter a location outside of the table\n    range 'You have incorrectly selected a location, please\n    try again' will be displayed\n\n");
	printf(" 4. A player should select 2 cards to be shown if they match\n    the cards are removed\n\n");
	printf(" 5. If a player selects a non matching pair 'Please try again\n    - you've selected an non matching pair' should be displayed\n\n");
	printf(" 6. The object of the game is to match all the pairs in the \n    least amount of turns possible\n\n");
	printf(" 7. The player cannot use any symbol !£$%^&*@~? as these will\n    not be recognised by the game and cause it to freeze resulting\n    in a restarted game\n");

	printf("\n");

	char ag = ' ';		//this is the variable used to denote the answer for play again question
	do {				//the do command is the start of the loop this will ensure the game is played through once
		char grid[17] = { 'a', 'a', 'b', 'b', 'c', 'c', 'd', 'd', 'e', 'e', 'f', 'f', 'g', 'g', 'h', 'h' };		//sets the characters used in the grid
		int high = 15;
		int random, random2, temp, card1, card2;
		int low = 0;
		int counter = 0;
		int x = 0;
		int flag = 0;			//this variable is used to identify potential issues
		int turns = 0;			//identifies the variable for the amount of turns taken

		for (x = 1; x < 100; x++)			//sets the random loop to vary the selection 100 times prior to selecting a game table
		{
			random = rand() % (high - low + 1) + low;
			random2 = rand() % (high - low + 1) + low;
			temp = grid[random];
			grid[random] = grid[random2];
			grid[random2] = temp;
		}

		while ((grid[0] != 'x') || (grid[1] != 'x') || (grid[2] != 'x') || (grid[3] != 'x') || (grid[4] != 'x') || (grid[5] != 'x') || (grid[6] != 'x') || (grid[7] != 'x') || (grid[8] != 'x') || (grid[9] != 'x') || (grid[10] != 'x') || (grid[11] != 'x') || (grid[12] != 'x') || (grid[13] != 'x') || (grid[14] != 'x') || (grid[15] != 'x'))
		{

			for (x = 0; x < 16; x++)
			{
				counter++;
				//printf("| %c ", grid[x]);	//The grid is shown using this command for testing purposes only must be removed prior to playing

				if (counter == 4)
				{
					printf("\n");
					counter = 0;
				}

			}

			printf("\n");
			printf(" Please enter Card 1 : ");	//Enter the location of your first card
			scanf("%d", &card1);				//Displays your first card
			printf(" Please enter Card 2 : ");	//Enter the location of your next card
			scanf("%d", &card2);				//Displays your second card
			printf("");
			turns = turns + 1;					//the turns variable has been set to count every attempt at matching cards

			//array of allowed inputs
			int user_input[16] = { 11, 12, 13, 14, 21, 22, 23, 24, 31, 32, 33, 34, 41, 42, 43, 44 };

			for (int i = 0; i < 16; i++)
			{
				if (user_input[i] == card1)
				{
					card1 = i;
				}
				if (user_input[i] = card2)
				{
					card2 = i;
				}
			}

			//printf("\n\nCARD 1: %d\n", card1);		//printf shows the location of the card selected from 0 to 15 (remove after testing)
			//printf("CARD 2: %d\n\n", card2);		//printf shows the location of the card selected from 0 to 15 (remove after testing)

			if (((card1 < 0) || (card1 > 15)) || ((card2 < 0) || (card2 > 15)))
			{
				printf("\nYou have incorrectly selected a location, please try again\n\n");
				flag = 1;
				//	printf("Flag=%d\n", flag);		//This printf command is just for testing remove prior to playing the game
			}

			counter = 0;						//This resets the counter

			for (x = 0; x < 16; x++)		// this means it will only loop the count 16 times
			{
				counter++;		// this will add 1 to the counter
				printf("|   ");

				if (card1 == x)
				{
					printf("%c", grid[card1]);
				}
				else if (card2 == x)
				{
					printf("%c", grid[card2]);
				}
				else
				{
					printf(" ");
				}

				if (counter > 3)
				{
					printf("\n");
					counter = 0;	// This will reset the counter back to zero 

				}
			}
			if ((grid[card1] == 'x') || (grid[card2] == 'x'))		//This 'if statment' states if you have made the choice 
			{
				printf("\nUnfortunately you have selected a card already match, please try again\n\n");
			}
			if ((grid[card1] == grid[card2]) && (grid[card1] != 'x') && (grid[card2] != 'x') && (flag == 0)) //This is the 'if statment' that will match the pairs and then mark them as 'x' 
			{
				printf("\nCongratulations you have found a pair!!\n");
				grid[card1] = 'x';
				grid[card2] = 'x';
			}

			if (((grid[card1] != grid[card2]) && (grid[card1] != 'x') && (grid[card2] != 'x')) && (flag == 0)) //This 'if statment' states if the guesses are incorrect
			{
				printf("\nOopps remember the cards as you need to try again\n\n");
			}
		}
		printf("\nExcellent %s you have managed to match all the cards correctly in %d turns\n\n", player1, turns);
		printf("Do you want to play again? (y/n)\n\n");
		scanf(" %c", &ag);
		printf("\n\n");

	} while ((ag == 'y') || (ag == 'Y')); //This is the exit statement from the program and ensures that the game can be played on if 'Y' is selected
	printf("\n\nThanks for playing see you again sometime for another \nthrilling game of Matching Pairs!!!\n\n");
}