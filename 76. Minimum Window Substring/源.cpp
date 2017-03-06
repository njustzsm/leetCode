#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;

string minWindow(string s, string t) 
{
	if (t == "")return "";
	if (t.size() > s.size())return "";
	string result ="";
	map<char, int>hash;
	map<char, int>check;
	for (int i = 0; i < t.size(); i++)
	{
		
		if (hash.count(t[i]) == 0)
		{
			hash[t[i]] = 1;
			check[t[i]] = 0;
		}
		else
		{
			hash[t[i]]++;
		}
	}

	int curSum = 0;
	int src = 0;
	queue<int>Que;
	for (int i = 0; i < s.size(); i++)
	{
		if (check.count(s[i])>0)
		{
			check[s[i]]++;
			Que.push(i);
			if (check[s[i]] <= hash[s[i]])
			{
				curSum++;
			}
			while (!Que.empty() && (check.count(s[Que.front()]) == 0 || (check[s[Que.front()]]>hash[s[Que.front()]])))
			{
				if (check.count(s[Que.front()]) > 0)
					check[s[Que.front()]]--;
				Que.pop();
			}
			if (curSum == t.size())
			{
				if (i - Que.front() + 1 < result.size()||result=="")
				{
					result = s.substr(Que.front(), i - Que.front() + 1);
				}
			}
		}
		else
		{
			if (!Que.empty())
			{
				Que.push(i);
			}
		}
	}
	
	return result;
	

	



}

void main()
{
	string s = "a";
	string t = "a";
	string result = minWindow(s,t);
}
