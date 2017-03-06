#include<iostream>
#include<string>
#include<vector>
using namespace std;



string tranf(string str)
{
	string result="";
	int length = str.size();

	int p = 0;
	int countn = 0;
	while (p<length)
	{
		int q = p;
		
		while (q<length&&str[q]==str[p])
		{
			q++;
		}
		//result +='0'+q-p;
		result += to_string(q - p);
		result += str[p];
		p = q;
	}
	return result;
}


string countAndSay(int n) 
{
	int num = 1;
	string src = "1";

	while(num<n)
	{
		src = tranf(src);
		num++;
	}
	return src;
}
void main()
{
	string result = countAndSay(2);
}