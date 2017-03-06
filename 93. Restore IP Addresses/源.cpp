#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<string>>result;

void dfs(int cur,string str,vector<string>list)
{
	if (cur == 4)
	{
		result.push_back(list);
		return;
	}

	if (cur == 3)
	{
		if (str.size() == 0 || str.size() > 3)
			return;

		if (str[0] == '0'&&str.size() != 1)
			return;


		int nn = atoi(&str[0]);
		if (nn <= 255)
		{

			list.push_back(str);
			dfs(cur + 1, "", list);
			list.pop_back();
		}
		return;

	}


	int length = 0;
	if (str.size() >= 3)
		length = 3;
	else
		length = str.size();

	for (int i = 1; i <= length; i++)
	{
		string ss = str.substr(0,i);

		if (ss[0] == '0'&&ss.size() != 1)
			continue;
		int nn = atoi(&ss[0]);
		if (nn <= 255)
		{
			list.push_back(ss);
			dfs(cur+1,str.substr(i),list);
			list.pop_back();
		}
	}
}

vector<string> restoreIpAddresses(string s) 
{
	vector<string>list;
	dfs(0, s, list);
	vector<string>address;

	for (int i = 0; i < result.size(); i++)
	{
		string cur= result[i][0];
		for (int j = 1; j < result[i].size(); j++)
		{
			cur += "." + result[i][j];
		}
		address.push_back(cur);
	}
	return address;
}


void main()
{

}