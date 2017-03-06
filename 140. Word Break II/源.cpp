#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
using namespace std;



map<string, int>hashTable;

void init(vector<string> wordDict)
{
	for (int i = 0; i < wordDict.size(); i++)
	{
		hashTable[wordDict[i]] = 0;
	}
}

vector<string> wordBreak(string s, vector<string>& wordDict)
{
	init(wordDict);

	map<int, vector<string>>record;
	int len = s.length();


	//计算的是0到i的字符串的每个解的最后一个字符串
	for (int i = 0; i < len; i++)
	{
		vector<string>words;

		if (hashTable.count(s.substr(0, i + 1)))
			words.push_back(s.substr(0, i + 1));


		for (int j = 1; j <=i; j++)
		{
			vector<string>pres = record[j-1];
			string post = s.substr(j,i-j+1);
			if (!pres.empty() && hashTable.count(post))
				words.push_back(post);
		}

		record.insert(pair<int, vector<string> >(i, words));
	}


	vector<string>result;

	queue<pair<int, string>>que;

	que.push(pair<int,string>(len-1,""));

	
	while (!que.empty())
	{
		pair<int, string>cur = que.front();
		que.pop();
		if (cur.first == -1)
		{
			result.push_back(cur.second);
			continue;
		}

		vector<string>lastWord = record[cur.first];

		for (int i = 0; i < lastWord.size(); i++)
		{
			int nextNum = cur.first - lastWord[i].size();
			if (nextNum < -1)continue;

			if (!cur.second.empty())
				que.push(pair<int,string>(nextNum,lastWord[i]+" "+cur.second));
			else
				que.push(pair<int, string>(nextNum, lastWord[i]));

		}
	}

	return result;
	

}


void main()
{
	string s = "leetcode";
	vector<string>wordList;
	wordList.push_back("leet");
	wordList.push_back("code");
	wordBreak(s, wordList);
}
