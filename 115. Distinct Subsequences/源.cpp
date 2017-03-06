#include<iostream>
#include<string>

using namespace std;


int numDistinct(string s, string t) 
{
	if (t.size() == 0)return 0;
	if (s.size() == 0 && t.size() != 0)return 0;
	if (s.size() + t.size() == 0)return 1;


	int m = s.size();
	int n = t.size();

	int **grid = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		grid[i] = new int[n + 1];
	}

	for (int i = 0; i <m + 1; i++)
	{
		grid[i][0] = 1;
	}

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i < j)
				grid[i][j] = 0;
			if (i == j)
			{
				if (s.substr(0, i) == t.substr(0, j))
					grid[i][j] = 1;
				else
					grid[i][j] = 0;
			}
		}
	}


	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i <= j)continue;

			if (s[i - 1] != t[j - 1])
			{
				grid[i][j] = grid[i - 1][j];
			}
			else
			{
				grid[i][j] = grid[i - 1][j] + grid[i - 1][j - 1];
			}
		}
	}

	return grid[m][n];
}

void main()
{

}