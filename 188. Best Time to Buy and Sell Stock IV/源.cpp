#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int maxProfit(int k, vector<int>& prices) 
{
	int m = prices.size();
	if (m <= 1)return 0;

	if (k >= m)
	{
		int result = 0;
		for (int i = 1; i < m; i++)
		{
			if (prices[i] - prices[i - 1]>0)
				result += prices[i] - prices[i - 1];
		}
		return result;
	}

	int**global = new int*[m+1];
	int**local = new int*[m+1];
	for (int i = 0; i < m+1; i++)
	{
		global[i] = new int[k+1];
		local[i] = new int[k+1];

		memset(local[i],0,(k+1)*sizeof(int));
		memset(global[i],0,(k+1)*sizeof(int));
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int diff = 0;

			if (i > 1)
				diff = prices[i - 1] - prices[i-2];

			local[i][j] = max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff);
			global[i][j] = max(local[i][j],global[i-1][j]);
		}
	}

	return global[m][k];
}



void main()
{

}