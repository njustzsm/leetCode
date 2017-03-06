#include<iostream>
#include<vector>


using namespace std;

int grid[10];

void initGrid()
{
	for (int i = 1; i <= 9; i++)
		grid[i] = 1;
}

bool isValidSudoku(vector<vector<char>>& board) 
{
	
	for (int i = 0; i < 9; i++)
	{
		initGrid();
		vector<char>cur = board[i];
		for (int j = 0; j < 9; j++)
		{
			char c = cur[j];
			if (c == '.')continue;
			if (grid[c - '0'] == 0)
				return false;
			else
				grid[c - '0'] = 0;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		initGrid();
		for (int j = 0; j < 9; j++)
		{
			char c = board[j][i];
			if (c == '.')continue;
			if (grid[c - '0'] == 0)
				return false;
			else
				grid[c - '0'] = 0;
		}
	}

	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			initGrid();
			for (int k = 0; k < 3; k++)
			{
				for (int t = 0; t < 3; t++)
				{
					char c = board[i+k][j+t];
					if (c == '.')continue;
					if (grid[c - '0'] == 0)
						return false;
					else
						grid[c - '0'] = 0;
				}
			}
		}
	}
	return true;


}

void main()
{

}
