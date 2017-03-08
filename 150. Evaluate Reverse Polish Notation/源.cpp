#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;


int evalRPN(vector<string>& tokens) 
{
	stack<int>Stack;

	for (int i = 0; i < tokens.size(); i++)
	{
		string cur = tokens[i];

		if (cur == "+")
		{
			int num2 = Stack.top();
			Stack.pop();
			int num1 = Stack.top();
			Stack.pop();
			num1 += num2;
			Stack.push(num1);

		}
		else if (cur == "-")
		{
			int num2 = Stack.top();
			Stack.pop();
			int num1 = Stack.top();
			Stack.pop();
			num1 -= num2;
			Stack.push(num1);
		}
		else if (cur == "*")
		{
			int num2 = Stack.top();
			Stack.pop();
			int num1 = Stack.top();
			Stack.pop();
			num1 *= num2;
			Stack.push(num1);
		}
		else if (cur == "/")
		{
			int num2 = Stack.top();
			Stack.pop();
			int num1 = Stack.top();
			Stack.pop();
			num1 /= num2;
			Stack.push(num1);
		}
		else
		{
			int num = atoi(&cur[0]);
			Stack.push(num);
		}

	}

	return Stack.top();


}

void main()
{

}