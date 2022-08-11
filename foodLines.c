//There a n lines of people waiting for food(The number of people in each line is given).
//Each new person (m) will get into the shortest line.
//Determine the number of people in each line that the mth person joins

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINES 100 //Defined as the Max number of lines in the problem (uses #define to declare a constant)

//Function prototypes
int shortest_line_index(int lines[], int n);
void solve(int lines[], int n, int m);

int main() {
	int lines[MAX_LINES]; //Defines a line array to store the number of people
	int n, m, i; //Defines n (number of lines), m (number of new people coming), and i (index iterator)
	scanf_s("%d%d", &n, &m); //Reading in the values for n and m... should work for multiple test cases

	//This block of code reads the input of how many people are in each line
	for (i = 0; i < n; i++) {
		scanf_s("%d", &lines[i]);
	}

	solve(lines, n, m);
	return 0;
}

//This function returns the index of the shortest line (***The index is also the line number that has the shortest amount of people)
int shortest_line_index(int lines[], int n) {
	int shortest = 0;

	for (int j = 1; j < n; j++) {
		if (lines[j] < lines[shortest]) {
			shortest = j;
		}
	}
	return shortest;

}

//This function displays how many people are in the line that the mth person gets in (the answer we want)
void solve(int lines[], int n, int m) {
	int shortest;
	for (int i = 0; i < m; i++) {
		shortest = shortest_line_index(lines, n);
		printf("%d\n", lines[shortest]);
		lines[shortest]++; //Increment the line that the mth person just joines becasue it has a new person in it
	}
}