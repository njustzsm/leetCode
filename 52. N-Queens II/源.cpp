#include<iostream>
#include<string>
#include<vector>

using namespace std;


int length = -1;
int result=0;


bool isAttack(int x0, int y0, int x1, int y1)
{
	if (x0 == x1 || y0 == y1 || abs(x0 - x1) == abs(y0 - y1))
		return true;

	return false;
}

bool isValid(int x, int y, vector<int>pre)
{
	for (int i = 0; i < pre.size(); i += 2)
	{
		int xx = pre[i];
		int yy = pre[i + 1];
		if (isAttack(x, y, xx, yy))
			return false;
	}
	return true;
}
void dfs(int cur, vector<int>pre)
{
	if (cur == length)
	{
		result++;
		return;
	}

	for (int i = 0; i < length; i++)
	{
		if (isValid(cur, i, pre))
		{
			pre.push_back(cur);
			pre.push_back(i);
			dfs(cur + 1, pre);
			pre.pop_back();
			pre.pop_back();
		}
	}



}

int solveNQueens(int n)
{
	length = n;
	vector<int>list;
	dfs(0, list);
	return result;
}

void main()
{

}