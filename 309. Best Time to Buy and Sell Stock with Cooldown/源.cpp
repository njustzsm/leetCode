#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) 
{
	int n = prices.size();
	if (n <= 1)return 0;


	/*
	buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
	sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。
	*/
	int*sell = new int[n];
	int*buy = new int[n];

	sell[0] = 0;
	sell[-1] = 0;
	buy[0] = -prices[0];

	for (int i = 1; i < n; i++)
	{
		sell[i] = max(sell[i-1],buy[i-1]+prices[i]);
		buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
	}

	return sell[n - 1];


}

int main()
{
	int data[] = {2,1,4};
	int len = sizeof(data) / sizeof(int);
	vector<int>input;
	for (int i = 0; i < len; i++)
	{
		input.push_back(data[i]);
	}

	int tt = maxProfit(input);


	return 0;
}