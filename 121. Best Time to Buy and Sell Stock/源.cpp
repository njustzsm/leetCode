#include<iostream>
#include<vector>
using namespace std;



int maxProfit(vector<int>& prices) 
{
	if (prices.size() <= 1)return 0;

	int n = prices.size();
	int curMax = prices[n-1];
	int result = 0;

	for (int i = n - 2; i >= 0; i--)
	{
		int cur = prices[i];

		if (curMax-cur>result)
		{
			result = curMax - cur;
		}
		if (cur > curMax)
			curMax = cur;
	}

	return result;

}

void main()
{

}