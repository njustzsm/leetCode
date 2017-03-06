#include<iostream>
#include<vector>

using namespace std;

int maxValue = 0;

int maxSubArray(vector<int>& nums) 
{
	maxValue = nums[0];
	int curSum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (curSum <= 0)
		{
			curSum = nums[i];
		}
		else
		{
			curSum += nums[i];
		}
		if (curSum>maxValue)
			maxValue = curSum;
	}
	return maxValue;
}


//动态规划算法
int maxSubArray0(vector<int>& nums)
{
	int*f=new int[nums.size()];
	f[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (f[i - 1] < 0)
			f[i] = nums[i];
		else
			f[i] = f[i - 1] + nums[i];
	}

	int result = f[0];
	for (int i = 0; i < nums.size(); i++)
	{
		if (f[i]>result)
			result = f[i];
	}
	return result;
}



void main()
{

}