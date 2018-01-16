#include<iostream>
using namespace std;
char arr[8][8];//the game array
char b = 'B';// this will represent the Black pieces
char w = 'W';// this will represent the White pieces
char e = '_';//this will represent empty spaces
char turn = b;//this allows the black piece to make the first move
bool gameRun = true;// fucction to represnt the game running
void count(void);//count function prototype
void input(void);//input function prototype
//Right direction functions
bool checkRight(int x, int y) {
	if (arr[y][x + 1] != turn && arr[y][x + 1] != e ){
		return(true);

	}
	else
		return(false);
}
int scanRight(int x, int y) {
	int depth = 0;

	for (int i = x + 1; i <8; i++)
	{
		if (arr[y][i] == turn)
		{
			return(depth);

		}
		 if (arr[y][i] != turn && arr[y][i] != e)
		{
			depth++;
		}
		 if (arr[y][i] == e)
		 {	
			 depth = 0;
			 return(depth);

		 }

	}

}
void doRight(int depth, int x, int y) {
	for (int i = x; i <= (x + depth); i++) {
		arr[y][i] = turn;
	}
}
//Left direction functions
bool checkLeft(int x, int y) {
	if (arr[y][x - 1] != turn && arr[y][x - 1] != e) {
		return(true);

	}
	else
		return(false);
}
int scanLeft(int x, int y) {
	int depth = 0;

	for (int i = x - 1; i >0; i--)
	{
		if (arr[y][i] == turn)
		{
			return(depth);

		}
		 if (arr[y][i] != turn && arr[y][i] != e)
		{
			depth++;
		}
	    if (arr[y][i] == e)
		 {	
			 depth = 0;
			 return(depth);

		 }

	}

}
void doLeft(int depth, int x, int y) {
	for (int i = x; i >= (x - depth); i--) {
		arr[y][i] = turn;
	}
}
//Down direction functions
bool checkDown(int x, int y) {
	if (arr[y + 1][x] != turn && arr[y + 1][x] != e) {
		return(true);
	}
	else
		return(false);
}
int scanDown(int x, int y) {
	int depth = 0;

	for (int i = y + 1; i <8; i++)
	{
		if (arr[i][x] == turn)
		{
			return(depth);

		}
		 if (arr[i][x] != turn && arr[i][x] != e)
		{
			depth++;
		}
		if (arr[i][x] == e)
		{
			depth = 0;
			return(depth);

		}
	}

}
void doDown(int depth, int x, int y) {
	for (int i = y; i <= (y + depth); i++) {
		arr[i][x] = turn;
	}
}
//Up direction functions
bool checkUp(int x, int y) {
	if (arr[y - 1][x] != turn && arr[y - 1][x] != e) {
		return(true);

	}
	else
		return(false);
}
int scanUp(int x, int y) {
	int depth = 0;
	for (int i = y - 1; i >0; i--)
	{
		if (arr[i][x] == turn)
		{
			return(depth);

		}
		if (arr[i][x] != turn && arr[i][x] != e)
		{
			depth++;
		}
		if (arr[i][x] == e)
		{	
			depth = 0;
			return(depth);

		}

	}

}
void doUp(int depth, int x, int y) {
	for (int i = y; i >= (y - depth); i--) {
		arr[i][x] = turn;
	}
}
//DownRight 
bool checkDownRight(int x, int y) {
	if (arr[y + 1][x + 1] != turn && arr[y + 1][x + 1] != e) {
		return(true);
	}
	else
		return(false);
}
int scanDownRight(int x, int y) 
{
	int depth = 0;
	int i = x + 1, j = y + 1;
	while (i < 8 && j < 8) 
	{
		if (arr[j][i] == turn) 
		{
			return(depth);
		}
		if (arr[j][i] != turn && arr[j][i] != e)
		{
			i++;
			j++;
			depth++;
		}
		if (arr[j][i] == e) {
			depth = 0;
			return(depth);
		}


	}

	


}
void doDownRight(int depth, int x, int y) {
	for (int i = 0; i <= depth; i++) {
		for (int j = 0; j <= depth; j++) {
			if (i == j) {
				arr[y + j][x + i] = turn;
			}
		}

	}
	
}
//DownLeft
bool checkDownLeft(int x, int y) {
	if (arr[y + 1][x - 1] != turn && arr[y + 1][x - 1] != e) {
		return(true);
	}
	else
		return(false);
}
int scanDownLeft(int x, int y) {
	int depth = 0;
	int i = x - 1, j = y + 1;
	while (i > 0 && j < 8)
	{	
		
		if (arr[j][i] == turn)
		{	
			return(depth);
		}
		
		if (arr[j][i] != turn && arr[j][i] != e)
		{
			i--;
			j++;
			depth++;
		}
		if (arr[j][i] == e) {
			depth = 0;
			return(depth);
		}


	}

}
void doDownLeft(int depth, int x, int y) {
	for (int i = 0; i <= depth; i++) {
		for (int j = 0; j <= depth; j++) {
			if (i == j) {
				arr[y + j][x - i] = turn;
			}
		}

	}
}
//UpRight
bool checkUpRight(int x, int y) {
	if (arr[y - 1][x + 1] != turn && arr[y - 1][x + 1] != e) {
		return(true);
	}
	else
		return(false);
}
int scanUpRight(int x, int y) {
	int depth = 0;
	int i = x + 1, j = y - 1;
	while (i < 8 && j > 0)
	{

		if (arr[j][i] == turn)
		{
			return(depth);
		}

		if (arr[j][i] != turn && arr[j][i] != e)
		{
			i++;
			j--;
			depth++;
		}
		if (arr[j][i] == e) {
			depth = 0;
			return(depth);
		}


	}
}
void doUpRight(int depth, int x, int y) {
	for (int i = 0; i <= depth; i++) {
		for (int j = 0; j <= depth; j++) {
			if (i == j) {
				arr[y - j][x + i] = turn;
			}
		}

	}
}
//UpLeft
bool checkUpLeft(int x, int y) {
	if (arr[y - 1][x - 1] != turn && arr[y - 1][x - 1] != e) {
		return(true);
	}
	else
		return(false);
}
int scanUpLeft(int x, int y) {
	int depth = 0;
	int i = x - 1, j = y - 1;
	while (i > 0 && j > 0)
	{

		if (arr[j][i] == turn)
		{
			return(depth);
		}
		if (arr[j][i] == e) {
			depth = 0;
			return(depth);
		}
		if (arr[j][i] != turn && arr[j][i] != e)
		{
			i--;
			j--;
			depth++;
		}
		


	}
}
void doUpLeft(int depth, int x, int y) {
	for (int i = 0; i <= depth; i++) {
		for (int j = 0; j <= depth; j++) {
			if (i == j) {
				arr[y - j][x - i] = turn;
			}
		}

	}
}

