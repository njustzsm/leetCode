#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>*path;



int num;
bool*check;

int getHeight(int root)
{
	memset(check,false,num*sizeof(bool));

	int result = -1;
	queue<int>que;
	que.push(root);
	check[root] = true;

	while (!que.empty())
	{
		result++;
		
		int curnum = que.size();
		for (int i = 0; i < curnum; i++)
		{
			int cur = que.front();
			que.pop();

			for (int j = 0; j < path[cur].size(); j++)
			{
				int dst = path[cur][j];
				if (!check[dst])
				{
					que.push(dst);
					check[dst] = true;
				}
			}
		}
	}
	return result;
}

vector<int>getMaxLength(int root,int father)
{
	vector<int>temp;
	vector<int>result;
	result.push_back(root);
	for (int i = 0; i < path[root].size(); i++)
	{
		if (path[root][i] == father)
			continue;

		vector<int>cur = getMaxLength(path[root][i],root);
		if (cur.size()>temp.size())
			temp = cur;
	}

	result.insert(result.end(),temp.begin(),temp.end());
	return result;
}


vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
{
	/*
	作为具有最短深度的树的根节点，一定是最长的列的中间点
	*/
	vector<int>result;
	path = new vector<int>[n];
	check = new bool[n];
	num = n;

	vector<pair<int, int>>edgeNum;
	for (int i = 0; i < n; i++)
	{
		pair<int, int>tt(i,0);
		edgeNum.push_back(tt);
	}

	for (int i = 0; i < edges.size(); i++)
	{
		pair<int, int>cur = edges[i];
		path[cur.first].push_back(cur.second);
		path[cur.second].push_back(cur.first);

	}

	vector<int>temp = getMaxLength(0,-1);

	int newRoot = temp[temp.size()-1];

	vector<int>tt = getMaxLength(newRoot,-1);

	if (tt.size() % 2 != 0)
	{
		result.push_back(tt[tt.size()/2]);
	}
	else
	{
		result.push_back(tt[tt.size() / 2-1]);
		result.push_back(tt[tt.size() / 2]);

	}
	return result;




	
}

int main()
{
	pair<int, int>t0(1, 0); pair<int, int>t1(1, 2); pair<int, int>t2(1, 3);
	vector<pair<int, int>>input;
	input.push_back(t0); input.push_back(t1); input.push_back(t2);

	vector<int>tt = findMinHeightTrees(4,input);
	return 0;
}