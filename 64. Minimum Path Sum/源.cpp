#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int tt[4][2] = { {1,0}, {0,1} };

int minPathSum(vector<vector<int>>& grid) 
{
	if (grid.size() == 0)return 0;

	int m = grid.size();
	int n = grid[0].size();

	int**dis = new int*[m];
	for (int i = 0; i < m; i++)
	{
		dis[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			dis[i][j] = -1;
		}
	}

	queue<int>Queue;
	Queue.push(0);
	Queue.push(0);
	dis[0][0] = grid[0][0];

	while (!Queue.empty())
	{
		int x = Queue.front();
		Queue.pop();
		int y = Queue.front();
		Queue.pop();

		for (int i = 0; i < 2; i++)
		{
			int xx = x + tt[i][0];
			int yy = y + tt[i][1];
			if (xx >= 0 && xx < m&&yy >= 0 && yy < n && (dis[xx][yy] < 0 || dis[x][y] + grid[xx][yy] < dis[xx][yy]))
			{
				dis[xx][yy] = dis[x][y] + grid[xx][yy];
				Queue.push(xx);
				Queue.push(yy);
			}
		}
	}

	return dis[m-1][n-1]+grid[m-1][n-1];





}


void main()
{

}