#include<iostream>
#include<vector>

using namespace std;



int removeDuplicates(vector<int>& nums) 
{
	if (nums.size() <= 1)return nums.size();

	int number = nums[0] - 1;
	int lastNumber = nums[0];
	int result = 1;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != lastNumber)
		{
			result++;
			lastNumber = nums[i];
		}
		else
			nums[i] = number;
	}

	int p = 0, q = 0;

	while (true)
	{
		while (p<result && nums[p] != number)
		{
			p++;
		}
		if (p < result)
		{
			q = p;
			while (q < nums.size() && nums[q] == number)
			{
				q++;
			}
			if (q < nums.size())
			{
				nums[p] = nums[q];
				nums[q] = number;
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