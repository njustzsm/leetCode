#include<iostream>
#include<vector>
#include<string>

using namespace std;


int num;
vector<string>data;
vector<string>result;

void dfs(int i,string digits,string res)
{
	if (i == num)
	{
		if (res.size()!=0)
		result.push_back(res);
	}
	else
	{
		int number = digits[i] - '0';
		number -= 2;

		for (int j = 0; j < data[number].size();j++)
		{
			res +=data[number][j];
			dfs(i+1,digits,res);
			res = res.substr(0,res.size()-1);
		}
	}
}

vector<string> letterCombinations(string digits) {
	string tt = "abc";
	data.push_back(tt);
	tt = "def";
	data.push_back(tt);
	tt = "ghi";
	data.push_back(tt);
	tt = "jkl";
	data.push_back(tt);
	tt = "mno";
	data.push_back(tt);
	tt = "pqrs";
	data.push_back(tt);
	tt = "tuv";
	data.push_back(tt);
	tt = "wxyz";
	data.push_back(tt);

	num = digits.size();

	string res;

	dfs(0, digits, res);

	return result;
}

int main()
{
	vector<string>tt = letterCombinations("4");

	return 0;
}