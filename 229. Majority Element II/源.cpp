#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> majorityElement(vector<int>& nums) 
{
	vector<int>result;
	int n = nums.size();
	if (n == 0)return result;

	int num1 = 0, time1 = 0, num2 = 0, time2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (time1 != 0 && num1 == nums[i])
		{
			time1++;
			continue;
		}
		if (time2 != 0 && num2 == nums[i])
		{
			time2++;
			continue;
		}


		if (time1 == 0)
		{
			num1 = nums[i];
			time1++;
			continue;
		}
		if (time2 == 0)
		{
			num2 = nums[i];
			time2++;
			continue;
		}

		time1--;
		time2--;
	}

	
		
		int tt = 0;

		if (time1 > 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (nums[i] == num1)
					tt++;
			}
			if (tt>n / 3)
				result.push_back(num1);
		}
		if (time2 > 0)
		{
			tt = 0;
			for (int i = 0; i < n; i++)
			{
				if (nums[i] == num2)
					tt++;
			}
			if (tt>n / 3)
				result.push_back(num2);
		}
		return result;
}

void main()
{

}