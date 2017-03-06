#include<iostream>
#include<string>
#include<vector>
using namespace std;

string simplifyPath(string path) 
{
	if (path.size() == 0)return "/";
	if (path[path.size() - 1] != '/')
		path += "/";
	vector<string>stack;

	int pre=0;

	for (int i = 0; i < path.size(); i++)
	{
		if (path[i] == '/')
		{
			if (i - pre>1)
			{
				string cur = path.substr(pre+1,i-pre-1);
				stack.push_back(cur);
				pre = i;
			}
			else
			{
				pre = i;
			}
		}
	}

	vector<string>result;

	for (int i = 0; i < stack.size(); i++)
	{
		if (stack[i] == ".")
			continue;
		else if (stack[i] == "..")
		{
			if (!result.empty())
				result.pop_back();
		}
		else
		{
			result.push_back(stack[i]);
		}
	}

	string tt = "";
	for (int i = 0; i < result.size(); i++)
	{
		tt += "/"+result[i];
	}

	if (tt == "")
	{
		tt = "/";
	}
	return tt;

	

}
void main()
{

}