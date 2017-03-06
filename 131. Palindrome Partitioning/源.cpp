#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<string>>result;

bool isPar(string s)
{
	if (s.size() == 1)return true;

	int p = 0, q = s.size() - 1;

	while (p<q)
	{
		if (s[p] != s[q])
			return false;
		p++;
		q--;
	}
	return true;

}

void dfs(string s,vector<string>list)
{
	if (s.size() == 0)
	{
		result.push_back(list);
		return;
	}

	for (int i = 0; i < s.size(); i++)
	{
		string subStr = s.substr(0,i+1);
		if (isPar(subStr))
		{
			list.push_back(subStr);
			if (i == s.size() - 1)
				dfs("", list);
			else
				dfs(s.substr(i+1,s.size()-i-1),list);

			list.pop_back();
		}
	}
}


vector<vector<string>> partition(string s) 
{
	vector<string>list;
	dfs(s,list);
	return result;
}

void main()
{

}