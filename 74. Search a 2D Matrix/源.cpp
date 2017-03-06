#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	int m = matrix.size();
	if (m == 0)return false;
	int n = matrix[0].size();
	if (n == 0)return false;

	int p = 0, q = m*n - 1;

	while (p<=q)
	{
		int mid = (p+q)/2;
		int x = mid / n;
		int y = (mid - x*n);

		if (matrix[x][y] < target)
		{
			p = mid + 1;
		}
		else if (matrix[x][y] > target)
		{
			q = mid - 1;
		}
		else
			return true;
	}
	return false;
}

void main()
{

}