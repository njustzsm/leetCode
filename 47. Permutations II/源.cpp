#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>>check;
vector<vector<int>>result;
bool*isCheck;

bool haveChoosed(int index,int value)
{
	if (check[index].size() == 0)return false;
	for (int i = 0; i < check[index].size(); i++)
	{
		if (check[index][i] == value)
			return true;
	}
	return false;
}
void dfs(int cur, vector<int>nums, vector<int>list)
{
	if (cur == nums.size())
	{
		result.push_back(list);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (!isCheck[i]&&!haveChoosed(cur,nums[i]))
		{
			check[cur].push_back(nums[i]);
			for (int j = cur + 1; j < nums.size(); j++)
				check[j].clear();
			isCheck[i] = true;
			list.push_back(nums[i]);
			dfs(cur + 1, nums, list);
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
	for (int i = 0; i < nums.size();i++)
		check.push_back(list);

	dfs(0, nums, list);
	return result;
	//vector<vector<int>>tt(result.size());
	//copy(result.begin(), result.end(), tt.begin());
//	return tt;
}

void main()
{
	vector<int>nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	//nums.push_back(0);
	//nums.push_back(2);
	//nums.push_back(3);
	//nums.push_back(2);

	vector<vector<int>>tt = permute(nums);
}