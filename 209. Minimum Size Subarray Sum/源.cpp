#include<iostream>
#include<vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) 
{
	int p = 0;
	int curSum = 0;

	int result = INT_MAX;

	bool isExist = false;

	for (int i = 0; i < nums.size(); i++)
	{
		curSum += nums[i];

		if (curSum == nums[i])
			p = i;
		

		while (curSum>=s)
		{
			if (i - p + 1 < result)
			{
				result = i - p + 1;
			}
			curSum -= nums[p++];
		}
	}
	if (result!=INT_MAX)
		return result;
	return 0;

}

void main()
{

}