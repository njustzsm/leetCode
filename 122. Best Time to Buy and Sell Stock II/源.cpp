#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
	if (prices.size() <= 1)return 0;

	int n = prices.size();

	int result = 0;
	
	for (int i = 1; i < n ; i++)
	{
		if (prices[i - 1] < prices[i])
		{
			result += prices[i] - prices[i - 1];
		}
	}
	return result;

}

void main()
{

}