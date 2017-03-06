#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int firstValue = 0, secondValue = 0;

void getminValue(vector<int>prices)
{
	int n = prices.size();

	int src = 1;
	
	while (src<n&&prices[src]<=prices[src-1])
	{
		src++;
	}

	if (src == n)return;

	src--;

	int dst=src+1;

	while (dst<n&&prices[dst]>=prices[dst-1])
	{
		dst++;
	}

	dst--;

	int cur = prices[dst] - prices[src];
	if (firstValue == 0)
	{
		firstValue = cur;
	}
	else if (secondValue == 0)
	{
		secondValue = cur;
	}
	else
	{
		if (cur > firstValue)
		{
			firstValue = cur;
		}
		else if (cur>secondValue)
		{
			secondValue = cur;
		}
	}

	vector<int>tt(prices.begin() + dst, prices.end());

	getminValue(tt);
	




}



int maxProfit(vector<int>& prices) 
{
	int m = prices.size();
	if (m == 0)
		return 0;

	int ret = 0;
	vector<int>forw(m,0);
	vector<int>back(m,0);

	int curMin = prices[0];

	for (int i = 1; i < m; i++)
	{
		curMin = min(curMin,prices[i]);
		forw[i] = max(forw[i-1],prices[i]-curMin);
	}

	int curMax = prices[m-1];

	for (int i = m - 2; i >= 0; i--)
	{
		curMax = max(curMax,prices[i]);
		back[i] = max(back[i+1],curMax-prices[i]);

		ret = max(ret,back[i]+forw[i]);

	}

	return ret;
}

void main()
{
	int data[] = { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
	int n = sizeof(data) / sizeof(int);
	vector<int>list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(data[i]);
	}

	int result = maxProfit(list);

}