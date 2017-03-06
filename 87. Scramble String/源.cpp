#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;





bool isScramble(string s1, string s2) 
{
	if (s1 == s2)return true;
	if (s1.size() != s2.size())return false;

	vector<int>countn(26,0);

	for (int i = 0; i < s1.size(); i++)
	{
		countn[s1[i] - 'a']++;
		countn[s2[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (countn[i] != 0)return false;
	}

	for (int i = 1; i < s1.size(); i++)
	{
		if ((isScramble(s1.substr(0, i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
			|| (isScramble(s1.substr(0, i),s2.substr(s2.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.size()-i))))
		{
			return true;
		}
	}
	return false;

}

void main()
{
	string s1 = "hobobyrqd";
	string s2 = "hbyorqdbo";
	isScramble(s1,s2);
}