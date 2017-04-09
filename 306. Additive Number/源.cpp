#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<long long int>curDigit;
bool isSucceess = false;
void dfs(string str)
{
	if (isSucceess)return;

	if (str == "")
	{
		isSucceess = true;
		return;
	}

	if (str[0] == '0')
	{
		if (curDigit.size() < 2)
		{
			curDigit.push_back(0);
			dfs(str.substr(1));
			curDigit.pop_back();
		}
		else
		{
			long long int a = curDigit[curDigit.size()-1];
			long long int b = curDigit[curDigit.size()-2];
			if (a + b != 0)
			{
				return;
			}
			else
			{
				curDigit.push_back(0);
				dfs(str.substr(1));
				curDigit.pop_back();
			}
		}
	}
	else
	{
		for (int i = 1; i <= str.size() - 2 + curDigit.size(); i++)
		{
			if (isSucceess)return;
			string cur = str.substr(0,i);
			long long int num = atoll(cur.c_str());
			if (curDigit.size() < 2)
			{
				curDigit.push_back(num);
				dfs(str.substr(i));
				curDigit.pop_back();
			}
			else
			{
				long long int a = curDigit[curDigit.size() - 1];
				long long int b = curDigit[curDigit.size() - 2];
				if (a + b > num)
				{
					continue;
				}
				else if (a+b==num)
				{
					curDigit.push_back(num);
					dfs(str.substr(i));
					curDigit.pop_back();
				}
				else
				{
					break;
				}
			}
		}
	}
	



}


bool isAdditiveNumber(string num) 
{
	if (num.size() < 3)return false;
	dfs(num);
	return isSucceess;
}

int main()
{

	return 0;
}