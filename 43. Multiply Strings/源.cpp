#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string multi(string num,int k)
{
	string result = "";
	int add = 0;
	for (int i = num.size() - 1; i >= 0; i--)
	{
		int cur = (num[i] - '0')*k+add;
		add = cur / 10;
		char a = ((cur % 10) + '0');
		result = a+result;
	}
	if (add != 0)
	{
		char a = add + '0';
		result = a + result;
	}
	return result;
}

string add(string a,string b)
{
	string result = "";
	

	
	int odd = 0;
	int p = a.size() - 1, q = b.size() - 1;

	while (p>=0&&q>=0)
	{
		int cur = (a[p] - '0') + (b[q]-'0')+odd;
		odd = cur / 10;
		char a = (cur % 10) + '0';
		result = a + result;

		p--;
		q--;
	}

	while (p>=0)
	{
		int cur = (a[p] - '0') + odd;
		odd = cur / 10;
		char a = (cur % 10) + '0';
		result = a + result;
		p--;
	}
	
	while (q>=0)
	{
		int cur = (b[q] - '0') + odd;
		odd = cur / 10;
		char a = (cur % 10) + '0';
		result = a + result;
		q--;
	}
	
	if (odd != 0)
	{
		char a = odd + '0';
		result = a + result;
	}

	return result;

}

string multiply(string num1, string num2) 
{
	if (num1 == "0" || num2 == "0")return "0";
	string result = "";


	for (int i =0; i <num2.size(); i++)
	{
		int cur = num2[i] - '0';

		string curS = multi(num1,cur);

		if (result == "")
			result = curS;
		else
		{
			result += '0';
			result = add(result,curS);
		}
	}

	return result;
}

void main()
{
	string a = "123";
	string b = "456";

	string result = multiply(a,b);
}