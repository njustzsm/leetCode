#include<iostream>
#include<vector>
using namespace std;


void moveZeroes(vector<int>& nums) 
{
	int zeroNum=0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i]==0)
		{
			zeroNum++;
		}
		else if (zeroNum != 0)
		{
			nums[i - zeroNum] = nums[i];
		}
	}

	for (int i = nums.size() - zeroNum; i < nums.size(); i++)
	{
		nums[i] = 0;
	}
}

int main()
{
	return 0;
}