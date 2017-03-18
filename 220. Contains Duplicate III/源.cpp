#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;




bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	if (nums.size() == 0 )
		return false;
	multiset<long>mySet;
	queue<int>que;

	for (int i = 0; i <=k&&i < nums.size(); i++)
	{
		mySet.insert(nums[i]);
		que.push(nums[i]);
	}

	multiset<long>::iterator it = mySet.begin();

	int pre = *it;
	it++;

	for (; it!=mySet.end(); it++)
	{
		if (abs(*it - pre) <= t)
			return true;
		pre = *it;
	}


	for (int i = k+1; i < nums.size(); i++)
	{
		que.push(nums[i]);
		int tail = que.front();
		que.pop();
		
		mySet.erase(mySet.find(tail));
		mySet.insert(nums[i]);

		it = mySet.find(nums[i]);

		if (it != mySet.begin())
		{
			it--;
			int left = *it;
			if (nums[i] - left <= t)
				return true;
			it++;
		}

		it++;
		if (it != mySet.end())
		{
			int right = *it;
			if (right - nums[i] <= t)
				return true;
		}
	}
	return false;





}

void main()
{

}