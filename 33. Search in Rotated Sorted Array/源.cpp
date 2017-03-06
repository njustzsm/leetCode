#include<iostream>
#include<vector>

using namespace std;




int search(vector<int>& nums, int target) 
{
	if (nums.size() == 0)return -1;
	int p = 0, q = nums.size() - 1;

	while (p<=q)
	{
		int mid = (p + q) / 2;
		if (nums[mid] > nums[q])
		{
			if (nums[mid] < target)
			{
				p = mid + 1;
			}
			else if (nums[mid]>target)
			{
				if (target > nums[q])
					q = mid - 1;
				else if (target < nums[q])
					p = mid + 1;
				else
					return q;
			}
			else
				return mid;
		}
		else
		{
			if (nums[mid] > target)
			{
				q = mid - 1;
			}
			else if (nums[mid] < target)
			{
				if (target < nums[q])
					p = mid + 1;
				else if (target>nums[q])
					q = mid - 1;
				else
					return q;
			}
			else
				return mid;
		}
	}
	
	return -1;
}
void main()
{
	vector<int>nums;
	nums.push_back(1);
	nums.push_back(3);
	//nums.push_back(1);
	int target = 3;
	search(nums,target);
}