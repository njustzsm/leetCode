#include<iostream>
#include<vector>


using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
	if (nums.size() == 0)
		return vector<int>();

	vector<int>result(nums.size(), 0);
	if (nums.size() == 1)
	{
		return result;
	}
	vector<long long int>left, right;
	

	long long int cur = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		cur *= nums[i];
		left.push_back(cur);
	}
	cur = 1;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		cur *= nums[i];
		right.push_back(cur);
	}

	
	result[0] = right[nums.size()-2];
	result[nums.size() - 1] = left[nums.size()-2];

	for (int i = 1; i <=nums.size()-2; i++)
	{
		long long int cur = 1;
		cur *= left[i-1];
		cur *= right[nums.size()-i-2];
		result[i]=cur;
	}
	return result;



}

void main()
{

}
