#include<iostream>
#include<string>
#include<algorithm>

using namespace std;



int lengthOfLongestSubstring(string s) 
{
	if (s.size() == 0)return 0;

	int map[128] = { 0 };

	int p = 0, q = 1;

	map[s[0]] = 1;

	int result = 1;

	while (q<s.size())
	{
		char a = s[q];
		if (map[a] == 1)
		{
			while (s[p]!=a)
			{
				map[s[p]] = 0;
				p++;
			}
			p++;
		}
		else
		{
			map[a] = 1;
		}
		result = max(result, q - p+1);
		q++;
	}
	return result;

}

void main()
{
	string s = "abcabcbb";
	lengthOfLongestSubstring(s);
}