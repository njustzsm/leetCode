#include<iostream>
#include<string>
#include<queue>
using namespace std;


void reverseWords(string &s) 
{
	int i = 0;
	while (i<s.size()&&s[i]==' ')
	{
		i++;
	}
	if (i == s.size())
	{
		s = "";
		return;
	}

	s = s.substr(i);
	i = s.size() - 1;
	while (i>=0&&s[i]==' ')
	{
		i--;
	}

	s = s.substr(0,i+1);

	queue<int>emptyCount;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			if (emptyCount.empty())
				emptyCount.push(i);
			else
			{
				if (i == emptyCount.back() + 1)
				{
					s = s.substr(0,i)+s.substr(i+1);
					i--;
				}
				else
				{
					emptyCount.push(i);
				}
			}
		}
			
	}

	if (emptyCount.empty())return;
	

	string result = "";

	int pre = -1;
	while (!emptyCount.empty())
	{
		
		int curIndex = emptyCount.front();
		emptyCount.pop();

		if (result != "")
			result = s.substr(pre + 1, curIndex - pre - 1) + " " + result;
		else
			result = s.substr(pre + 1, curIndex - pre - 1);
		pre = curIndex;
	}

	result = s.substr(pre + 1) + " " + result;
	
	s = result;


	




}
void main()
{
	string s = "   a   b  c d   e  ";
	reverseWords(s);
}