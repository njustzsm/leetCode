#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
	int left;
	int right;
	point()
	{
		left = 0;
		right = 0;
	}
};

int maximalSquare(vector<vector<char>>& matrix)
{
	int m = matrix.size();
	if (m == 0)return 0;
	int n = matrix[0].size();
	if (n == 0)return 0;

	point **grid = new point*[m];

	for (int i = 0; i < m; i++)
	{
		grid[i] = new point[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '0'||j==0)
				continue;

			if (matrix[i][j - 1] != '0')
			{
				grid[i][j].left = grid[i][j - 1].left;
			}
			else
			{
				grid[i][j].left = j;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = n-1; j>=0; j--)
		{
			if (matrix[i][j] == '0')
				continue;

			if (j!=n-1&&matrix[i][j + 1] != '0')
			{
				grid[i][j].right = grid[i][j+1].right;
			}
			else
			{
				grid[i][j].right = j;
			}
		}
	}


	int result = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '0')
				continue;

			int curLength = 0;

			int left = grid[i][j].left, right = grid[i][j].right;

			int height = i;

			while (height>=0&&matrix[height][j]=='1')
			{
				left = max(left,grid[height][j].left);
				right = min(right,grid[height][j].right);

				int width = right - left + 1;
				curLength = min(width,i-height+1);

				if (result < curLength)
					result = curLength;

				height--;
			}
		}
	}
	return result*result;



}

void main()
{

}