#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int result = 0;
int n;
vector<int>price;

void dfs(int cur,int cumSum)
{
	if (cur == n)
	{
		result = max(result,cumSum);
	}




}



int maxProfit(vector<int>& prices) 
{
	price = prices;
	n = prices.size();




}

int main()
{
	return 0;
}