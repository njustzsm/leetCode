#include<iostream>
#include<string>

using namespace std;


int get(string s)
{
	if (s.size() == 0)return 1;
	if (s.size() == 1)
	{
		if (s == "0")return 0;
		return 1;
	}
	if (s[0] == '0')return 0;

	char*tt = new char[3];
	tt[0] = s[0];
	tt[1] = s[1];
	tt[2] = '\0';
	int nn = atoi(tt);

	if (nn <= 26)
		return get(s.substr(1)) + get(s.substr(2));
	else
		return get(s.substr(1));

}

int*nums;

int numDecodings(string s) 
{

	if (s.size() == 0)return 0;

	nums = new int[s.size()+1];
	nums[s.size()] = 1;

	char*tt = new char[3];
	tt[2] = '\0';

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (i == s.size() - 1)
		{
			if (s[i] == '0')
				nums[i] = 0;
			else
				nums[i] = 1;
			continue;
		}
		if (s[i] == '0')
		{
			nums[i] = 0;
			continue;
		}
		tt[0] = s[i];
		tt[1] = s[i + 1];
		int nn = atoi(tt);
		if (nn <= 26)
		{
			nums[i] = nums[i + 1] + nums[i + 2];
		}
		else
			nums[i] = nums[i + 1];
	}

	return nums[0];




}
void main()
{

}