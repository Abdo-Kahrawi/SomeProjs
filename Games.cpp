#include <iostream>

#include <iomanip>

#include <cmath>

#include <string>

using namespace std;

//Battleships Game's functions

void Print2Array(int [][5],const int row,const int column);

//Tic Tac Toe Game's functions

void DrawBoard(char[3][3]);

bool CheckWin(char[3][3], char);

bool CheckDraw(char[3][3], int, int);


int main() {

	// Battleships Game

	/*int NumofHits = 0; int NumofTurns= 0; const int RowNum = 5; const int ColNum = 5;

	int arrgame[RowNum][ColNum] = { 
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1},
	};

	cout << "This is a simple game called, Battleship. You would select potential coordinates where the ships could be, or not. \n Enjoy!\n";


	while (NumofHits < 4) {

		int row, column;

		cout << "Guess the number of the row: (from 0 to 4 only) "; cin >> row;

		cout << "Guess the number of the column: (from 0 to 4 only)  "; cin >> column;

		if (arrgame[row][column] == 1) {

			arrgame[row][column] = 0;

			NumofHits++;

			cout << "HIT! Your one step closer to wining and " << 4 - NumofHits << " Left! \n";
		}
		else if (row > 4 || column > 4) {
			cout << "That's invalid input. Try again.\n";
		}
		else {
			cout << "Missed! Try again, looser!";
		}

		NumofTurns++;
	}

	cout << "Victory! You won in " << NumofTurns << " times\n"; 

	cout << "Map of Ships Printed: \n"; Print2Array(arrgame, RowNum, ColNum);*/

	// Tic Tac Toe Game

	char board[3][3] = { 
		{' ', ' ', ' '},
		{' ', ' ', ' '}, 
		{' ', ' ', ' '}
	};

	int row, column, turn, Xcounter, Ocounter, yesorno, Usercounter; char player1 = 'X'; char player2 = 'O'; turn = 0; char userchar; string Conorend;

	Xcounter = 0; Ocounter = 0; Usercounter = 0;

	cout << "Welcome to our game: TIC TAC TOE \n";

	for (int i = 0; turn < 9; i++) {

		DrawBoard(board);


		while (true) {
			
			switch (Usercounter) {
			case 0:
				cout << "Who are you? Choose X or O: "; cin >> userchar;

				if (userchar == 'X')

					userchar = 'X';

				else if (userchar == 'O')

					userchar = 'O';

				else {
					cout << "Invalid Input. Try again. (X or O)\n"; cin >> userchar;

					userchar = ' ';
				}
				break;
			default: if (userchar == 'X') {
				cout << "Now, it's Player O's turn to play: "; cin >> userchar;
			}
				   else {
				cout << "Now, it's Player X's turn to play: "; cin >> userchar;

			       }
			}

			cout << "Enter row and column (from 0 to 2 only): ";

			cin >> row >> column;

			Usercounter++;


			if (board[row][column] != ' ' || row < 0 || row > 2 || column < 0 || column > 2)

				cout << "Invalid Input or move. Try AGAIN!\n";

			else
				break;
		}
		

		board[row][column] = userchar;

		if (CheckWin(board, userchar)) {

			DrawBoard(board);

			if (userchar == 'X')

				Xcounter++;

			else

				Ocounter++;


			cout << "Player " << userchar << " is the WINNER!\n" << setw(10) << "X Player won " << Xcounter << " times\n" << setw(10) << "O Player won " << Ocounter << " times\n";


			cout << "Want to continue? Enter 1 now!: "; cin >> yesorno;

			if (yesorno== 1) 

				continue;
			
			else

			    break;
			
		}
		if (CheckDraw(board,3,3))
		{
			cout << "Draw!! How close that was! Want to continue? Enter 1 now!: "; cin >> yesorno;

			if (yesorno == 1)

				continue;

			else

				break;
		}
	}
		


	return 0;
} 

void DrawBoard(char board[3][3]) {

	cout << setw(3);

	for (int k = 0; k < 18; k++) {

		cout << "-";
	}

	for (int i = 0; i < 3; i++) {

		cout << endl << setw(3) << "|";

		for (int j = 0; j < 3; j++) {

			cout << setw(3) << board[i][j] << setw(3) << "|";
		}
		cout << endl;
	}
	
	cout << setw(3);

	for (int l = 0; l < 18; l++) {

		cout << "-";
	}
	cout << endl;

}

bool CheckWin(char board[3][3], char XorO) {

	for (int i = 0; i < 3; i++) {

		if (board[i][0] == XorO && board[i][1] == XorO && board[i][2] == XorO)
			return true;

		if (board[0][i] == XorO && board[1][i] == XorO && board[2][i] == XorO)
			return true;
	}

	if (board[0][0] == XorO && board[1][1] == XorO && board[2][2] == XorO)
		return true;

	if (board[0][2] == XorO && board[1][1] == XorO && board[2][0] == XorO)
		return true; 
		
	return false;
}

bool CheckDraw(char board[3][3], int row, int column) {

	bool draw = false;

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < column; j++) {

			if (board[i][j] != ' ')
				draw = true;
			else {
				draw = false; break;
			}
		}

	}
	switch (draw) {
	case true: return draw; break;

	default: return draw;
}
}



void Print2Array(int arr[][5],const int row,const int column) {

	cout << "{";

	for (int i = 0; i < row; i++) {

			for (int j = 0; j < column; j++) {

				if (j == column - 1) {
					cout << arr[i][j]; break;
				}

				cout << arr[i][j] << ", ";
			}
			switch (i) {

			case 4: cout << "}" << endl; break;

			default: cout << "}," << endl << "{";
			}
	}
}