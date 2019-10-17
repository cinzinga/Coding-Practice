#include <stdio.h>

//This program prints numbers 1 to 100, appending the word Fizz if it is divisible by 3, Buzz if it is divisible by 5, and FizzBuzz if it is divisible by both.

int main() 
{
	for(int i = 1; i <= 100; i++) 
	{
		if (i % 15 == 0) 
		{
			printf("%d FizzBuzz\n",i);
		}
		else if(i % 5 == 0) 
		{
			printf("%d Buzz\n", i);
		}
		else if(i % 3 == 0) 
		{
			printf("%d Fizz\n", i);
		}
		else 
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
