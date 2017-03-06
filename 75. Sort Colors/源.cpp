#include<iostream>
#include<vector>
using namespace std;


void sortColors(vector<int>& nums) 
{
	if (nums.size() == 0)return;

	int low = 0, cur = 0, high = nums.size() - 1;

	while (cur<=high)
	{
		switch (nums[cur])
		{
		case 0:
			nums[cur] = nums[low];
			nums[low] = 0;
			low++;
			cur++;
			break;
		case 1:
			cur++;
			break;
		default:
			nums[cur] = nums[high];
			nums[high] = 2;
			high--;
			break; 
		}
	}
}

void main()
{
	vector<int>nums;
	nums.push_back(1);
	nums.push_back(0);
	sortColors(nums);
}