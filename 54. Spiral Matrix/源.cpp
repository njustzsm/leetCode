#include<iostream>
#include<vector>

using namespace std;

vector<int> getRect(int src,int row,int col,vector<vector<int>> matrix)
{
	vector<int>result;
	
	if (row == 1)
	{
		for (int i = src; i < src + col; i++)
			result.push_back(matrix[src][i]);
		return result;
	}
	if (col == 1)
	{
		for (int i = src; i < src + row; i++)
			result.push_back(matrix[i][src]);
		return result;
	}

	for (int i = src; i <src+col; i++)
	{
		result.push_back(matrix[src][i]);
	}
	for (int i = src + 1; i < src + row; i++)
	{
		result.push_back(matrix[i][src+col-1]);
	}
	for (int i = src + col - 2; i >= src; i--)
	{
		result.push_back(matrix[src+row-1][i]);
	}
	for (int i = src + row - 2; i>src; i--)
	{
		result.push_back(matrix[i][src]);
	}
	return result;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
	
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int>result;
	if (m == 0)return result;
	int src = 0;
	while (m>0&&n>0)
	{
		vector<int>cur = getRect(src,m,n,matrix);
		result.insert(result.end(),cur.begin(),cur.end());
		m-=2;
		n -= 2;
		src++;
	}
	return result;
}

void main()
{

}