void draw()
{//Draw fucntion. simply draws the array
	system("cls");
	count();
	cout << "  0|1|2|3|4|5|6|7" << endl;// just draws numbers to aid inputtion the X-coordinate
	int num = 0;//just draws numbers to aid inputtion the Y-coordinate
	cout << num<<" ";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
		++num;
		if (num < 8) {
			cout << num << " ";
		}
		
		
	}

}
void initialise()
{// Initialises the array to represent how an Reversi board looks like at the biggening

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = e;//just fills the entire array with '_' to represent an empty space
		}
	}
		arr[3][3] = arr[4][4] = w;//places the white pieces
		arr[3][4] = arr[4][3] = b;//places teh blacke pieces
		

}
void logic(int x, int y)
{// this function uses if sattements to check each of the 8 directions

	if (checkRight(x, y) == true&&arr[y][x]==e) {
		arr[y][x] = turn;
		doRight(scanRight(x, y), x, y);

	}
	
	if (checkLeft(x, y) == true && arr[y][x] == e) {
		//i guess its safe to place the coordi in right now but i will have to do it for every check function
		//this also allows me to palce near the grop thus preventing invalid moves
		arr[y][x] = turn;
		doLeft(scanLeft(x, y), x, y);

	}
	
	if (checkDown(x, y) == true && arr[y][x] == e) {
		arr[y][x] = turn;
		doDown(scanDown(x, y), x, y);
	}
	
	if (checkUp(x, y) == true && arr[y][x] == e) {
		arr[y][x] = turn;
		doUp(scanUp(x, y), x, y);
	}
	
	if (checkDownRight(x, y) == true && arr[y][x] == e) {
		arr[y][x] = turn;
		doDownRight(scanDownRight(x, y), x, y);
	}

	if (checkDownLeft(x, y) == true && arr[y][x] == e) {
		arr[y][x] = turn;
		doDownLeft(scanDownLeft(x, y), x, y);
	}
	if (checkUpRight(x, y) == true && arr[y][x] == e) {
		arr[y][x] = turn;
		doUpRight(scanUpRight(x, y), x, y);
	}
	if (checkUpLeft(x, y) == true && arr[y][x] == e) {
		arr[y][x] = turn;
		doUpLeft(scanUpLeft(x, y), x, y);
	}
	
}
void input()
{//input function. takes in user input
	int x, y;
	switch (turn) {
	case 'B':
		cout << "\nBlack Input X-Coordinate:";
		cin >> x;// take in the X-Coordinate
		cout << "Black Input Y-Coordinate:";
		cin >> y;// take in the Y-Coordinate
		logic(x, y);//passes the x and y cordinates to the logic function that checks all directions
		draw();// draws the board
		turn = w;// sets the turn to the other player
	case 'W':
		cout << "\nWhite Input X-Coordinate:";
		cin >> x;// take in the X-Coordinate
		cout << "White Input Y-Coordiante:";
		cin >> y;// take in the Y-Coordinate
		logic(x, y);//passes the x and y cordinates to the logic function that checks all directions
		draw();// draws the board
		turn = b;// sets the turn to the other player
	}
}
void count(void) { 
	// function counts pieces before the board is drawn to chekc if there are no more moves possible and then declaers the winner
	int nblack=0;
	int nwhite = 0;
	int empty = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == b) {
				nblack++;
			}
			if (arr[i][j] == w) {
				nwhite++;
			}
			if (arr[i][j] == e) {
				empty++;
			}
		}
		
	}
	if (empty == 0) {
		gameRun = false;
		system("cls");
		if (nwhite > nblack) {
			cout << "\nWhite Wins!!!"<<endl;
		}
		if (nblack > nwhite) {
			cout << "\nBlack Wins!!!"<<endl;
		}
		if (nblack == nwhite) {
			cout << "\nLOOKS LIKE IT'S A DRAW, FOLKS!!!" << endl;
		}

	}
	cout << "Number of White 'W' Pieces: " << nwhite << endl;
	cout << "Number of Balck 'B' Pieces: " << nblack << endl;
	cout << "Number of Empty squares: " << empty << endl;

}
int main() {
	
	initialise();//initilaise the array
	draw();// draw the board the first time
	while (gameRun)// while the game hasent ended
	{	
		
		input();// take in user input
		draw();// draw the board
	}
	system("pause");
	return(0);
}

