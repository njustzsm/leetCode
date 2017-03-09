#include<iostream>
#include<vector>


using namespace std;


int majorityElement(vector<int>& nums)
{
	int curNumber=0;
	int countn = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (countn == 0)
		{
			curNumber = nums[i];
			countn++;
		}
		else
		{
			if (curNumber == nums[i])
				countn++;
			else
				countn--;
		}
	}
	return curNumber;
}

void main()
{

}