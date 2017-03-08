#include<iostream>
#include<vector>

using namespace std;

vector<int>data;
int getMax(int src,int dst)
{
	if (dst < src)return INT_MIN;
	if (src == dst)return data[src];

	int result = INT_MIN;

	vector<int>negationIndex;

	long long int total = 1;

	for (int i = src; i <= dst; i++)
	{
		if (data[i] < 0)
		{
			negationIndex.push_back(i);
		}
		total *= data[i];
	}

	if (negationIndex.size() % 2 == 0)
	{
		if (total>INT_MAX)
			return INT_MAX;
		return total;
	}
	else
	{
		int leftIndex = negationIndex[0];
		int rightIndex = negationIndex[negationIndex.size()-1];

		long long int leftResult = 1;

		for (int i = src; i < leftIndex; i++)
		{
			leftResult *= data[i];
		}
		if (leftResult>result)
			result = leftResult;

		long long int rightResult = 1;
		for (int i = rightIndex + 1; i <= dst; i++)
		{
			rightResult *= data[i];
		}
		if (rightResult > result)
			result = rightResult;

		if (total / leftResult / data[leftIndex] > result)
			result = total / leftResult / data[leftIndex];

		if (total / rightResult / data[rightIndex] > result)
			result = total / rightResult / data[rightIndex];

	}
	if (result > INT_MAX)
		return INT_MAX;
	return result;



}

int maxProduct(vector<int>& nums)
{
	
	if (nums.size() == 1)return nums[0];


	data = nums;

	int result = INT_MIN;
	vector<int>zeroIndex;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			zeroIndex.push_back(i);
	}

	if (zeroIndex.size() == 0)
		return getMax(0,nums.size()-1);
	else
	{
		int pre = 0;
		zeroIndex.push_back(nums.size());

		for (int i = 0; i < zeroIndex.size(); i++)
		{
			int cur = getMax(pre,zeroIndex[i]-1);
			if (result < cur)
				result = cur;
			pre = zeroIndex[i] + 1;
		}
	}
	if (result < 0 && zeroIndex.size() != 0)return 0;
	return result;


	


	




}
void main()
{

}