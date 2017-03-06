#include<iostream>
#include<string.h>
#include<string>
using namespace std;


int strStr(string haystack, string needle) 
{
	int sampleLength = needle.length();
	int totalLength = haystack.length();

	if (sampleLength == 0)return 0;
	if (sampleLength > totalLength)
		return -1;

	for (int i = 0; i <=totalLength - sampleLength; i++)
	{
		string tempStr = haystack.substr(i,sampleLength);
		//if (tempStr==needle)
		if (tempStr.compare(needle)==0)
			return i;
	}
	return -1;
	
}

void main()
{
	string haystack = "a";
	string needle = "a";
	int i = strStr(haystack,needle);
}