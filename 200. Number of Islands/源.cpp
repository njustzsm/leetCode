#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int tt[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int numIslands(vector<vector<char>>& grid) 
{
	int m = grid.size();
	if (m == 0)return 0;
	int n = grid[0].size();
	if (n == 0)return 0;

	int result = 0;

	queue<int>que;



	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == '1')
			{
				result++;

				que.push(i);
				que.push(j);

				grid[i][j] = '0';

				while (!que.empty())
				{
					int x = que.front();
					que.pop();
					int y = que.front();
					que.pop();

					for (int k = 0; k < 4; k++)
					{
						int xx = x + tt[k][0];
						int yy = y + tt[k][1];

						if (xx >= 0 && xx < m&&yy >= 0 && yy < n&&grid[xx][yy] == '1')
						{
							grid[xx][yy] = '0';
							que.push(xx);
							que.push(yy);
						}

					}
				}
			}
		}
	}

	return result;


}


void main()
{
	vector<char>list(159,'1');
	vector<vector<char>>data(1,list);
	int result=numIslands(data);
}