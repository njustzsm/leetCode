#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;

bool isConnect(string a, string b)
{
	int n = a.size();

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			sum++;
			if (sum>1)
				return false;
		}

	}
	if (sum == 1)return true;
	return false;
}





int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
	vector<vector<int>>grid;
	int minValue = INT_MAX;

	int m = wordList.size();
	vector<int>list;
	for (int i = 0; i < m; i++)
		grid.push_back(list);

	for (int i = 0; i < m; i++)
	{
		string cur = wordList[i];
		for (int j = i + 1; j < m; j++)
		{
			if (isConnect(wordList[j], cur))
			{
				grid[j].push_back(i);
				grid[i].push_back(j);
			}
		}
	}

	int*dis = new int[m];
	bool* check = new bool[m];
			
	memset(dis, 0, m*sizeof(int));
	memset(check, false, m*sizeof(bool));

	int src = -1;
	for (int i = 0; i < m; i++)
	{
		if (wordList[i] == endWord)
		{
			src = i;
			break;
		}
		
	}
	
	if (src < 0)return 0;


	queue<int>que;
	que.push(src);

	check[src] = true;

	while (!que.empty())
	{
		int index = que.front();
		que.pop();

		if (wordList[index] == beginWord||isConnect(wordList[index],beginWord))
		{
			int length = dis[index];
			if (wordList[index] != beginWord)
				length++;
			if (length < minValue)
				minValue = length;

			continue;
		}

		for (int j = 0; j < grid[index].size(); j++)
		{
			if (!check[grid[index][j]])
			{
				int value = dis[index] + 1;
				dis[grid[index][j]] = value;
				check[grid[index][j]] = true;
				que.push(grid[index][j]);
			}
		}
	}

	if (minValue == INT_MAX)return 0;
	return minValue+1;





}
void main()
{
	string a = "hit";
	string b = "cog";
	string data[] = { "hot", "dot", "dog", "lot", "log", "cog" };
	vector<string>wordList;
	for (int i = 0; i < 6; i++)
		wordList.push_back(data[i]);
	int result=ladderLength(a,b,wordList);
}