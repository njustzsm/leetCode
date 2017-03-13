#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int rob(vector<int>& nums) 
{
	int m = nums.size();
	if (!m)return 0;

	if (m == 1)return nums[0];


	int*money = new int[m];
	money[0] = nums[0];
	money[1] = nums[1];
	


	for (int i = 1; i < m; i++)
	{
		money[i] = max(money[i-2]+nums[i],money[i-1]);
	}


	return money[m-1];


}

void main()
{

}