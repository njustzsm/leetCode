#include<iostream>
#include<vector>

using namespace std;


int searchInsert(vector<int>& nums, int target) 
{
	if (nums.size() == 0)return -1;

	int p = 0, q = nums.size() - 1;

	while (p<q)
	{
		int mid = (p + q) / 2;
		if (nums[mid] < target)
		{
			p = mid + 1;
		}
		else if (nums[mid]>target)
		{
			q = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	if (nums[p] < target)
		return p + 1;
	else
		return p;

}
void main()
{

}
