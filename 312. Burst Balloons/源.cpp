#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

 
int maxCoins(vector<int>& nums) 
{
	int n = nums.size();

	int* arr=new int[n+2];
	arr[0] = arr[n + 1] = 1;

	for (int i = 1; i <= n; i++)
		arr[i] = nums[i - 1];

	int**dp = new int*[n + 2];
	for (int i = 0; i < n + 2; i++)
	{
		dp[i] = new int[n + 2];
	}

	return 0;



}

int main()
{
	vector<int>data{3,1,5,8};
	int result = maxCoins(data);
	return 0;

}