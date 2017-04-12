#include<iostream>
#include<vector>

using namespace std;

int maxCoins(vector<int>& nums) 
{
	int n = nums.size();

	int*dp = new int[n];
	//int*lastVal = new int[n];

	dp[0] = nums[0];
	//lastVal[0] = nums[0];

	
	for (int i = 0; i < n; i++)
	{
		//dp[i] = max(dp[i-1]+nums[i]*nums[i-1],dp[i-1]-lastVal[i-1]+);
	}




}

int main()
{
	return 0;

}