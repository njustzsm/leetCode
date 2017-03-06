#include<iostream>
#include<vector>

using namespace std;

vector<int>coordX,coordY;
vector<vector<char>> result;
int num = 0;
bool isCheck = false;

bool isValid(vector<vector<char>>& board, int x, int y, int value)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[x][i] - '0' == value&&i != y)
			return false;
		if (board[i][y] - '0' == value&&i != x)
			return false;
	}

	int srcX = 3 * (x / 3);
	int srcY = 3 * (y / 3);

	for (int i = srcX; i < srcX + 3; i++)
	{
		for (int j = srcY; j < srcY + 3; j++)
		{
			if (i == x&&j == y)continue;
			if (board[i][j] - '0' == value)
				return false;
		}
	}
	return true;

}

void DFS(int cur, vector<vector<char>>& board)
{
	if (isCheck)return;
	if (cur == num)
	{
		result = board;
		isCheck = true;
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (isValid(board, coordX[cur], coordY[cur], i)&&!isCheck)
		{
			board[coordX[cur]][coordY[cur]] = '0'+i;
			DFS(cur + 1, board);
			board[coordX[cur]][coordY[cur]] = '.';
		}
	}
		

}


void solveSudoku(vector<vector<char>>& board) 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				coordX.push_back(i);
				coordY.push_back(j);
				num++;
			}
		}
	}

	DFS(0,board);

	board = result;



}

void main()
{

}