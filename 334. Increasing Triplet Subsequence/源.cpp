#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool increasingTriplet(vector<int>& nums) 
{
	int*minValue, *maxValue;
	int num = nums.size();
	if(num <= 2)return false;


	minValue = new int[num];
	maxValue = new int[num];
	

	minValue[0] = nums[0];
	maxValue[num - 1] = nums[num - 1];

	for (int i = 1; i < num; i++)
	{
		minValue[i] = min(minValue[i-1],nums[i]);
	}
	for (int i = num - 2; i >= 0; i--)
	{
		maxValue[i] = max(maxValue[i+1],nums[i]);
	}

	for (int i = 1; i < num - 1; i++)
	{
		if (nums[i]>minValue[i - 1] && nums[i] < maxValue[i + 1])
			return true;
	}
	return false;

}


int main()
{
	int tt[] = {1,2,2,1};
	int num = sizeof(tt) / sizeof(int);
	vector<int>data;
	for (int i = 0; i < num; i++)
	{
		data.push_back(tt[i]);
	}

	bool result = increasingTriplet(data);
	return 0;
}