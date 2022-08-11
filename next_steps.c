//This code tests out the static key word
//all local variables are stored in the call stack
//when a function is called, the call stack sets aside memory for local variables
//The call stack is small though
//Using the keword static, we can keep the value of the variable between function calls
#include <stdio.h>

void f() {
	static int x = 5; //static changes the storage duration of a local variable from automatic to static
	printf("%d is the number\n", x);
	x++;
}

int main()
{
	f();
	f();
	f();
}