#include<iostream>
#include<vector>

using namespace std;


int findMin(vector<int>& nums)
{
	int m = nums.size();

	if (m == 1)return nums[0];


	int result = INT_MAX;

	int p = 0, q = nums.size() - 1;
	
	while (p<q)
	{
		int mid = (p + q) / 2;

		if (nums[mid]>nums[q])
		{
			p = mid + 1;
		}
		else
		{
			q = mid;
		}
	}
	return nums[p];


}
void main()
{

}