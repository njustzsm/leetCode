#include<iostream>
#include<string>

using namespace std;

bool isEmpty(string s)
{
	if (s.size() == 0)return true;
	if (s.size() == 1)return false;
	if (s.size() % 2 != 0)return false;
	int i = 1;
	while (i<s.size()&&s[i]=='*')
	{
		i += 2;
	}
	if (i < s.size())return false;
	return true;
}

bool isMatch(string s, string p) 
{
	if (s.size() == 0 && p.size() == 0)return true;
	if (p.size()==0)return false;
	if (s.size() == 0)
		return isEmpty(p);
	if (p.size() == 1 || p[1] != '*')
	{
		if (s[0] == p[0] || p[0] == '.')
			return isMatch(s.substr(1), p.substr(1));
		else
			return false;
	}
	else
	{
		if (s[0] != p[0]&&p[0]!='.')
		{
			if (p.size()>2)
				return isMatch(s,p.substr(2));
			return isMatch(s, "");
		}
		else if (p[0]!='.')
		{
			bool result = false;
			int t = 0;
			char cur = s[0];
			while (t<s.size()&&s[t]==cur)
			{
				t++;
			}

			string res="";
			if (p.size()>2)
				res = p.substr(2);
			for (int i = 0; i <=t; i++)
			{
				result = result || isMatch(s.substr(i),res);
			}
			return result;
		}
		else
		{
			bool result = false;
			string res = "";
			if (p.size()>2)
				res = p.substr(2);

			for (int i = 0; i <s.size(); i++)
			{
				result = result || isMatch(s.substr(i),res);
			}
			result = result || isMatch("",res);
			return result;
			
		}
	}
}

void main()
{
	string s = "a";
	string p = "ab*a";
	isMatch(s,p);
}