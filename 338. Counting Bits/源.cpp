#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


//网上找到的方法
vector<int> countBits0(int num) {
	vector<int> dp(num + 1);
	for (int n = 1; n <= num; n++){
		dp[n] = dp[n & (n - 1)] + 1;
	}
	return dp;
}


vector<int> countBits(int num) 
{
	vector<int>result;

	result.push_back(0);

	for (int i = 1; i <= num; i++)
	{
		int rate = log2(i);
		int res = i - pow(2, rate);

		if (res == 0)
		{
			result.push_back(1);
			continue;
		}
		else
		{
			int tt = result[res];
			result.push_back(tt+1);
		}
	}
	
	return result;
}
int main()
{
	return 0;
}