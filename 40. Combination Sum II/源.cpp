#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


vector<vector<int>>result;

void dfs(int curIndex,int curSum,int target,vector<int>candidates,vector<int>list)
{
	if (curIndex == candidates.size())
	{
		if (curSum == target)
		{
			vector<int>cur = list;
			sort(cur.begin(), cur.end());
			result.push_back(cur);
			return;
		}
		else
			return;
	}
	if (curSum == target)
	{
		vector<int>cur = list;
		sort(cur.begin(), cur.end());
		result.push_back(cur);
		return;
	}
	else if (curSum > target)
		return;

	list.push_back(candidates[curIndex]);
	dfs(curIndex + 1, curSum + candidates[curIndex],target,candidates,list);
	list.pop_back();

	dfs(curIndex+1,curSum,target,candidates,list);
	
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
	vector<int>list;
	dfs(0,0,target,candidates,list);

	set<vector<int>>correctResult;
	for (int i = 0; i < result.size(); i++)
	{
		correctResult.insert(result[i]);
	}
	result.clear();
	set<vector<int>>::iterator it;
	for (it = correctResult.begin(); it != correctResult.end();it++)
	{
		result.push_back(*it);
	}
	return result;
}

void main()
{

}