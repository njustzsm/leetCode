#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;



vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	if (k <= 1)return nums;
	queue<int>que;
	multiset<int>mySet;
	vector<int>result;

	int curMax = INT_MIN;

	
	for (int i = 0; i < k; i++)
	{
		que.push(nums[i]);
		if (curMax < nums[i])
			curMax = nums[i];
		mySet.insert(nums[i]);
	}

	multiset<int>::iterator it;
	result.push_back(curMax);

	for (int i = k; i < nums.size(); i++)
	{
		que.push(nums[i]);
		int tail = que.front();
		que.pop();
		mySet.erase(mySet.find(tail));
		mySet.insert(nums[i]);

		it = mySet.end();
		it--;
		result.push_back(*it);
	}

	return result;










}


void main()
{

}