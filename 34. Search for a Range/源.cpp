#include<iostream>
#include<vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int>tt;
	tt.push_back(-1);
	tt.push_back(-1);
	if (nums.size() == 0)
	{
		return tt;
	}

	int p = 0, q = nums.size() - 1;
	int left = -1, right = -1;

	while (p<=q)
	{
		int mid = (p + q) / 2;
		if (nums[mid] > target)
		{
			q = mid - 1;
		}
		else if (nums[mid] < target)
		{
			p = mid + 1;
		}
		else
		{
			if (mid == 0)
			{
				left = 0;
				break;
			}
			else
			{
				if (nums[mid - 1] == target)
				{
					q = mid - 1;
				}
				else
				{
					left = mid;
					break;
				}
			}
		}
	}
	if (left < 0)
		return tt;

	tt.clear();
	tt.push_back(left);
	p = 0;
	q = nums.size() - 1;
	while (p <= q)
	{
		int mid = (p + q) / 2;
		if (nums[mid] > target)
		{
			q = mid - 1;
		}
		else if (nums[mid] < target)
		{
			p = mid + 1;
		}
		else
		{
			if (mid == nums.size()-1)
			{
				right = nums.size() - 1;
				break;
			}
			else
			{
				if (nums[mid + 1] == target)
				{
					p = mid + 1;
				}
				else
				{
					right = mid;
					break;
				}
			}
		}
	}
	tt.push_back(right);
	return tt;
}

void main()
{

}