#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>>result;
vector<int>data;
void dfs(int cur,vector<int>list)
{
	if (cur == data.size())
	{
		result.push_back(list);
		return;
	}


	dfs(cur+1,list);

	list.push_back(data[cur]);
	dfs(cur + 1, list);
	list.pop_back();

}

vector<vector<int>> subsets(vector<int>& nums)
{
	data = nums;
	vector<int>list;
	dfs(0,list);
	return result;
}

void main()
{

}