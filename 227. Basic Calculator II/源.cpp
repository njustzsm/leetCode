#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int calculate(string s) 
{
	stack<int>numberStack;
	stack<char>signStack;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')continue;
		if (s[i] == '*' || s[i] == '/')
		{
			signStack.push(s[i]);
			continue;
		}

		if (s[i] >= '0'&&s[i] <= '9')
		{
			int dst = i+1;
			while (s[dst]>='0'&&s[dst]<='9')
			{
				dst++;
			}

			string curNum = s.substr(i,dst-i);
			int tt = atoi(&curNum[0]);
			numberStack.push(tt);
			i = dst-1;

			if (!signStack.empty() && (signStack.top() == '*' || signStack.top() == '/'))
			{
				char curSignal = signStack.top();
				signStack.pop();
				int b = numberStack.top(); numberStack.pop();
				int a = numberStack.top(); numberStack.pop();
				if (curSignal == '*')a = a*b;
				else a = a / b;
				numberStack.push(a);

			}
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			if (signStack.empty())
			{
				signStack.push(s[i]);
			}
			else
			{
					char signal = signStack.top();
					signStack.pop();
					signStack.push(s[i]);
					int b = numberStack.top(); numberStack.pop();
					int a = numberStack.top(); numberStack.pop();

					if (signal == '+')
						a += b;
					else
						a -= b;
					numberStack.push(a);
			}
		}
	}

	if (signStack.empty())
		return numberStack.top();
	else
	{
		char signal = signStack.top();
		int b = numberStack.top(); numberStack.pop();
		int a = numberStack.top(); numberStack.pop();

		if (signal == '+')
			return a + b;
		return a - b;

	}



}

void main()
{
	string data = "0";
	int result = calculate(data);
}