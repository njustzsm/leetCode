#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

bool isDigit(string a)
{
	if (a[0] >= '0'&&a[0] <= '9')
		return true;
	return false;
}

int calculate(string s) 
{
	vector<string>heap;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		if (s[i] == '(' || s[i] == '+' || s[i] == '-'||s[i]==')')
		{
			string cur = "";
			cur += s[i];
			heap.push_back(cur);
		}

		if (s[i] >= '0'&&s[i] <= '9')
		{
			if (!heap.empty())
			{
				string head = heap[heap.size()-1];

				if (head[0] >= '0'&&head[0] <= '9')
				{
					heap.pop_back();
					head += s[i];
					heap.push_back(head);
				}
				else
				{
					string cur = "";
					cur += s[i];
					heap.push_back(cur);
				}
			}
			else
			{
				string cur = "";
				cur+= s[i];
				heap.push_back(cur);
			}
		}
	}


	stack<string>sta;

	for (int i = 0; i < heap.size(); i++)
	{
		string cur = heap[i];

		
		if (sta.empty())
		{
			sta.push(cur);
			continue;
		}

		
		if (cur == "+" || cur == "-" || cur == "(")
		{
			sta.push(cur);
			continue;
		}

		
		if (isDigit(cur))
		{
			string topStr = sta.top();
			if (topStr == "+" || topStr == "-")
			{
				string sign = sta.top();
				sta.pop();
				string number = sta.top();
				sta.pop();

				int a = atoi(&number[0]);
				int b = atoi(&cur[0]);

				if (sign[0] == '+')
				{
					a = a + b;
				}
				if (sign[0] == '-')
				{
					a = a - b;
				}

				string result = to_string(a);
				sta.push(result);
			}
			else
			{
				sta.push(cur);
				continue;
			}
		}
		if (cur == ")")
		{
			string tt = sta.top();
			int b = atoi(&tt[0]);
			sta.pop();
			sta.pop();
			if (sta.empty())
			{
				sta.push(tt);
			}
			else
			{
				string sign = sta.top();
				sta.pop();
				string temp = sta.top();
				sta.pop();
				int a = atoi(&temp[0]);

				if (sign == "+")
				{
					a = a + b;
				}
				else
				{
					a = a - b;
				}
				string result = to_string(a);
				sta.push(result);

			}
		}

	}

	string fina = sta.top();
	return atoi(&fina[0]);




}

void main()
{
	string input = "1-(5)";
	int result = calculate(input);
}