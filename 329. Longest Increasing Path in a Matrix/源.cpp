#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int nextStep[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int m, n;
int result = 1;


int**data;
int**check;
vector<vector<int>> mymatrix;



int getmax(vector<vector<int>>& matrix, int x, int y)
{
	vector<int>list(n, 1);
	vector<vector<int>>grid(m, list);
	queue<int>que;
	que.push(x);
	que.push(y);
	int result = 1;
	
	while (!que.empty())
	{
		const int curx = que.front(); que.pop();
		const int cury = que.front(); que.pop();

		int cur = matrix[curx][cury];

		for (int k = 0; k < 4; k++)
		{
			int xx = curx + nextStep[k][0];
			int yy = cury + nextStep[k][1];
			if (xx >= 0 && xx < m&&yy >= 0 && yy < n&&matrix[xx][yy]>cur&&grid[xx][yy]<grid[curx][cury] + 1)
			{
				grid[xx][yy] = grid[curx][cury] + 1;
				result = max(result, grid[xx][yy]);
				que.push(xx);
				que.push(yy);
			}
		}
	}
	return result;
	
}


int dfs(int x,int y)
{
	if (check[x][y] != 0)
		return check[x][y];
	int maxV = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + nextStep[i][0];
		int yy = y + nextStep[i][1];
		if (xx >= 0 && xx < m&&yy >= 0 && yy < n&&mymatrix[x][y]>mymatrix[xx][yy])
		{
			if (check[xx][yy] == 0)
			{
				maxV = max(maxV,dfs(xx,yy)+1);
			}
			else
			{
				maxV = max(maxV, check[xx][yy]+1);
			}
		}
	}
	check[x][y] = maxV;
	return maxV;
}


int longestIncreasingPath(vector<vector<int>>& matrix) 
{
	
	m = matrix.size();
	if (m == 0)return 0;
	n = matrix[0].size();

	mymatrix = matrix;

	check = new int*[m];
	data = new int*[m];
	for (int i = 0; i < m; i++)
	{
		data[i] = new int[n];
		check[i] = new int[n];
		memset(data[i],0,n*sizeof(int));
		memset(check[i], 0, n*sizeof(int));
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result = max(result,dfs(i,j));
		}
	}
	return result;
}

int main()
{
	vector<int>list1{7,8,9};
	vector<int>list2{9,7,6};
	vector<int>list3{ 7,2, 3 };
	vector<vector<int>>list{list1,list2,list3};

	int result = longestIncreasingPath(list);
	return 0;
}