#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


int n;
vector<int>data;
//bool*check;
set<vector<int>>result;


void dfs(int cur, vector<int>list, int curSrc)
{
	if (cur == n)
	{
		sort(list.begin(), list.end());
		result.insert(list);
		return;
	}

	dfs(cur + 1, list, curSrc);

	for (int i = curSrc; i < n; i++)
	{
		list.push_back(data[i]);
		dfs(cur + 1, list, i + 1);
		list.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
	//可以通过一个n位二进制数，0表示有，1表示没有
	vector<int>list;
	vector<vector<int>>tt;
	if (nums.size() == 0)
	{
		tt.push_back(list);
		return tt;
	}

	data = nums;
	n = nums.size();
	dfs(0, list, 0);

	set<vector<int>>::iterator it;
	for (it = result.begin(); it != result.end(); it++)
	{
		tt.push_back(*it);
	}
	return tt;

	
}
void main()
{

}