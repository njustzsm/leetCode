#include<vector>
#include<iostream>
#include<stdarg.h>
using namespace std;

class NumMatrix {
public:

	vector<vector<int>>data;

	NumMatrix(vector<vector<int>> matrix)
	{
		data = matrix;

		int m = matrix.size();
		if (m != 0)
		{
			int n = matrix[0].size();

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i - 1 >= 0)
					{
						data[i][j] += data[i - 1][j];
					}
					if (j - 1 >= 0)
					{
						data[i][j] += data[i][j - 1];
					}

					if (i - 1 >= 0 && j - 1 >= 0)
					{
						data[i][j] -= data[i - 1][j - 1];
					}
				}
			}
		}
		
	}

	int sumRegion(int row1, int col1, int row2, int col2) 
	{
		if (data.size() == 0)return 0;
		long long int result = data[row2][col2];

		if (row1 - 1 >= 0)
		{
			result -= data[row1 - 1][col2];
		}
		if (col1 - 1 >= 0)
		{
			result -= data[row2][col1-1];
		}
		if (row1 - 1 >= 0 && col1 - 1 >= 0)
		{
			result += data[row1-1][col1 - 1];
		}

		return result;
	}
};

int main()
{

	
	return 0;
}
