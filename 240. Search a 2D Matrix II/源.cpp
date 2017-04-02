#include<iostream>
#include<vector>

using namespace std;


bool search(vector<int>list,int target)
{
	int p = 0, q = list.size() - 1;

	while (p<=q)
	{
		int mid = (p + q) / 2;
		if (list[mid]>target)
			q = mid - 1;
		else if (list[mid] < target)
			p = mid + 1;
		else
			return true;
	}

	return false;

}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	int m = matrix.size();
	if (m == 0)return false;
	int n = matrix[0].size();
	if (n == 0)return false;


	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0]>target)
			break;

		if (matrix[i][n - 1] < target)
			continue;

		if (search(matrix[i], target))
			return true;
	}


	return false;

}

void main()
{

}