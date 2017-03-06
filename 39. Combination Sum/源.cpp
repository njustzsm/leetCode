#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>result;


void dfs(int curIndex,int curSum, int target, vector<int>candidates, vector<int>list)
{
	if (curIndex == candidates.size())
	{
		if (curSum == target)
		{
			result.push_back(list);
			return;
		}
		else
			return;
	}
	if (curSum == target)
	{
		result.push_back(list);
		return;
	}
	else if (curSum > target)
		return;

	for (int i = 0; i <=(target / candidates[curIndex]); i++)
	{
		for (int j = i; j > 0; j--)
		{
			curSum += candidates[curIndex];
			list.push_back(candidates[curIndex]);
		}
		dfs(curIndex+1,curSum,target,candidates,list);

		for (int j = i; j > 0; j--)
		{
			curSum -= candidates[curIndex];
			list.pop_back();
		}

	}

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
	vector<int>list;
	dfs(0,0,target,candidates,list);
	return result;
}
void main()
{
	vector<int>candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	int target = 7;
	combinationSum(candidates,target);
}
