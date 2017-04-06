#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stack>
using namespace std;

bool*check;
set<string>mySet;
string input;
void dfs(int cur,vector<int>stack)
{
	if (cur == stack.size())
	{
		string curResult = "";
		for (int i = 0; i < input.size(); i++)
		{
			if (!check[i])
			{
				curResult += input[i];
			}
		}
		mySet.insert(curResult);
		return;
	}
	int index = stack[cur];

	if (input[index] == ')')
	{
		for (int i = 0; i <= index; i++)
		{
			if (!check[i] && input[i] == ')')
			{
				

				check[i] = true;
				dfs(cur+1,stack);
				check[i] = false;
			}
		}
	}
	else
	{
		for (int i = index; i < input.size(); i++)
		{
			if (!check[i] && input[i] == '(')
			{
				
				check[i] = true;
				dfs(cur+1,stack);
				check[i] = false;
			}
		}
	}

}

vector<string> removeInvalidParentheses(string s) 
{
	vector<string>result;
	if (s.size() == 0)
	{
		string tt = "";
		result.push_back(tt);
		return result;
	}

	input = s;
	vector<int>myStack;


	for (int i = 0; i < s.size(); i++)
	{
		char cur = s[i];

		if (cur != '('&&cur != ')')
			continue;

		if (myStack.empty() || cur == '(')
		{
			myStack.push_back(i);
		}
		else
		{
			if (s[myStack[myStack.size()-1]] == '(')
				myStack.pop_back();
			else
				myStack.push_back(i);
		}
	}

	if (myStack.size() == 0)
	{
		result.push_back(s);
		return result;
	}


	check = new bool[s.size()];
	memset(check, false, s.size()*sizeof(bool));
	
	dfs(0,myStack);

	set<string>::iterator it = mySet.begin();
	for (; it != mySet.end(); it++)
	{
		result.push_back(*it);
	}
	return result;
}

int main()
{
	string s = "()())()";
	vector<string>tt = removeInvalidParentheses(s);
	return 0;
}