#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<string, int>hashTable;

void init(vector<string> wordDict)
{
	for (int i = 0; i < wordDict.size(); i++)
	{
		hashTable[wordDict[i]] = 0;
	}
}

bool isCheck(string s)
{
	if (hashTable.count(s)>0)return true;

	for (int i = 1; i <s.size(); i++)
	{
		if (hashTable.count(s.substr(0, i))>0)
		{
			if (isCheck(s.substr(i, s.size() - i)))
				return true;
			
		}
	}
	return false;
}


bool wordBreak(string s, vector<string>& wordDict) 
{
	init(wordDict);
	int m = s.size();

	
	

	bool**grid = new bool*[m];
	for (int i = 0; i < m; i++)
	{
		grid[i] = new bool[m];
		memset(grid[i],false,m*sizeof(bool));
	}

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i; j < s.size(); j++)
		{
			if (hashTable.count(s.substr(i, j - i + 1)))
			{
				grid[i][j] = true;
			}
		}
	}

	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = i+1; j < m; j++)
		{
			if (grid[i][j] == false)
			{
				for (int k = i; k < j; k++)
				{
					if (grid[i][k] && grid[k + 1][j])
					{
						grid[i][j] = true;
					}
				}
			}
			
		}
	}

	return grid[0][m - 1];

	

}


void main()
{
	string s = "leetcode";
	vector<string>wordList;
	wordList.push_back("leet");
	wordList.push_back("code");
	wordBreak(s,wordList);
}