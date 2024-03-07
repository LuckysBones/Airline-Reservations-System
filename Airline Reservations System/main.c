/*Luc Gremillion
  March 5, 2023
  C Programming
  Rebecca Dewitt*/

//6.21 - (Airline Reservations System) A small airline has just
//purchased a computer for its new automated reservations system.
#include <stdio.h>
#include <stdbool.h>

//Constant Variable
#define LENGTH 10

//Function Prototypes 
int fullPlane(int seats[], int t);
int firstClass(int seats[]);
int economyClass(int seats[]);

//Main Function
void main() {

	//Declare variables
	int seats[LENGTH] = {0,0,0,0,0,0,0,0,0,0};
	int flag = 0;

	//While loop controls where the user wants to place there seat
	while (flag != -1) {
		//Prompt and input so system know where to send the user
		printf("Please type 1 for - First Class\n" 
			"Please type 2 for - Economy\nPlease type -1 to leave: ");
		scanf_s("%d",&flag);
		if (flag == 1) {
			firstClass(seats);
		}
		else if (flag == 2) {
			economyClass(seats);
		}
		puts("");
		//tests to see if the plane still has room or not
		flag = fullPlane(seats, flag);
	}
	
	puts("");
	
}

//Function test the array to see if there are any open seats
int fullPlane(int seats[], int flag) {
	//Declare variables
	int isFull = 0;

	//For-loop to count total seats used
	for (int x = 0; x < LENGTH; x++) {
		if (seats[x] == 1)
			isFull++;
	}
	//returns the flag to end a loop
	if (isFull == LENGTH) {
		puts("Plane is Full, the Next flight leaves in 3 hours");
		return -1;
	}
	return flag;
}

//function places a user in a first class seat
int firstClass(int seats[]) {
	//Declare variables
	bool flag = true;
	int pos = 0, goToEco = 0;

	//While loop places a user in first class if there is room
	while(flag == true){
		if (seats[pos] == 0 && pos != 5) {
			seats[pos] = 1;
			pos++;
			flag = false;
			printf("\nFirst Class Seat Placed - Seat Number %d\n", pos);
		}
		else if (pos == 5) {
			printf("\nNo more seats in first class is it acceptable to be placed in the economy section[1-yes|0-no]? ");
			scanf_s("%d",&goToEco);
			if (goToEco == 1) {
				economyClass(seats);
			}
			else {
				puts("\nNext flight leaves in 3 hours.");
			}
			flag = false;
		}
		else {
			pos++;
		}
	}
	return *seats;
}

int economyClass(int seats[]) {
	//Declare variables
	bool flag = true;
	int pos = 5;

	//While loop places a user in economy class while there is room
	while (flag == true) {
		if (seats[pos] == 0 && pos != 10) {
			seats[pos] = 1;
			pos++;
			flag = false;
			printf("\nEconomy Class Seat Placed - Seat Number %d\n", pos);
		}
		else if (pos == LENGTH) {
			puts("No more seats on the Plane!\nThe next flight leaves in 3 hours.");
			flag = false;
		}
		else {
			pos++;
		}
	}
	return *seats;
}
