#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


int longestConsecutive(vector<int>& nums) 
{
	
	int result = 0;

	map<int, int>hashTable;

	for (int i = 0; i < nums.size(); i++)
	{
		if (hashTable.count(nums[i]) == 0)
		{
			hashTable[nums[i]] = 1;
		}
		else
			hashTable[nums[i]]++;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		int cur = nums[i];
		if (hashTable.count(cur) == 0)continue;
		int p = cur - 1, q = cur + 1;
		hashTable.erase(cur);

		while (hashTable.count(p)!=0)
		{
			hashTable.erase(p);
			p--;
		}
		while (hashTable.count(q) != 0)
		{
			hashTable.erase(q);
			q++;
		}

		result = max(result,(q-1)-(p+1)+1);
	}

	return result;


}

void main()
{

}