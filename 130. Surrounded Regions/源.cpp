#include<iostream>
#include<vector>
#include<queue>
using namespace std;




void solve(vector<vector<char>>& board)
{
	int m = board.size();
	if (m == 0)return;
	int n = board[0].size();
	int grid[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

	bool**check = new bool*[m];
	for (int i = 0; i < m; i++)
	{
		check[i] = new bool[n];
		memset(check[i],false,n*sizeof(bool));
	}

	vector<int>his;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!check[i][j] && board[i][j] == 'O')
			{
				bool isRemove = true;
				check[i][j] = true;
				queue<int>que;

				his.clear();

				que.push(i);
				que.push(j);
				while (!que.empty())
				{
					int curx = que.front();
					que.pop();
					int cury = que.front();
					que.pop();

					his.push_back(curx);
					his.push_back(cury);

					if (curx == 0 || curx == m - 1 || cury == 0 || cury == n - 1)
						isRemove = false;

					for (int k = 0; k < 4; k++)
					{
						int xx = curx + grid[k][0];
						int yy = cury + grid[k][1];
						if (xx >= 0 && xx < m&&yy >= 0 && yy < n&&!check[xx][yy] && board[xx][yy] == 'O')
						{
							check[xx][yy] = true;
							que.push(xx);
							que.push(yy);
						}
					}

				}
				if (isRemove)
				{
					for (int i = 0; i < his.size(); i += 2)
					{
						int xx = his[i];
						int yy = his[i + 1];
						board[xx][yy] = 'X';
					}
				}
			}
		}
	}



}
void main()
{

}