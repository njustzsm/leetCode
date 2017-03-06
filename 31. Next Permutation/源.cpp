#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap(vector<int>& nums,int i,int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void nextPermutation(vector<int>& nums) 
{
	if (nums.size() <= 1)return;

	int p = nums.size() - 2;

	for (; p >= 0;p--)
	{
		if (nums[p] < nums[p + 1])
		{
			int minValue = nums[p+1];
			int index = p+1;
			for (int i = p + 1; i < nums.size(); i++)
			{
				if (nums[i]>nums[p] && nums[i] < minValue)
				{
					minValue = nums[i];
					index = i;
				}
			}

			swap(nums,p,index);
			sort(nums.begin()+p+1,nums.end());
			return;
		}
	}

	sort(nums.begin(),nums.end());

}
void main()
{
	int a[] = { 3, 2, 20, 16, 1, 15, 15, 14, 27, 26, 5, 16, 9, 13, 17, 24, 15, 12, 15, 14, 27, 14, 14, 3
		, 20, 7, 18, 6, 8, 8, 24, 3, 11, 14, 19, 12, 0, 26, 18, 19, 22, 16, 6
		, 24, 29, 15, 10, 14, 28, 17, 21, 17, 2, 27, 12, 22 };
	int num = sizeof(a) / sizeof(int);
	vector<int>nums;

	for (int i = 0; i < num; i++)
	{
		nums.push_back(a[i]);
	}

	nextPermutation(nums);

}