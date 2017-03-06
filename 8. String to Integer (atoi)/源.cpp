#include<iostream>
#include<string>

using namespace std;


int myAtoi(string str) 
{
	if (str.size() == 0)
		return 0;

	int temp = 0;
	while (temp<str.size()&&str[temp]==' ')
	{
		temp++;
	}
	if (temp == str.size())return 0;

	str = str.substr(temp);
	
	temp = str.size() - 1;
	while (temp>=0&&str[temp]==' ')
	{
		temp--;
	}
	if (temp<0)return 0;

	str = str.substr(0,temp+1);




	int index = 0;
	bool isPositive = true;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str.size() == 1)return 0;
		else if (str[0] == '-')
			isPositive = false;

		index++;
	}

	long long int  result = 0;

	for (; index < str.size(); index++)
	{
		char cur = str[index];
		if (cur >= '0'&&cur <= '9')
		{
			int tt = cur - '0';
			result = result * 10 + tt;

			if (result - 1>INT_MAX)
				break;
		}
		else
			break;
	}

	if (isPositive)
	{
		if (result <= INT_MAX)
			return result;
		return INT_MAX;
	}
	else
	{
		if (result - 1 <= INT_MAX)
		{
			return -1 * result;
		}
		return INT_MIN;
	}

}

void main()
{
	string str = "+1";
	myAtoi(str);
}