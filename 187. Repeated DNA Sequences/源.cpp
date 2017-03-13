#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) 
{
	vector<string>result;
	int m = s.size();
	if (m < 10)return result;

	map<string, int>hashTable;

	for (int i = 0; i <= m - 10; i++)
	{
		string subStr = s.substr(i,10);
		if (hashTable.count(subStr) == 0)
			hashTable[subStr] = 1;
		else
			hashTable[subStr]++;
	}

	map<string, int>::iterator it= hashTable.begin();

	for (; it != hashTable.end(); it++)
	{
		if (it->second >= 2)
		{
			result.push_back(it->first);
		}
	}
	return result;



}
void main()
{

}
