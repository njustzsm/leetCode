#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{

	if (obstacleGrid[0][0] == 1)return 0;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int**grid = new int*[m];
	for (int i = 0; i < m; i++)
	{
		grid[i] = new int[n];
	}

	grid[0][0] = 1;

	for (int i = 1; i < m; i++)
	{
		if (obstacleGrid[i][0] == 0)
			grid[i][0] = grid[i - 1][0];
		else
			grid[i][0] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (obstacleGrid[0][i] == 0)
			grid[0][i] = grid[0][i - 1];
		else
			grid[0][i] = 0;
	}
		


	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] == 0)
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			else
				grid[i][j] = 0;
		}
	}

	
	return grid[m-1][n-1];
}

void main()
{

}