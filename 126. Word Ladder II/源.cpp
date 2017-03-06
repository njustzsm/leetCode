#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;





bool isConnect(string a,string b)
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
	if (sum ==1)return true;
	return false;


}






vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
	int m = wordList.size();
	vector<int>list;
	vector<vector<int>>grid(m,list);

	

	for (int i = 0; i < m; i++)
	{
		string cur = wordList[i];
		for (int j = i + 1; j < m; j++)
		{
			if (isConnect(cur,wordList[j]))
			{
				grid[i].push_back(j);
				grid[j].push_back(i);
			}
		}
	}


	
	bool*Check = new bool[m];
	memset(Check,false,m*sizeof(bool));
	int index = -1;
	for (int i = 0; i < m; i++)
	{
		if (wordList[i] == endWord)
		{
			index = i;
			break;
		}
	}

	vector<vector<string>>result;
	if (index < 0)return result;

	int minLength = INT_MAX;
	queue<int>que;
	que.push(index);
	Check[index] = true;
	
	vector<vector<string>>temp;
	vector<vector<vector<string>>>returnList(m,temp);
	vector<string>tt;
	tt.push_back(endWord);
	returnList[index].push_back(tt);

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		if (wordList[cur] == beginWord || isConnect(wordList[cur], beginWord))
		{
			if (wordList[cur] != beginWord)
			{
				for (int i = 0; i < returnList[cur].size(); i++)
				{
					returnList[cur][i].push_back(beginWord);
				}
			}

			if (returnList[cur][0].size() <= minLength)
			{
				if (returnList[cur][0].size() < minLength)
				{
					result.clear();
				}
				for (int i = 0; i < returnList[cur].size(); i++)
				{
					result.push_back(returnList[cur][i]);
				}
				minLength = returnList[cur][0].size();
			}
		}

		for (int i = 0; i < grid[cur].size(); i++)
		{
			int nextn = grid[cur][i];
			if (!Check[nextn] || returnList[cur][0].size() + 1 <= returnList[nextn][0].size())
			{
				for (int j = 0; j < returnList[cur].size(); j++)
				{
					vector<string>temp = returnList[cur][j];
					temp.push_back(wordList[nextn]);
					returnList[nextn].push_back(temp);
				}
			}
			if (!Check[nextn])
			{
				Check[nextn] = true;
				que.push(nextn);
			}
		}

	}

	for (int i = 0; i < result.size(); i++)
	{
		int p = 0, q = result[i].size() - 1;
		while (p<q)
		{
			string str = result[i][p];
			result[i][p] = result[i][q];
			result[i][q] = str;
			p++;
			q--;
		}
	}

	return result;


	/*vector<vector<string>>returnList;

	for (int i = 0; i < result.size(); i++)
	{
		vector<string>list;
		if (wordList[result[i][0]] != beginWord)
			list.push_back(beginWord);
		for (int j = 0; j < result[i].size(); j++)
		{
			
			list.push_back(wordList[result[i][j]]);
		}
		returnList.push_back(list);
	}

	return returnList;*/
	
}


void main()
{
	string a = "hit";
	string b = "cog";
	string data[] = { "hot", "dot", "dog", "lot", "log", "cog" };
	vector<string>wordList;
	for (int i = 0; i < 6; i++)
		wordList.push_back(data[i]);
	
	findLadders(a,b,wordList);
}