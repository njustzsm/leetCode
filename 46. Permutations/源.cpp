#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>result;
bool*isCheck;

void dfs(int cur,vector<int>nums,vector<int>list)
{
	if (cur == nums.size())
	{
		result.push_back(list);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (!isCheck[i])
		{
			isCheck[i] = true;
			list.push_back(nums[i]);
			dfs(cur+1,nums,list);
			list.pop_back();
			isCheck[i] = false;
		}
	}
}


vector<vector<int>> permute(vector<int>& nums) 
{
	isCheck = new bool[nums.size()];
	memset(isCheck, false, nums.size()*sizeof(bool));
	vector<int>list;
	dfs(0,nums,list);
	return result;
}

void main()
{

}