#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
	map<int, int>hashTable;

	for (int i = 0; i < nums.size(); i++)
	{
		if (hashTable.count(nums[i]))
			return true;
		hashTable[nums[i]] = 0;
	}
	return false;


}

void main()
{
	
}