#include<iostream>
#include<string>

using namespace std;


bool isDigit(char a)
{
	if (a >= '0'&&a <= '9')
		return true;
	return false;
}


bool isAnNum(string s)
{
	if (s.size() == 0)return false;
	if (s == "+" || s == "-"||s==".")return false;

	int left = 0, right = 0;

	int p = 0;
	if (s[p] == '+' || s[p] == '-')p++;
	while (p < s.size() && isDigit(s[p]))
	{
		left++;
		p++;
	}
	if (p == s.size())return true;

	if (s[p] != '.')return false;

	p++;
	while (p < s.size() && isDigit(s[p]))
	{
		right++;
		p++;
	}
	if (p == s.size()&&left+right>0)return true;
	return false;

}

bool scanNum(string s)
{
	if (s.size() == 0)return false;
	if (s == "+" || s == "-")return false;

	int p = 0;
	if (s[p] == '+' || s[p] == '-')p++;
	while (p < s.size() && isDigit(s[p]))
	{
		p++;
	}
	if (p == s.size())return true;
	return false;
}


bool isNumber(string s)
{

	if (s.size() == 0)return false;

	while (s[s.size()-1]==' ')
	{
		s = s.substr(0,s.size()-1);
	}
	if (s.size() == 0)return false;
	while (s.size()>0&&s[0] == ' ')
	{
		s = s.substr(1);
	}
	if (s.size() == 0)return false;

	
	int p = 0;

	while (p<s.size()&&s[p]!='e')
	{
		p++;
	}

	if (p == s.size())
		return isAnNum(s);
	else
	{
		return isAnNum(s.substr(0,p)) && scanNum(s.substr(p+1));
	}

	


}



void main()
{

}