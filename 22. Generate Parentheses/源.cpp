#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;


void DFS(int left, int right, string curString,vector<string>&result,int n)
{
	if (left == n&&right == n)
	{
		result.push_back(curString);
		return;
	}

	if (left < n)
	{
		DFS(left + 1, right, curString + '(', result, n);
	}
	if (left>right)
		DFS(left, right + 1, curString + ')', result, n);

}

vector<string> generateParenthesis(int n) 
{
	vector<string>result;
	string cur = "";
	DFS(0, 0, cur, result, n);
	for (int i = 0; i < result.size(); i++)
		printf("%s\n",result[i]);

	return result;
}


void main()
{
	generateParenthesis(4);
}