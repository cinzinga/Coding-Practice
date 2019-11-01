#include <iostream>
using namespace std;

const int SIZE = 81;

void upper(char * input);

int main()
{
	char input[SIZE]{ 0 }; //Initialize to zero.
	cout << "Enter your sentence less than 80 characters: \n";
	cin.getline(input, SIZE);

	upper(input);

	for (int i = 0; i < SIZE; i++)
	{
		cout << input[i];

	}
	cout << endl;

	system("pause");
	return 0;
}


void upper(char * input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		char c = input[i];
		if (c >= 97 && c <= 122)
		{
			c = c - 32;
			input[i] = c;
		}
		i++;
	}
}
