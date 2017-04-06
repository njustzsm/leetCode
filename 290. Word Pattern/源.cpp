#include<iostream>
#include<string>
#include<map>

using namespace std;


bool wordPattern(string pattern, string str) 
{
	string hashTable[26];
	map<string, char>myMap;

	for (int i = 0; i < 25;i++)
		hashTable[i] = "";

	int index = 0,pre=0;

	str += " ";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			string subStr = str.substr(pre,i-pre);
			pre = i + 1;
			if (index == pattern.size())
				return false;
			char cur = pattern[index++];
			int curIndex = cur - 'a';
			if (hashTable[curIndex] == "")
			{
				hashTable[curIndex] = subStr;
			}
			if (myMap.count(subStr) == 0)
			{
				myMap[subStr] = cur;
			}
			else if (myMap[subStr] != cur)
				return false;

			if (hashTable[curIndex] != subStr)
				return false;
		}
	}
	
	if (index == pattern.size())
		return true;
	return false;

}

int main()
{
	string pattern = "aba";
	string str = "dog cat cat dog";
	bool result = wordPattern(pattern,str);
}