#include<iostream>
#include<string>

using namespace std;

int lengthOfLastWord(string s) 
{
	if (s.size() == 0)return 0;

	int p=s.size()-1;
	while (p>=0&&s[p]==' ')
	{
		p--;
	}

	int cur = p;
	if (cur < 0)return 0;

	while (p>=0&&s[p]!=' ')
	{
		p--;
	}

	return cur-p;
}

void main()
{

}