#include<iostream>
#include<vector>

using namespace std;

int findDuplicate(vector<int>& nums) 
{
	int p = nums[0];
	int q = nums[nums[0]];

	while (p!=q)
	{
		p = nums[p];
		q = nums[nums[q]];
	}

	p = 0;
	while (p!=q)
	{
		p = nums[p];
		q = nums[q];
	}
	
	return p;

}

int main()
{

}