#include<iostream>
#include<windows.h>
#include<conio.h>



using namespace std;

#define UP		119  // w
#define DOWN	115  // s
#define LEFT	97   // a
#define RIGHT   100  // d
#define OK		13   // enter

int a[100][100];
int turn = 0;
int x = 12;
int y = 6;
int p1 = 0;	// score of the player 1
int p2 = 0; // score of the player 2
int turnChange = 0;

struct Coords {
	int x;
	int y;
};
Coords chance[4];

void txtColor(int color);
void gotoxy(int x, int y);
void frame();
void play();
int  win();
void score();
void ratioFrame();
void instruction();

int main() {
	SetConsoleTitle("Game : Caro . Developer : Thu Vo");
	frame();
	ratioFrame();
	gotoxy(x, y);
	play();
	_getch();
	return 0;
}

void txtColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void start() {
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<100; j++) {
			a[i][j] = 0;
		}
	}
}

void frame() {
	txtColor(7);
	for (int i = 0; i < 40; i++) {
		gotoxy(10 + i, 3);
		cout << char(220);
		gotoxy(10 + i, 20);
		cout << char(223);
	}
	for (int i = 4; i <= 19; i++) {
		gotoxy(10, i);
		cout << char(219);
		gotoxy(49, i);
		cout << char(219);
	}
	int k = 1;
	for (int i = 11; i <= 48; i++) {
		for (int j = 4; j <= 19; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					gotoxy(i, j);
					txtColor(0);
					cout << char(219);
				}
				else {
					gotoxy(i, j);
					txtColor(7);
					cout << char(219);
				}
			}
			else {
				if (j % 2 == 0) {
					gotoxy(i, j);
					txtColor(7);
					cout << char(219);
				}
				else {
					gotoxy(i, j);
					txtColor(0);
					cout << char(219);
				}
			}
		}
	}
	txtColor(14);
	gotoxy(10, 21);
	cout << "Developer : Thu Vo.";
	gotoxy(10, 22);
	instruction();
}

