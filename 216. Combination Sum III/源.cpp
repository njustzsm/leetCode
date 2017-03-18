#include<iostream>
#include<vector>


using namespace std;

int num;
int sum;
vector<vector<int>>result;

void dfs(int cur,int curSum,vector<int>path)
{
	if (cur == num)
	{
		if (curSum == sum)
		{
			result.push_back(path);
			return;
		}
		return;
		
	}

	int src = 1;
	if (path.size() != 0)
		src = path[path.size() - 1] + 1;

	for (int i=src; i<= 9; i++)
	{
		if (curSum + i <= sum)
		{
			path.push_back(i);
			dfs(cur+1,curSum+i,path);
			path.pop_back();
		}
	}
	
}

vector<vector<int>> combinationSum3(int k, int n) 
{
	num = k;
	sum=n;

	vector<int>path;
	dfs(0,0,path);
	return result;

}

void main()
{
	vector<vector<int>>result=combinationSum3(3,7);
}