#include<iostream>
#include<string>
#include<algorithm>
using namespace std;




string getLength(string s,int mid)
{
	int n = s.size();

	string result = "";
	result += s[0];

	int p = mid - 1, q = mid + 1;
	while (p>=0&&q<n&&s[p]==s[q])
	{
		if (q - p + 1>result.size())
		{
			result = s.substr(p,q-p+1);
		}
		p--;
		q++;
	}

	p = mid, q = mid + 1;
	while (p>=0&&q<n&&s[p]==s[q])
	{
		if (q - p + 1>result.size())
		{
			result = s.substr(p, q - p + 1);
		}
		p--;
		q++;
	}


	return result;
}

string longestPalindrome(string s) 
{
	if (s.size() == 0)return "";

	string result = "";
	result += s[0];

	for (int i = 1; i <s.size(); i++)
	{
		if (s.size() - i<result.size() / 2 + 1)
			break;
		string cur = getLength(s,i);
		if (cur.size() > result.size())
			result = cur;
	}
	return result;

}

void main()
{
	string s= "babab";
	longestPalindrome(s);
}