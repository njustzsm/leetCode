#include<iostream>
#include<vector>

using namespace std;




int grid[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
void gameOfLife(vector<vector<int>>& board) 
{
	int m = board.size();
	if (m == 0)return;
	int n = board[0].size();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

			int liveNum = 0;
			for (int k = 0; k < 8; k++)
			{
				int x = i + grid[k][0];
				int y = j + grid[k][1];
				if (x >= 0 && x < m&&y >= 0 && y < n&&board[x][y] >= 1 && board[x][y]<4)
				{
					liveNum++;
				}
			}
			if (liveNum >= 2 && liveNum <= 3&&board[i][j]==1)
			{
				board[i][j] += 2;
			}
			if (liveNum==3&&board[i][j]==0)
			{
				board[i][j] = 4;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j]>1)
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}


}

int main()
{
	return 0;
}