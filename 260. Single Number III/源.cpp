#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> singleNumber(vector<int>& nums)
{
	vector<int>result;
	int xorNum = 0;

	for (int i = 0; i < nums.size(); i++)
		xorNum ^= nums[i];


	int stard = xorNum&(~(xorNum - 1));

	vector<int>list1, list2;

	for (int i = 0; i < nums.size(); i++)
	{
		int tt = stard&nums[i];
		if (tt == 0)
		{
			list1.push_back(nums[i]);
		}
		else
			list2.push_back(nums[i]);
	}

	int num1 = 0, num2 = 0;

	for (int i = 0; i < list1.size(); i++)
		num1 ^= list1[i];
	for (int i = 0; i < list2.size(); i++)
		num2 ^= list2[i];

	result.push_back(num1);
	result.push_back(num2);

	return result;

}

void main()
{
	vector<int>data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(1);
	data.push_back(3);
	data.push_back(2);
	data.push_back(5);
	vector<int>result = singleNumber(data);
}