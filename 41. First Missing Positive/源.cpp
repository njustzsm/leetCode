#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	if (nums.size() == 0)return 1;

	sort(nums.begin(),nums.end());

	int p = 0;
	while (nums[p]<=0&&p<nums.size())
	{
		p++;
	}

	if (p == nums.size()||nums[p]!=1)return 1;
	
	for (int i = p; i < nums.size() - 1; i++)
	{
		if (nums[i + 1] - nums[i] <= 1)continue;
		else
			return nums[i] + 1;
	}
	return nums[nums.size() - 1] + 1;
	
	

}

void main()
{
	vector<int>nums;
	nums.push_back(1);
	int result = firstMissingPositive(nums);
}