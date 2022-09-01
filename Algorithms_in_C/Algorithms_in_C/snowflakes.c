//Snowflake Problem - In this problem, we are given a collection of snowflakes, each with six sides
//A snowflake is represented by six integers (each integer is the length of one of the snowflake's arms
//EX: a snowflake could be 3, 9, 15, 2, 1, 10 (they can also have repeated integers
//***We need to determine if any of the snowflakes in the collection are identical
//If a snowflake is identical, if the integers match each other (no matter where they start)
//EX of being Identical: 1, 2, 3, 4, 5, 6 & 1, 2, 3, 4, 5, 6 (These match up in each corresponding position)
//1, 2, 3, 4, 5, 6 & 4, 5, 6, 1, 2, 3 (If you start at 1 on the second snowflake and move right you get the same order as the first snowflake)
//1, 2, 3, 4, 5, 6 & 3, 2, 1, 6, 5, 4 (If you start at 1 on the second snowflake and move left you get the same order as the first snowflake)

//Input - The first line of input is n - the number of snowflakes we process (between 1 and 100,000)
// Each following line represents one snowflake (each six integers between 0 and 10,000,000)

//Output - If there are no snowflakes alike print out "There are no two snowflakes alike"
//If there are alike snowflake print out "Twin snowflakes found"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIDES 6
#define SIZE 10000000

void identify_identical(int snowflakes[][SIDES], int);
int identical_right(int snow1[], int snow2[], int start);
int identical_left(int snow1[], int snow2[], int start);
int are_identical(int snow1[], int snow2[]);

int main() {
	static int snowflakes[SIZE][SIDES]; //We use static here because the amount of size that needs to be allocated for this array is very large
	int n; //This is the number of snowflakes we will be processing
	printf("Enter the number of snowflakes: ");
	scanf_s("%d", &n);

	printf("Enter the six sides for each snowflake: \n");
	//Each of the next lines will be considered as one individual snowflake
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < SIDES; j++) {
			scanf_s("%d", &snowflakes[i][j]);
		}
	}
	identify_identical(snowflakes, n);

	return 0;
}

void identify_identical(int snowflakes[][SIDES], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (are_identical(snowflakes[i], snowflakes[j])) {
				printf("Twin snowflakes were found\n");
				return;
			}
		}
	}
	printf("There were no alike snowflakes!\n");
}


//Offset and start are the indexes of the two snowflakes being compared
//By using the mod operator, we can "wrap around" our snowflake and make sure we do no
//go out of the range of the array
int identical_right(int snow1[], int snow2[], int start) {

	for (int offset = 0; offset < SIDES; offset++) {
		if (snow1[offset] != snow2[(offset + start) % 6]) {
			return 0;
		}
	}
	return 1;
}

//This function is very similiar to indentical_right, but instead of using the mod operator,
//we check to see if the index for snow 2 has gone below 0
//If it has, we "wrap around" to the end of the array by adding 6
int identical_left(int snow1[], int snow2[], int start) {
	
	int snow2_index;
	for (int offset = 0; offset < SIDES; offset++) {
		snow2_index = start - offset;
		if (snow2_index < 0) {
			snow2_index = snow2_index + 6;
		}
		if (snow1[offset] != snow2[snow2_index]) {
			return 0;
		}
	}
	return 1;
}

int are_identical(int snow1[], int snow2[]) {
	
	for (int start = 0; start < SIDES; start++) {
		if (identical_right(snow1, snow2, start)) {
			return 1;
		}
		if (identical_left(snow1, snow2, start)) {
			return 1;
		}
	}
	return 0;
}