#include<iostream>
#include<string>


using namespace std;


bool isPalindrome(string s) 
{
	if (s.size() == 0||s.size()==1)return true;

	int p = 0, q = s.size() - 1;

	while (p<q)
	{
		if (s[p] >= 'A'&&s[p] <= 'Z')
		{
			s[p] += 32;
		}
		if (s[q] >= 'A'&&s[q] <= 'Z')
		{
			s[q] += 32;
		}

		if (!((s[p]>='a'&&s[p]<='z')||(s[p]>='0'&&s[p]<='9')))
		{
			p++;
			continue;
		}
		if (!((s[q] >= 'a'&&s[q] <= 'z') || (s[q] >= '0'&&s[q] <= '9')))
		{
			q--;
			continue;
		}

		

		if (s[p] == s[q])
		{
			p++;
			q--;
		}
		else
			return false;
	}

	return true;
	

	



}

void main()
{
	string s = "ab";
	isPalindrome(s);
}