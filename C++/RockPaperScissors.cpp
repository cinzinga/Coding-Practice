#include <iostream>
#include <ctime>
using namespace std;

//Define the constants needed for this program
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

//Prototype the 4 functions that will be used in this code
int getUserChoice(); //Gets the user's choice, returns an int.
int getCompChoice(); //Generates the computer's choice, returns an int.
void displayChoice(int choice); //Converts the user's choice from a number to text.
void displayCompChoice(int choice); //Converts the computer's choice from a number to text.
void determineWinner(int userChoice, int compChoice); //Determines the winner.

int main()
{
	//Define the necessary variables.
	int userChoice, compChoice;

	//Print the game menu.
	cout << "Game Menu\n";
	cout << "---------\n";
	cout << "[1] Rock\n";
	cout << "[2] Paper\n";
	cout << "[3] Scissors\n";
	cout << "[4] Quit\n\n";

	//Assignes output of functions to local variables.
	compChoice = getCompChoice();
	userChoice = getUserChoice();

	//Runs until the user quits.
	while (userChoice != QUIT)
	{
		//Determins the winner based off the choices above.
		determineWinner(userChoice, compChoice);
		
		//Print's game menu again.
		cout << "\nGame Menu\n";
		cout << "---------\n";
		cout << "[1] Rock\n";
		cout << "[2] Paper\n";
		cout << "[3] Scissors\n";
		cout << "[4] Quit\n\n";

		//Assigns output of functions to local variables.
		compChoice = getCompChoice();
		userChoice = getUserChoice();
	}

	return 0;

}

//Asks the user for their choice (1-4) and returns that int.
int getUserChoice()
{
	int userChoice;
	cout << "Enter your choice: ";
	cin >> userChoice;
	return userChoice;
}

//Randomly generates the computer's choice, returns a number between 1-3.
int getCompChoice()
{
	int compChoice;
	srand(time(0));
	compChoice = (rand() % 3) + 1;
	return compChoice;
}

//Translates the user's choice (int) to user friendly text.
void displayChoice(int choice)
{
	if (choice == ROCK)
	{
		cout << "You selected: Rock\n";
	}
	else if (choice == PAPER)
	{
		cout << "You selected: Paper\n";
	}
	else if (choice == SCISSORS)
	{
		cout << "You selected: Scissors\n";
	}
}

//Translates the computer's choice (int) to user friendly text.
void displayCompChoice(int choice)
{
	if (choice == ROCK)
	{
		cout << "The computer selected: Rock\n";
	}
	else if (choice == PAPER)
	{
		cout << "The computer selected: Paper\n";
	}
	else if (choice == SCISSORS)
	{
		cout << "The computer selected: Scissors\n";
	}
}

//Compares the user's choice to the computer's choice to determine the winner.
void determineWinner(int userChoice, int compChoice)
{
	//Displays the user's numerical choice as text
	displayChoice(userChoice);
	displayCompChoice(compChoice);

	//If the choices are equal it will be a tie.
	if (userChoice == compChoice)
	{
		cout << "Tie. No winner\n";
	}
	else if (userChoice == 1 && compChoice == 2)
	{
		cout << "You lose. Paper beats rock.\n";
	}
	else if (userChoice == 1 && compChoice == 3)
	{
		cout << "You win. Rock beats scissors.\n";
	}
	else if (userChoice == 2 && compChoice == 1)
	{
		cout << "You win. Paper beats rock.\n";
	}
	else if (userChoice == 2 && compChoice == 3)
	{
		cout << "You lose. Scissors beat paper.\n";
	}
	else if (userChoice == 3 && compChoice == 1)
	{
		cout << "You lose. Rock beats scissors.\n";
	}
	else if (userChoice == 3 && compChoice == 2)
	{
		cout << "You win. Scissors beat paper.\n";
	}
}
