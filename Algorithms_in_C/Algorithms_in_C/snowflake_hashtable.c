//This program is a more efficient way of solving the snowflakes.c program
//In snowflakes.c, we compared every single snowflake to one another
//Making our program run at O(n^2)
//For this code, we will weed out the snowflakes that we know are no alike by
//get the sum of the elements
//We will then use that sum as the index to make similar snowflakes beside each other in our array

//We will use a hash table and use the mod operator to store this sum code in an array of 100000 elements
//index between 0 and 99999

//We will used a linked list implementation in our hash table to deal with collisions (Chaining)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100000

//This structure defines our linked list in case of collisions
//It contains the node itself and the pointer to the next node
//typedef allows us to use the name "snowflake_node" to represent this strcuture
typedef struct snowflake_node {
	int snowflake[6];
	struct snowflake_node* next;
} snowflake_node;

//Function prototypes
int element_sum(int snowflakes[]);
void identify_identical(snowflake_node* snowflakes[]);
int are_identical(int snow1[], int snow2[]);
int identical_right(int snow1[], int snow2[], int start);
int identical_left(int snow1[], int snow2[], int start);

int main() {
	static snowflake_node *snowflakes[SIZE] = { NULL }; //This initializes a one dimensional array of pointers to snowflake nodes
	snowflake_node *snow; //This will point to the snowflake nodes that we allocate

	int n, index; //n is number of snowflakes - index is index returned by our element_sum function

	//Read in the number of snowflakes and allocate memory for the amount of snowflakes
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		snow = malloc(sizeof(snowflake_node)); //Manually allocates space for each snowflake node
		if (snow == NULL) {
			fprintf(stderr, "malloc error\n"); //Throws an error if there is no space to allocate
			exit(1);
		}
	}

	//Read the values of each snowflake
	for (int j = 0; j < 6; j++) {
		scanf_s("%d", &snow->snowflake[j]); //The -> operator allows us to access a member of our structure using pointers
	}

	index = element_sum(snow->snowflake); //Stores our element sum index in index
	//These two lines sets the snowflake node's value and points it to the next node
	snow->next = snowflakes[index]; 
	snowflakes[index] = snow; //Points toward the node we just inserted

	return 0;
}

//This function sums the elements of the snowflakes and then gets the mod of 100000 to be used as an index in our hash table
int element_sum(int snowflakes[]) {
	return((snowflakes[0] + snowflakes[1] + snowflakes[2] + snowflakes[3] + snowflakes[4]
		+ snowflakes[5]) % SIZE);
}

//This function compares node1 to each of the nodes in the linked list to see if the snowflakes are equal
//If they are not, it moves node1 to the next node in the linked list and repeats this process
//We do this because only snowflakes with the same index will be of equal value
//therefore, we do not have to compare as many snowflakes...we only compare the snowflakes located at the
//same place in the array via a linked list
void identify_identical(snowflake_node* snowflakes[]) {
	snowflake_node* node1, * node2;

	for (int i = 0; i < SIZE; i++) {
		node1 = snowflakes[i]; //set node1 to our first present element in the array (also the first node in the linked list)
		while (node1 != NULL) {
			node2 = node1->next;
			while (node2 != NULL) {
				if (are_identical(node1->snowflake, node2->snowflake)) {
					printf("Twin snowflakes found\n");
					return;
				}
				node2 = node2->next;
			}
			node1 = node1->next;
		}
	}
	printf("There are no two snowflakes alike\n");
}

int are_identical(int snow1[], int snow2[]) {

	for (int start = 0; start < 6; start++) {
		if (identical_right(snow1, snow2, start)) {
			return 1;
		}
		if (identical_left(snow1, snow2, start)) {
			return 1;
		}
	}
	return 0;
}

int identical_right(int snow1[], int snow2[], int start) {

	for (int offset = 0; offset < 6; offset++) {
		if (snow1[offset] != snow2[(offset + start) % 6]) {
			return 0;
		}
	}
	return 1;
}

int identical_left(int snow1[], int snow2[], int start) {

	int snow2_index;
	for (int offset = 0; offset < 6; offset++) {
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
