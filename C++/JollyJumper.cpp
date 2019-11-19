#include <iostream>
using namespace std;

int main()
{
	int num, diff;
	int * array;

	cout << "How many numbers will you enter?: ";
	cin >> num;

	while (num <= 0)
	{
		cout << "Array size cannot be negative!\n";
		cout << "How many numbers will you enter?: ";
		cin >> num;
	}

	array = new int[num];

	for (int i = 0; i < num; i++)
	{
		cout << "Enter number " << (i + 1) << ": ";
		cin >> array[i];
	}

	bool * diffArray;
	diffArray = new bool[num - 1];

	for (int i = 0; i < (num - 1); i++) // This should create an array all false.
	{
		diffArray[i] = false;
	}

	for (int i = 0; i < (num - 1); i++)
	{
		diff = abs(array[i] - array[i + 1]);
		if (diff == 0 || diff > num - 1 || diffArray[diff] == true)
		{
			cout << "Not Jolly\n";
			delete [] array;
			delete [] diffArray;
			return 0;
		}
		diffArray[diff] = true;
	}

	cout << "Jolly!\n";

	delete [] array;
	delete [] diffArray;
	return 0;
}


/*
TEST CASES:
How many numbers will you enter?: 4
Enter number 1: 1
Enter number 2: 4
Enter number 3: 2
Enter number 4: 3
Jolly!

How many numbers will you enter?: 4
Enter number 1: 1
Enter number 2: 3
Enter number 3: 5
Enter number 4: 7
Not Jolly
*/

