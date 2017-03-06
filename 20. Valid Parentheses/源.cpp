#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isValid(string s) 
{
	int num = s.size();

	vector<char>stack;

	for (int i = 0; i < num; i++)
	{
		char cur = s[i];

		if (stack.size() == 0)
			stack.push_back(cur);
		else
		{
			int curNum = stack.size()-1;
			if ((stack[curNum] == '('&&cur == ')') || (stack[curNum] == '['&&cur == ']') || (stack[curNum] == '{'&&cur == '}'))
				stack.pop_back();
			else
				stack.push_back(cur);
		}
	}

	if (stack.size() == 0)
		return true;
	return false;
}

void main()
{

}