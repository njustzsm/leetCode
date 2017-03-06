#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


long long int getNum(string str)
{
	int nums[26] = {0};
	for (int i = 0; i < str.size(); i++)
	{
		int tt = str[i] - 'a';
		nums[tt]++;
	}

	long long int result = 0;

	for (int i = 0; i < 26; i++)
	{
		result = result * 10 + nums[i];
	}
	return result;
}


vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	map<long long int, vector<string>>stack;

	for (int i = 0; i < strs.size(); i++)
	{
		long long int cur = getNum(strs[i]);
		if (stack.count(cur) == 0)
		{
			vector<string>list;
			list.push_back(strs[i]);
			stack[cur] = list;
		}
		else
		{
			stack[cur].push_back(strs[i]);
		}
	}

	vector<vector<string>>result;

	map<long long int, vector<string>>::iterator it;

	for (it = stack.begin(); it != stack.end(); it++)
	{
		result.push_back(it->second);
	}

	return result;
}

void main()
{

}