void play() {
	score();
	gotoxy(x, y);
	if (win()) {
		gotoxy(10, 1);
		cout << "                                                              ";
		gotoxy(10, 1);
		cout << "Player " << win() << " won.";
		if (win() == 1) p1++; else p2++;
		for (int k = 0; k<4; k++) {
			gotoxy(chance[k].x, chance[k].y);
			txtColor(13);
			if (win() == 1) {
				cout << "o";
			}
			else {
				cout << "x";
			}
		}
		_getch();
		gotoxy(10, 1);
		cout << "                                                  ";
		gotoxy(10, 1);
		cout << "Want to play again (y/n)?";
		char ch = _getch();
		if ((ch == 'y') || (ch == 'Y')) {
			gotoxy(10, 1);
			turnChange++;
			if (turnChange % 2 == 0) turn = 0;
			else turn = 1;
			cout << "                                  ";
			start();
			frame();
			ratioFrame();
			gotoxy(x, y);
			play();
		}
		else {
			exit(0);
		}

	}
	char ch = _getch();
	// Should use switch();
	if (ch == 104) {

		txtColor(10);
		if (turn % 2 == 0) { // a tight game
			gotoxy(15, 1);
			cout << "Does the player 2 accept ? y/n";
			char CHAR = _getch();
			if ((CHAR == 'y') || (CHAR == 'Y')) {
				gotoxy(10, 1);
				turnChange++;
				if (turnChange % 2 == 0) turn = 0;
				else turn = 1;
				cout << "                                                 ";
				start();
				frame();
				ratioFrame();
				gotoxy(x, y);
				play();
			}
			else {
				gotoxy(15, 1);
				cout << "                                              ";
				gotoxy(15, 1);
				cout << "The player 2 didn't accept a tight game ";
				gotoxy(15, 1);
				_getch();
				cout << "                                        ";
				cout << "                                                                     ";
			}
		}
		else {
			gotoxy(15, 1);
			cout << "Does the player 1 accept ? y/n";
			char CHAR = _getch();
			if ((CHAR == 'c') || (CHAR == 'C')) {
				gotoxy(10, 1);
				turnChange++;
				if (turnChange % 2 == 0) turn = 0;
				else turn = 1;
				cout << "                                                  ";
				start();
				frame();
				ratioFrame();
				gotoxy(x, y);
				play();
			}
			else {
				gotoxy(15, 1);
				cout << "                                              ";
				gotoxy(15, 1);
				cout << "The player 1 didn't accept a tight game ";
				_getch();
				gotoxy(15, 1);
				cout << "                                        ";
				gotoxy(15, 1);
				cout << "                                                                     ";
			}

		}
	}
	if (ch == 116) {
		if (turn % 2 == 0) {
			gotoxy(15, 1);
			txtColor(10);
			cout << "The player 1 lost ";
			_getch();
			p2++;
			gotoxy(10, 1);
			turnChange++;
			if (turnChange % 2 == 0) turn = 0;
			else turn = 1;
			cout << "                                  ";
			start();
			frame();
			ratioFrame();
			gotoxy(x, y);
			play();
		}
		else {
			gotoxy(15, 1);
			txtColor(10);
			cout << "The player 2 lost ";
			_getch();
			p1++;
			gotoxy(10, 1);
			turnChange++;
			if (turnChange % 2 == 0) turn = 0;
			else turn = 1;
			cout << "                                  ";
			start();
			frame();
			ratioFrame();
			gotoxy(x, y);
			play();
		}
	}
	if (ch == UP) {
		if (y <= 4) {
			y = 19;
			gotoxy(x, y);
			play();
		}
		else {
			y--;
			gotoxy(x, y);
			play();
		}
	}
	if (ch == 27) {
		gotoxy(15, 0);
		cout << "Do you want to exit? (y/n)";
		char C = _getch();
		if ((C == 'y') || (C == 'Y')) {
			exit(0);
		}
		else {
			gotoxy(15, 0);
			cout << "                                ";
		}
	}
	if (ch == DOWN || ch == 281) {
		if (y >= 19) {
			y = 4;
			gotoxy(x, y);
			play();
		}
		else {
			y++;
			gotoxy(x, y);
			play();
		}
	}
	if (ch == RIGHT) {
		if (x >= 48) {
			x = 11;
			gotoxy(x, y);
			play();
		}
		else {
			x++;
			gotoxy(x, y);
			play();
		}
	}
	if (ch == LEFT) {
		if (x <= 11) {
			x = 48;
			gotoxy(x, y);
			play();
		}
		else {
			x--;
			gotoxy(x, y);
			play();
		}
	}
	if (ch == OK) {
		// Neu ma da co gia tri
		if (a[x][y] != 0) {
			gotoxy(15, 1);
			txtColor(10);
			cout << "O nay khong trong. Ban hay chon o khac ...";
			_getch();
			gotoxy(15, 1);
			cout << "                                            ";
			gotoxy(x, y);
			play();
		}
		// luc nay da chon o khong co gia tri
		turn++;
		if (turn % 2 == 0) {  // Player 2's turn
			a[x][y] = 2;
			gotoxy(x, y);
			txtColor(10);
			cout << "x";
			gotoxy(15, 1);
			txtColor(11);
			cout << "Player 1's turn - ";
			txtColor(12);
			cout << "o";
			play();
		}
		else { // Player 1's turn
			a[x][y] = 1;
			gotoxy(x, y);
			txtColor(12);
			cout << "o";
			gotoxy(15, 1);
			txtColor(11);
			cout << "Player 2's turn - ";
			txtColor(10);
			cout << "x";
			play();
		}
	}
	play(); // When press a random key
}
int win() {
	int Win = 1; // win = 1 means won . 0 means haven't won yet.
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {

			if ((a[i][j] == a[i + 1][j]) && (a[i][j] == a[i + 2][j]) && (a[i][j] == a[i + 3][j])/*&&(a[i+4][j]==a[i][j])*/ && (a[i][j] != 0)) {
				Win = 1;
				for (int h = 0; h <= 50; h++) {
					if (i - h <= 1) {
						break;
					}
					else {
						if ((a[i - h][j] != a[i][j]) && (a[i - h][j] != 0)) {
							Win = 0;
							break;
						}
					}
				}
				for (int h = 0; h <= 50; h++) {
					if (i + h >= 50) {
						break;
					}
					else {
						if ((a[i + h + 3][j] != a[i][j]) && (a[i + h + 3][j] != 0)) {
							Win = 0;
							break;
						}
					}
				}
				if (Win == 1) {
					for (int k = 0; k<4; k++) {
						chance[k].y = j;
						chance[k].x = i + k;
					}
					return a[i][j];
				}
			}
			if ((a[i][j] == a[i][j + 1]) && (a[i][j] == a[i][j + 2]) && (a[i][j] == a[i][j + 3])/*&&(a[i][j]==a[i][j+4])*/ && (a[i][j] != 0)) {
				Win = 1;
				for (int h = 0; h <= 50; h++) {
					if (j + h >= 50) {
						break;
					}
					else {
						if ((a[i][j + 3 + h] != 0) && (a[i][j + 3 + h] != a[i][j])) Win = 0;
					}
				}
				for (int h = 0; h <= 50; h++) {
					if (j - h <= 1) {
						break;
					}
					else {
						if ((a[i][j - h] != 0) && (a[i][j - h] != a[i][j])) Win = 0;
					}
				}
				if (Win == 1) {
					for (int k = 0; k<4; k++) {
						chance[k].x = i;
						chance[k].y = j + k;
					}
					return a[i][j];
				}
			}
			if ((a[i][j] == a[i + 1][j + 1]) && (a[i][j] == a[i + 2][j + 2]) && (a[i][j] == a[i + 3][j + 3])/*&&(a[i][j]==a[i+4][j+4])*/ && (a[i][j] != 0)) {
				Win = 1;
				for (int h = 0; h <= 50; h++) {
					if ((i + h >= 50) || (j + h) >= 30) break;
					else {
						if ((a[i + h + 3][j + h + 3] != a[i][j]) && (a[i + h + 3][j + h + 3] != 0)) Win = 0;
					}
				}
				for (int h = 0; h <= 50; h++) {
					if ((i - h <= 1) || (j - h) <= 1) break;
					else {
						if ((a[i - h][j - h] != a[i][j]) && (a[i - h][j - h] != 0)) Win = 0;
					}
				}
				if (Win == 1) {
					for (int k = 0; k<4; k++) {
						chance[k].x = i + k;
						chance[k].y = j + k;
					}
					return a[i][j];
				}
			}
			if ((a[i][j] == a[i - 1][j + 1]) && (a[i][j] == a[i - 2][j + 2]) && (a[i][j] == a[i - 3][j + 3])/*&&(a[i][j]==a[i-4][j-4])*/ && (a[i][j] != 0)) {
				Win = 1;
				for (int h = 1; h <= 50; h++) {
					if ((i + h >= 50) || (j - h) <= 1) break;
					else {
						if ((a[i + h][j - h] != a[i][j]) && (a[i + h][j - h] != 0)) Win = 0;
					}
				}
				for (int h = 0; h <= 50; h++) {
					if ((i - h <= 1) || (j + h) >= 50) break;
					else {
						if ((a[i - 4 - h][j + h + 4] != a[i][j]) && (a[i - h - 4][j + h + 4] != 0)) Win = 0;
					}
				}
				if (Win == 1) {
					for (int k = 0; k<4; k++) {
						chance[k].x = i - k;
						chance[k].y = j + k;
					}
					return a[i][j];
				}
			};
		}
	}

	return 0;
}

