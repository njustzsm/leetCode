#include<iostream>
#include<vector>
#include<map>
using namespace std;


bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	int i = 0;
	map<int, int>hashTable;
	for (; i <=k&&i < nums.size(); i++)
	{
		if (hashTable.count(nums[i]) != 0)
			return true;

		hashTable[nums[i]] = 1;
	}


	if (i == nums.size())return false;

	for (; i < nums.size(); i++)
	{
		int tail = nums[i-k-1];
		hashTable.erase(tail);

		if (hashTable.count(nums[i]) != 0)
			return true;
		hashTable[nums[i]] = 1;
	}

	return false;



}

void main()
{

}