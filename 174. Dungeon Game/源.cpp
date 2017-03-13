#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;



int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
	int m = dungeon.size();
	int n = dungeon[0].size();

	int**health = new int*[m];
	for (int i = 0; i < m; i++)
	{
		health[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			health[i][j] = INT_MIN;
		}
	}

	if (dungeon[m - 1][n - 1] < 0)
		health[m - 1][n - 1] = dungeon[m - 1][n - 1] * (-1) + 1;
	else
		health[m - 1][n - 1] = 1;

	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (i == m - 1 && j == n - 1)continue;

			int xx = i + 1;
			int yy = j + 1;

			int minNeed = INT_MAX;

			if (xx < m)
				minNeed = min(minNeed,health[xx][j]);
			if (yy < n)
				minNeed = min(minNeed,health[i][yy]);
			
			minNeed -= dungeon[i][j];
			if (minNeed <= 0)
				health[i][j] = 1;
			else
				health[i][j] = minNeed;
			
		}
	}
	
	return health[0][0];


	


}

void main()
{

}