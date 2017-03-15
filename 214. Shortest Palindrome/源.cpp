#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s)
{
	int m = s.size();
	if (m == 1)return true;

	int p = 0, q = m - 1;
	while (p<q)
	{
		if (s[p] != s[q])
			return false;
		p++;
		q--;
	}
	return true;
}


string shortestPalindrome(string s) 
{
	int m = s.size();
	if (m == 0)return "";

	if (isPalindrome(s))return s;

	string result = s;

	for (int i = m - 1; i >= 1; i--)
	{
		string str = s.substr(0,i);
		if (isPalindrome(str))
		{
			for (int j = i; j < m; j++)
			{
				result= s[j]+result;
			}
			return result;
		}
	}


}

void main()
{

}