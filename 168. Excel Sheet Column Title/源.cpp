#include<iostream>
#include<string>

using namespace std;


string convertToTitle(int n) 
{
	string result = "";

	while (n != 0)
	{
		int res = n % 26;
		if (res == 0)res = 26;
		char cur = 'A' + res - 1;
		result = cur+result;
		n = (n - res) / 26;
	}

	return result;
	

}

void main()
{

}