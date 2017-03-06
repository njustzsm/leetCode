#include<iostream>
#include<vector>

using namespace std;

int find(vector<int> nums)
{
	int p = 0, q = nums.size() - 1;

	while (p<q)
	{
		int mid = (p + q) / 2;
		if (nums[mid]>nums[q - 1])
			p = mid + 1;
		else if (nums[mid]<nums[q-1])
		{
			q = mid - 1;
		}
		else
		{
			int cur = mid;
			while (cur<q-1&&nums[cur]==nums[mid])
			{
				cur++;
			}
			if (cur == q - 1)
			{
				q = mid - 1;
			}
			else
				p = mid + 1;
		}
	}
	return p;
}

bool search(vector<int>& nums, int target)
{
	if (nums.size() == 0)return false;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
			return true;
	}
	return false;


	

}
void main()
{

}