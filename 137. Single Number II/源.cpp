#include<iostream>
#include<vector>

using namespace std;


int singleNumber(vector<int>& nums) 
{
	int result=0;
	for (int i = 0; i < 32; i++)
	{
		int mask = 1 << i;
		int count = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (mask&nums[i])
			{
				count++;
			}
		}
		if (count % 3)
		{
			result |= mask;
		}
	}
	
	return result;



}
void main()
{

}