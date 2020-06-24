#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
void menu(void)
{
	int choice;
	printf(" _______________________________________________________________\n");
	printf("|-----------------------AKROSTOIXIDA----------------------------|\n");
	printf("|---------------------------MENU--------------------------------|\n");
	printf("|-------------------1.START-2.HELP-3.CREDITS--------------------|\n");
	printf("|------------------PLEASE ENTER YOUR CHOICE---------------------|\n");
	printf("|_______________________________________________________________|\n");
	printf("choice:");
	scanf("%d",&choice);
	printf("\n");
	switch(choice)
	{
		case 1:
			
			break;
		case 2:
			
		printf(" _______________________________________________________________\n");
		printf("|YOU MUST WRITE ONE OF BELOW COMMANDS---------------------------|\n");
		printf("|*INSERT-------EX(INSERT:<SPACE>...)----------------------------|\n");
		printf("|*DELETE-------EX(DELETE:<SPACE>...)----------------------------|\n");
		printf("|*SHOWFWD-------EX(SHOWFWD:<SPACE> NUM ...)---------------------|\n");
		printf("|*SHOWREV-------EX(SHOWREV:<SPACE> NUM ...)---------------------|\n");
		printf("|*FIND-------EX(FIND:<SPACE>  WORD NUM ...)---------------------|\n");
		printf("|*CREATE-------EX(CREATE:<SPACE> WORD LEVEL(WORD) ...)----------|\n");
		printf("|*LOAD-------EX(LOAD:<SPACE> WORD...)---------------------------|\n");
		printf("|*SAVE-------EX(SAVE:<SPACE> WORD...)---------------------------|\n");
		printf("|*CHECK-------EX(CHECK)-----------------------------------------|\n");
		printf("|*EXIT-------EX(EXIT)-------------------------------------------|\n");
		printf("|_______________________________________________________________|\n");
		break;
		case3:
		
		printf(" _______________________________________________________________\n");
		printf("|THIS APPLICATION WAS CREATED BY :------------------------------|\n");
		printf("|*NIKOLAOS-SPYRIDON KOUTROUMANIS -------------------------------|\n");
		printf("|*KONSTANTINOS LALOUDAKIS---------------------------------------|\n");
		printf("|_______________________________________________________________|\n");
		break;
	}
}
