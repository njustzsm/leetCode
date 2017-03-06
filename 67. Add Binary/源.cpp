#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string addBinary(string a, string b) 
{
	string result = "";
	int minLength = min(a.size(), b.size());

	int p = a.size() - 1, q = b.size() - 1, add = 0;

	while (p >= 0 && q >= 0)
	{
		int inta = a[p] - '0';
		int intb = b[q] - '0';
		int cur = inta + intb + add;
		add = cur / 2;
		char res = '0' + (cur % 2);
		result = res + result;
		p--;
		q--;
	}
	while (p >= 0)
	{
		int inta = a[p] - '0';
		int cur = inta + add;
		add = cur / 2;
		char res = '0' + (cur % 2);
		result = res + result;
		p--;
	}
	while (q >= 0)
	{
		int intb = b[q] - '0';
		int cur = intb + add;
		add = cur / 2;
		char res = '0' + (cur % 2);
		result = res + result;
		q--;
	}
	if (add != 0)
	{
		char res = '0' + add;
		result = res + result;
	}
	return result;

}

void main()
{

}