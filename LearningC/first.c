//My first program in C
//Make sure to specify the type of data you a are reading when using scanf
//I got an erro with scanf so I used scanf_s (more secure?)
//Also pass the data's address when using scanf_s

#include <stdio.h>

int main() {

	int num;
	printf("Hello User!\nWelcome to my first C program\nLet's start with an easy question\nWhat is your favorite number?: ");
	scanf_s("%1d", &num); //%1f specifies a double data type

	if (num < 0) {
		printf("You have typed in a negative number!");
	}
	else if (num > 0) {
		printf("You have typed in a positive number");
	}
	else {
		printf("I have no clue what you typed in!");
	}

}