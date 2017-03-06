#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int longestValidParentheses(string s) 
{
	int length = s.length();

	vector<int>Vec;
	int maxLength = 0;

	Vec.push_back(0);

	for (int i = 1; i < length; i++)
	{
		if (s[i] == ')')
		{
			if (Vec.size()>0 && s[Vec[Vec.size() - 1]] == '(')
				Vec.pop_back();
			else
				Vec.push_back(i);
		}
		else
			Vec.push_back(i);
	}

	if (Vec.size() == 0)
		return s.size();
	
	int left = -1;
	Vec.push_back(s.size());

	for (int i = 0; i < Vec.size(); i++)
	{
		if (Vec[i] - left-1>=2)
		{
			if (Vec[i] - left - 1 >= maxLength)
				maxLength = Vec[i] - left - 1;
		}
		left = Vec[i];
	}

	return maxLength;
	
	
}

void main()
{
	string s = "())";
	int length = longestValidParentheses(s);
}