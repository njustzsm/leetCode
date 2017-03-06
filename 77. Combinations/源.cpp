#include<iostream>
#include<vector>

using namespace std;


bool*data;
vector<vector<int>>result;
int length;
int totalsum;

void dfs(int cur,vector<int>list)
{
	if (cur == length+1)
	{
		result.push_back(list);
		return;
	}

	int src = totalsum;

	while (src >=1&&!data[src])
	{
		src--;
	}
	src++;

	for (; src <= totalsum; src++)
	{
		data[src] = true;
		list.push_back(src);
		dfs(cur+1,list);
		list.pop_back();
		data[src] = false;
	}

	

}

vector<vector<int>> combine(int n, int k) 
{
	length = k;
	data = new bool[n+1];
	memset(data,false,(n+1)*sizeof(bool));
	totalsum = n;
	vector<int>list;
	dfs(1,list);
	return result;
}
void main()
{

}