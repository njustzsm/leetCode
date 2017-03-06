#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int result = INT_MAX;
vector<vector<int>> data;
void dfs(int curRow,int col,int rows,int curSum)
{
	if (curRow == rows)
	{
		if (curSum < result)
			result = curSum;
		return;
	}

	vector<int>list = data[curRow];

	dfs(curRow+1,col,rows,curSum+list[col]);

	dfs(curRow+1,col+1,rows,curSum+list[col+1]);
}


int minimumTotal(vector<vector<int>>& triangle) 
{
	if (triangle.size() == 0)return 0;
	if (triangle.size() == 1)return triangle[0][0];

	int m = triangle.size();
	int n = triangle[triangle.size()-1].size();

	int**grid = new int*[m];
	for (int i = 0; i < m; i++)
	{
		grid[i] = new int[n];
		memset(grid[i],0,n*sizeof(int));
	}

	grid[0][0] = triangle[0][0];

	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)continue;
			if (j == 0)
			{
				grid[i][j] = grid[i - 1][j] + triangle[i][j];
			}
			else if (i==j)
			{
				grid[i][j] = grid[i - 1][j-1] + triangle[i][j];
			}
			else
			{
				grid[i][j] = triangle[i][j] + min(grid[i-1][j-1],grid[i-1][j]);
			}
		}
	}

	int result = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (grid[m - 1][i] < result)
			result = grid[m - 1][i];
	}
	return result;

}

void main()
{
	vector<int>list0,list1;
	list0.push_back(-1);
	list1.push_back(-2);
	list1.push_back(-3);
	vector<vector<int>>tt;
	tt.push_back(list0);
	tt.push_back(list1);

}

