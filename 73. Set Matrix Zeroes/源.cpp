#include<iostream>
#include<vector>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) 
{

	int m = matrix.size();
	if (m == 0)return;
	int n = matrix[0].size();
	if (n == 0)return;

	vector<int>tag;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				tag.push_back(i);
				tag.push_back(j);
			}
		}
	}

	for (int i = 0; i < tag.size(); i += 2)
	{
		int x = tag[i];
		int y = tag[i + 1];
		for ( int i = 0; i < m; i++)
		{
			matrix[i][y] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			matrix[x][i] = 0;
		}
	}
	


}

void main()
{
	int grid[5][8] = { { 8, 3, 6, 9, 7, 8, 0, 6 }, { 0, 3, 7, 0, 0, 4, 3, 8 }, 
	{ 5, 3, 6, 7, 1, 6, 2, 6 }, { 8, 7, 2, 5, 0, 6, 4, 0 }, { 0, 2, 9, 9, 3, 9, 7, 3 } };
	vector<vector<int>>tt;
	for (int i = 0; i < 5; i++)
	{
		vector<int>rr;
		for (int j = 0; j < 8; j++)
		{
			rr.push_back(grid[i][j]);
		}
		tt.push_back(rr);
	}
	setZeroes(tt);
}
