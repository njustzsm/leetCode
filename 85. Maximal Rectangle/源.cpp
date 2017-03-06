#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int**left0, **right0, **height;
//vector<vector<int>>left0, right0;
int maximalRectangle(vector<vector<char>>& matrix) 
{
	int m = matrix.size();
	if (m == 0)return 0;
	int n = matrix[0].size();

	left0 = new int*[m];
	right0 = new int*[m];
	//height = new int*[m];

	for (int i = 0; i < m; i++)
	{
		left0[i] = new int[n];
		right0[i] = new int[n];
		//height[i] = new int[n];
		for (int j = 0; j < n;j++)
		{
			left0[i][j] = 0;
			right0[i][j] = 0;
			
		}
		
	}
	
	
	

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '1')
			{
				if (j != 0)
				{
					if (matrix[i][j - 1] == '1')
					{
						left0[i][j] = left0[i][j - 1];
					}
					else
						left0[i][j] = j;
				}
				else
				{
					left0[i][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = n-1; j >=0; j--)
		{
			if (matrix[i][j] == '1')
			{
				if (j != n - 1)
				{
					if (matrix[i][j + 1] == '1')
					{
						right0[i][j] = right0[i][j + 1];
					}
					else
						right0[i][j] = j;
				}
				else
					right0[i][j] = j;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '1')
			{
				int curLeft = left0[i][j], curRight = right0[i][j];
				int curRow = i;
				while (curRow>=0&&matrix[curRow][j]=='1')
				{
					int height = i - curRow + 1;
					curLeft = max(curLeft,left0[curRow][j]);
					curRight = min(curRight,right0[curRow][j]);
					if (result < height*(curRight - curLeft + 1))
					{
						result = height*(curRight - curLeft + 1);
					}
					curRow--;
				}

			}
		}
	}
	return result;



}
void main()
{
	string a[] = {"10100", "10111", "11111", "10010" };
	vector<vector<char>>data;

	for (int i = 0; i < 4; i++)
	{
		string tt = a[i];
		vector<char>list;
		for (int j = 0; j < tt.size(); j++)
		{
			list.push_back(tt[j]);
		}
		data.push_back(list);
		
	}
	vector<int>list(5,0);
	for (int i = 0; i < 4; i++)
	{
		//left0.push_back(list);
		//right0.push_back(list);
		
	}
	maximalRectangle(data);
}