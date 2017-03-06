#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) 
{
	if (nums.size() == 0)return 0;
	int result = 0;
	int p = 0, q = nums.size() - 1;

	while (p<=q)
	{
		while (p<=q&&nums[p]!=val)
		{
			p++;
			result++;
		}
		if (p <=q)
		{
			while (p<=q&&nums[q]==val)
			{
				q--;
			}
			if (p <=q)
			{
				nums[p] = nums[q];
				nums[q] = val;
			}
		}
		else
			break;

	}
	return result;
}

void main()
{

}