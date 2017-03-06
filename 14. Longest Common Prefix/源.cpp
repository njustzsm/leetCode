#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

string getCommonPrefix(string a,string b)
{
	
	int length = a.size();
	if (length > b.size())length = b.size();

	for (int i = 0; i < length; i++)
	{
		if (a[i] != b[i])
			return a.substr(0,i);
	}
	return a.substr(0,length);
}

string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.size() == 1)return strs[0];
	if (strs.size() == 0) return "";

	string result=strs[strs.size()-1];
	strs.pop_back();

	for (int i = 0; i < strs.size(); i++)
	{
		result = getCommonPrefix(result,strs[i]);
	}

	return result;
}

int main()
{
	return 0;
}