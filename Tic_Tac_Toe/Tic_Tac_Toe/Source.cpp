#include <iostream>
#include <string>
using namespace std;
int counter = 0;
int choice;
string box[9] = { "1","2","3","4","5","6","7", "8", "9" };
char player1 = 'X';
char player2 = 'O';
int player = 0;
void DrawBoard()
{
	cout << "The DEFEATED tic tac toe" << endl;
	cout << endl;
	cout << "   " << box[0] << "	|   " << box[1] << "   |   " << box[2] << endl;
	cout << "--------+-------+--------" << endl;
	cout << "   " << box[3] << "	|   " << box[4] << "   |   " << box[5] << endl;
	cout << "--------+-------+--------" << endl;
	cout << "   " << box[6] << "	|   " << box[7] << "   |   " << box[8] << endl;
}
void Clear()
{
	for (int i = 0; i < 9; i++) {
		box[i] = " ";
	}
}
void X()
{
	player = 1;
	cin >> choice;
	if (choice == 0) {
		cout << "invalid input. Try again ";
		X();
	}
	else {
		if (box[choice - 1] == "O" || box[choice - 1] == "X")
		{
			cout << "invalid input. Try again ";
			X();
			return;
		}
		else
		{
			box[choice - 1] = "X";
		}
	}
}
void O()
{
	player = 0;
	cin >> choice;
	if (choice == 0) {
		cout << "invalid input. Try again ";
		O();
	}
	else {
		//box[choice -1 ] = "O";
		if (box[choice - 1] == "X" || box[choice - 1] == "O")
		{
			cout << "invalid input. Try again ";
			O();
			return;
		}
		else
		{
			box[choice - 1] = "O";
		}
	}

}
bool isWinner()
{
	if (box[0] == "X" && box[0] == box[1] && box[0] == box[2] || box[0] == "O" && box[0] == box[1] && box[0] == box[2])
	{
		return true;
	}
	else if (box[6] == "X" && box[6] == box[7] && box[6] == box[8] || box[6] == "O" && box[6] == box[7] && box[6] == box[8])
	{
		return true;
	}
	else if (box[3] == "X" && box[3] == box[4] && box[3] == box[5] || box[3] == "O" && box[3] == box[4] && box[3] == box[5])
	{
		return true;
	}
	else if (box[0] == "X" && box[0] == box[3] && box[0] == box[6] || box[0] == "O" && box[0] == box[3] && box[0] == box[6])
	{
		return true;
	}
	else if (box[1] == "X" && box[1] == box[4] && box[1] == box[7] || box[1] == "O" && box[1] == box[4] && box[1] == box[7])
	{
		return true;
	}
	else if (box[2] == "X" && box[2] == box[5] && box[2] == box[8] || box[2] == "O" && box[2] == box[5] && box[2] == box[8])
	{
		return true;
	}
	else if (box[0] == "X" && box[0] == box[4] && box[0] == box[8] || box[0] == "O" && box[0] == box[4] && box[0] == box[8])
	{
		return true;
	}
	else if (box[2] == "X" && box[2] == box[4] && box[2] == box[6] || box[2] == "O" && box[2] == box[4] && box[2] == box[6])
	{
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	int play = 1;
	DrawBoard();
	while (play == 1) {
		Clear();
		DrawBoard();
		while (counter < 9 && isWinner() == false)
		{
			cout << "Enter the value of the desired space: ";
			if (player == 0) { X(); DrawBoard(); }
			else if (player == 1) { O(); DrawBoard(); }
			counter++;
		}
		if (counter > 9 || isWinner() != true)
		{
			cout << "We have a tie!" << endl;
		}
		else {
			int x = 0;
			int y = 0;
			for (int i = 0; i < 9; i++) {
				if (box[i] == "X") {
					x++;
				}
				else if (box[i] == "O") { y++; }
			}
			if (x > y) { cout << "X is the winner!!!!" << endl; }
			else { cout << "O is the winner!!!!" << endl; }
		}
		cout << "Do you want to play again?" << endl;
		cout << "Type 1 to play again or 0 to exit!" << endl;
		cin >> play;
		player = 0;
		counter = 0;
	}
	cout << "Thanks for playing!" << endl;
	system("pause");

}
