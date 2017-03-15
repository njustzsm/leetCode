#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int rob(vector<int>& nums) 
{
	int m = nums.size();
	if (m == 0)return 0;
	if (m == 1)return nums[0];
	if (m == 2)return max(nums[0],nums[1]);


	int result0 = 0, result1 = 0;

	vector<int>list0(nums.begin(),nums.end()-1);
	vector<int>list1(nums.begin() + 1, nums.end());
	
	int*money = NULL;

	if (list0.size() == 1)
		result0 = list0[0];
	else
	{
		money = new int[list0.size()];

		money[0] = list0[0];
		money[1] = max(list0[0], list0[1]);

		for (int i = 2; i < list0.size(); i++)
		{
			money[i] = max(money[i - 1], money[i - 2] + list0[i]);
		}
		result0 = money[list0.size() - 1];
	}
	
	if (money)
		delete[]money;

	if (list1.size() == 1)
		result1 = list1[0];
	else
	{
		money = new int[list1.size()];

		money[0] = list1[0];
		money[1] = max(list1[0], list1[1]);

		for (int i = 2; i < list1.size(); i++)
		{
			money[i] = max(money[i - 1], money[i - 2] + list1[i]);
		}
		result1 = money[list1.size() - 1];
	}
	return max(result0,result1);
}
void main()
{

}