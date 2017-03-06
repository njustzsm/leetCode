#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	if (nums.size() <= 2)return nums.size();

	vector<int>data;

	int result = 1;
	data.push_back(nums[0]);
	int p = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[p])
		{
			data.push_back(nums[i]);
			result++;
			p = i;
		}
		else if (i - p <= 1)
		{
			data.push_back(nums[i]);
			result++;
		}
	}
	nums.clear();
	nums = data;
	return result;

}

void main()
{

}