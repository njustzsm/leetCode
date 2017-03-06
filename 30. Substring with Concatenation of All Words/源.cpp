#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;


void InititalizeMap(map<string,int>&map,vector<string>&words)
{
	for (int i = 0; i < words.size(); i++)
	{
		if (map.count(words[i]) == 0)
		{
			map[words[i]] = 1;
		}
		else
			map[words[i]] += 1;
	}
}


vector<int> findSubstring(string s, vector<string>& words) 
{
	map<string, int>mapOfVec;
	int singleWordLength = words[0].length();
	int wordsLen = words.size();
	int sLen = s.length();

	int i, j, count;
	bool countChanged = false;
	vector<int>result;

	count = wordsLen; //表示还需要找到的字串个数
	if (wordsLen == 0 || sLen == 0)return result;

	InititalizeMap(mapOfVec,words);

	for (int i = 0; i <=sLen - wordsLen*singleWordLength; i++)
	{
		string subStr = s.substr(i,singleWordLength);
		j = i;
		while (mapOfVec.count(subStr)!=0&&mapOfVec[subStr]!=0&&j+singleWordLength<=sLen)
		{
			mapOfVec[subStr] -= 1;
			count--;
			countChanged = true;
			j = j + singleWordLength;
			subStr = s.substr(j,singleWordLength);

			if (mapOfVec.count(subStr) == 0)
				break;
		}
		if (count == 0)
			result.push_back(i);

		if (countChanged)
		{
			mapOfVec.clear();
			InititalizeMap(mapOfVec,words);
			count = wordsLen;
			countChanged = false;
		} 

	}
	return result;

}

void main()
{
	string s = "wordgoodgoodgoodbestword";
	vector<string>words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");
	vector<int>result = findSubstring(s,words);
}