void ratioFrame() {
	gotoxy(52, 3);
	txtColor(10);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
	txtColor(13);
	cout << " Score ";
	txtColor(10);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
	gotoxy(54, 4);
	txtColor(14);
	cout << "player1    player2";

	for (int i = 0; i <= 21; i++) {
		gotoxy(52 + i, 4 + 18);
		txtColor(10);
		cout << char(223);
	}
	for (int i = 4; i <= 21; i++) {
		gotoxy(52, i);
		cout << char(219);
		gotoxy(52 + 16 + 5, i);
		cout << char(219);
		gotoxy(52 + 8 + 2, i);
		cout << char(219);
	}
	score();
}
void score() {
	for (int i = 0; i < p1; i++) {
		gotoxy(52 + 2, 6 + i);
		txtColor(12);
		cout << "o";
	}
	for (int i = 0; i < p2; i++) {
		gotoxy(52 + 13, 6 + i);
		txtColor(11);
		cout << "x";
	}
}
void instruction() {
	txtColor(10);
	gotoxy(1, 0);
	txtColor(9);
	cout << "Esc - Exit";
	txtColor(10);
	gotoxy(1, 3);
	// the order of symbol '←' is 283
	cout << "a : " << char(283);
	gotoxy(1, 4);
	// the order of symbol '→' is 282
	cout << "d : " << char(282);
	gotoxy(1, 5);
	// the order of symbol '↑' is 280
	cout << "w : " << char(280);
	gotoxy(1, 6);
	// the order of symbol '↓' is 281
	cout << "s : " << char(281);
	gotoxy(1, 8);
	txtColor(13);
	cout << "t : ";
	gotoxy(1, 9);
	txtColor(13);
	cout << "Surrender";
	gotoxy(1, 10);
	txtColor(10);
	txtColor(13);
	cout << "h : ";
	gotoxy(1, 11);

	cout << "Tight game?";

}
