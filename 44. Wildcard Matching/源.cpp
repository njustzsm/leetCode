#include<iostream>
#include<string>

using namespace std;


bool isMatch(string s, string p) 
{
	int ss = 0, pp = 0;
	while (ss<s.size()&&pp<p.size())
	{
		if (s[ss] == p[pp]||p[pp]=='?')
		{
			ss++;
			pp++;

		}
		else if (p[pp] == '*')
		{
			int num = 0;
			int index = -1;
			for (int i = pp; i < p.size(); i++)
			{
				if (p[i] == '*')continue;
				else if (p[i] == '?')
				{
					num++;
				}
				else
				{
					index = i;
					break;
				}
			}
			if (index < 0 && num == 0)return true;
			if (index < 0 && num != 0)
			{
				if (num <= s.size() - ss)
					return true;
				else return false;
			}

			
			for (int i = ss + num; i < s.size(); i++)
			{
				if (s[i] == p[index])
				{
					bool result = isMatch(s.substr(i),p.substr(index));
					if (result)
						return true;
				}
			}
			return false;



		}
		else
		{
			return false;
		}
	}
	if (pp == p.size() && ss == s.size())
		return true;
	else if (ss==s.size())
	{
		for (; pp < p.size(); pp++)
		{
			if (p[pp] != '*')
				return false;
		}
		return true;
	}
	return false;
}

void main()
{
	string src = "zacabz";
	string p = "*a?b*";
	bool result = isMatch(src,p);
}