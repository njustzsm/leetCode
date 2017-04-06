#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



//时间复杂度为O（n*n）
int lengthOfLIS0(vector<int>& nums) 
{
	int n = nums.size();
	if (n <= 1)return n;

	int*dis = new int[n];
	memset(dis,0,n*sizeof(int));

	dis[0] = 1;

	for (int i = 0; i < n; i++)
	{
		dis[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dis[i] = max(dis[i],dis[j]+1);
			}
		}
	}
	
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result = max(result,dis[i]);
	}
	return result;

}

//时间复杂度为O（nlogn）
/*
该方法的原理是，前端已经计算过的值尽量取最小值
*/
int lengthOfLIS(vector<int>& nums)
{
	int n = nums.size();
	
	vector<int>res;

	for (int i = 0; i < n; i++)
	{
		vector<int>::iterator it = lower_bound(res.begin(),res.end(),nums[i]);
		if (it == res.end())
		{
			res.push_back(nums[i]);
		}
		else
			*it = nums[i];
	}

	return res.size();

}

int main()
{
	int data[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int len = sizeof(data) / sizeof(int);
	vector<int>input;
	for (int i = 0; i < len; i++)
	{
		input.push_back(data[i]);
	}
	int result = lengthOfLIS(input);
}