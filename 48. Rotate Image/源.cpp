#include<iostream>
#include<vector>

using namespace std;

void rotateOneStep(vector<vector<int>>& matrix,int x,int y,int length)
{
	int value = matrix[x][y];
	for (int i = x + 1; i<x+length; i++)
	{
		matrix[i-1][y] = matrix[i][y];
	}
	for (int i = y+1; i < y+length; i++)
	{
		matrix[x+length-1][i - 1] = matrix[x+length-1][i];
	}
	for (int i = x + length - 2; i >= x; i--)
	{
		matrix[i + 1][y + length - 1] = matrix[i][y+length-1];
	}

	for (int i = y + length - 2; i>y; i--)
	{
		matrix[x][i+1] = matrix[x][i];
	}
	matrix[x][y + 1] = value;
}

void rotate(vector<vector<int>>& matrix) 
{
	int n = matrix.size();
	for (int i = 0; i < n / 2; i++)
	{
		int curLength = n - i*2;
		for (int j = 0; j < curLength - 1; j++)
			rotateOneStep(matrix,i,i,curLength);
	}
}

void main()
{

}