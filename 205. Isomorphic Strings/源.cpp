#include<iostream>
#include<string>

using namespace std;


bool isIsomorphic(string s, string t) 
{
	if (s.size() != t.size())return false;


	int s2t[256],t2s[256];

	for (int i = 0; i < 256; i++)
	{
		s2t[i] = t2s[i] = -1;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s2t[s[i]] < 0 && t2s[t[i]] < 0)
		{
			s2t[s[i]] = t[i];
			t2s[t[i]] = s[i];
		}
		else if (s2t[s[i]] >= 0 && t2s[t[i]] >= 0)
		{
			int sChar = s[i];
			int tChar = t[i];

			if (s2t[sChar] != tChar || t2s[tChar] != sChar)
				return false;
		}
		else
			return false;
	}

	return true;





}

void main()
{

}