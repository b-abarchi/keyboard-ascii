// ------------------------------------
// Bello Abarchi
// date of 03/31/2017
// Exam 4
//-------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define PAUSE getchar()
#define CLS system("cls")
#define FLUSH myFlush()
#define CHAR_SIZE 95
//Function Prototype
void displayArrays(char letters[], int counts[]);
char getChoice();
void howMany(char charArray[], int a2[]);
void loadCharArray(char charArray[]);
void pressKey(char charArray[], int a2[]);
void mostPressed(char charArray[], int a2[]);
void myFlush();
void neverPressed(char charArray[], int a2[]);
void sortArray(int charArray[], int a2[], int c);
char switchValues(char charArray[], int a2[], int i);
int main() {
	//Variable Declaration
	char choice;
	int c = 95;
	char charArray[CHAR_SIZE] = { 0 };
	int a2[CHAR_SIZE] = { 0 };
	loadCharArray(charArray);
	//Menu System
	do {
		choice = getChoice();
		switch (choice) {
		case '1': // PRESS A KEY ON THE KEYBOARD
			pressKey(charArray, a2);
			PAUSE;
			break;
		case '2': // HOW MANY OF EACH KEY WAS PRESSED IN ORDER FROM (Most to Lowest)
		  sortArray(charArray, a2, c);//SORT THE ARRAY 
			howMany(charArray,a2);
			//displayArrays(charArray, a2);
			PAUSE;
			break;
		case '3': // Show Keys that were NEVER PRESSED
			neverPressed(charArray,a2);
			PAUSE;
			break;
		case '4':// Show the ONE KEY that was PRESSED THE MOST
				 mostPressed(charArray,a2);
			PAUSE;
			break;
		case 'Q':// Quits the program
			printf("\t\n\tHAVE A WONDERFULL DAY!\n");
			printf("\t\n\tSEE YOU IN COP 2220!\n");
			PAUSE;
			break;
		default: // ERROR MESSAGE
			printf("\tInvalid selection....\n");
			PAUSE;
			break;
		}//end switch
	} while (choice != 'Q');

}//end main

 //**********************************************************************************
void displayArrays(char letters[], int counts[]) {
	int i;
	for (i = 0; i < CHAR_SIZE; i++)
		if (counts[i] > 0)
			printf("\t%c\t%i\n", letters[i], counts[i]);
} // end displayArrays
void displayMenu() {
	CLS;
	printf("\n\n\n");
	printf("\t=======================================\n");
	printf("\t==         M A I N   M E N U         ==\n");
	printf("\t=======================================\n");
	printf("\t=======================================\n\n");
	printf("\t[1] Press any key(s)\n\n");
	printf("\t=======================================\n");
	printf("\t[2] How many times did you press each key\n");
	printf("\t[3] Display the keys you never pressed \n");
	printf("\t[4] Display the key pressed the most \n");
	printf("\t[Q]uit\n");
	printf("\tEnter choice: ");
}//end displayMenu
char getChoice() {
	char choice;
	displayMenu();
	scanf("%c", &choice); FLUSH;
	return toupper(choice);
}//end getChoice
void howMany(char charArray[], int a2[]) {
	int i = 0;
	for (i = 0; i < CHAR_SIZE; i++)
		if (a2[i] > 0)
			printf("\t%c has been pressed %i times\n", charArray[i], a2[i]);
}//end of howMany
void loadCharArray(char charArray[]) {
	int i = 0;
	int j = 0;
	for (i = 32, j = 0; i < 127; i++, j++)
		charArray[j] = i;
}//end of loadCharArray
void pressKey(char charArray[], int a2[]) { //PRESS A KEY ON THE KEYBOARD FUNCTION
	int i = 0;
	char key = 0;
		printf("\tPlease press a key:");
		scanf_s("%c", &key); FLUSH;
		for (i = 0; i < CHAR_SIZE; i++)
			if (key == charArray[i])
				a2[i]++;
}//end of pressKey
void mostPressed(char charArray[], int a2[]) {//  Show the ONE KEY that was pressed the most function
	int i = 0;
	for (i = 0; i < 1; i++)
		printf("\t%c is the key pressed the most", charArray[i]);
}//end of mostPressed
void myFlush() {
	while (getchar() != '\n');
}//end myFlush
void neverPressed(char charArray[], int a2[]) {//Show Keys that were NEVER PRESSED
	char neverPressed = 0;
	int i = 0;
	for (i = 0; i < CHAR_SIZE; i++)
		if (a2[i] == 0)
			printf("\tThe key %c has never been pressed\n", charArray[i]);
}//end of neverPressed
void sortArray(int charArray[], int a2[], int c) {//SORT THE ARRAY
	char switchMade = 'N'; FLUSH;
	int bottom = c - 1;
	int i;
	do {
		switchMade = 'N';
		for (i = 0; i < bottom; i++)
			if (charArray[i] < charArray[i + 1])
				switchMade = switchValues(charArray, a2, i);
		for (i = 0; i < bottom; i++)
		if (a2[i] < a2[i + 1])
			switchMade = switchValues(charArray, a2, i);
		bottom--;
	} while (switchMade == 'Y');
}//end of sortTheArray
char switchValues(char charArray[], int a2[], int i) {      //SWITCH VALUES FUNCTION 
	char temp = 0;//TEMPORARY VARIABLES
	int temp2 = 0;
	char switchMade = 'N';
	temp = charArray[i];
	charArray[i] = charArray[i + 1];
	charArray[i + 1] = temp;
	temp2 = a2[i];
	a2[i] = a2[i + 1];
	a2[i + 1] = temp2;
	return 'Y';
}//end switchValues

