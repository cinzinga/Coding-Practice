#include <iostream>
using namespace std;

int main()
{
	void initialize(char * board);
	void printBoard(char * board);
	char decideTurn(int turn);
	bool decideWinner(char * board);

	char board[9]{ 0 }; //On older versions of C++ an = sign may be needed between the array and the initalization.
	int location, turn = 0;
	bool winner = false;
	char player;
	bool valid = false;

	initialize(board);
	printBoard(board);

	while (winner != true && turn != 9)
	{
		do 
		{
			player = decideTurn(turn);
			cout << "Player " << player << "'s turn: ";
			cin >> location;
			location--;

			valid = (board[location] != 'X' && board[location] != 'O');

			if (valid)
			{
				board[location] = player;
				printBoard(board);
				turn++;
				winner = decideWinner(board);
			}
			else
			{
				cout << "That spot is taken.\n";
			}
		}
		while (!valid && !winner);
		
	}

	if (turn == 9)
	{
		cout << "Tie.\n";
	}
	else
	{
		cout << "The winner is " << player << endl;
	}


	system("pause");
	return 0;
}

void initialize(char * board)
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = i + '1';
	}
}

void printBoard(char * board)
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0) cout << endl;
		cout << board[i] << " ";
	}
	cout << endl;
}

char decideTurn(int turn)
{
	if (turn % 2 == 0)
	{
		return 'X';
	}
	else
	{
		return 'O';
	}
}

bool decideWinner(char * board)
{
	if (board[0] == board[1] && board[1] == board[2])
	{
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5])
	{
		return true;
	}
	else if (board[6] == board[7] && board[7] == board[8])
	{
		return true;
	}
	else if (board[0] == board[3] && board[3] == board[6])
	{
		return true;
	}
	else if (board[1] == board[4] && board[4] == board[7])
	{
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[8])
	{
		return true;
	}
	else if (board[0] == board[4] && board[4] == board[8])
	{
		return true;
	}
	else if (board[2] == board[4] && board[4] == board[6])
	{
		return true;
	}
	else
	{
		return false;
	}
}
