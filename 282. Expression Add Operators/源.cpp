#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


int myTarget;
vector<string>result;
int calculation(string str)
{
	stack<int>number;
	stack<char>signal;

	for (int i = 0; i < str.size(); i++)
	{
		char a = str[i];

		if (a == '+' || a == '-')
		{
			if (signal.empty())
			{
				signal.push(a);
			}
			else
			{
				while (!signal.empty())
				{
					int b = number.top();
					number.pop();
					int a = number.top();
					number.pop();

					char cur = signal.top();
					signal.pop();

					switch (cur)
					{
					case '+':
						number.push(a + b);
						break;
					case '-':
						number.push(a - b);
						break;
					case '*':
						number.push(a * b);
						break;
					}
				}
				signal.push(a);
			}
		}
		else if (a == '*')
			signal.push(a);
		else
		{
			int cur = a - '0';
			if (i != 0 && str[i - 1] >= '0'&&str[i - 1] <= '9')
			{
				int temp = number.top();


				//要注意012之类的不合法的数字的出现
				if (temp == 0)
					return -1;

				number.pop();
				number.push(temp * 10 + cur);
			}
			else
				number.push(cur);
		}

	}
	while (!signal.empty())
	{
		int b = number.top();
		number.pop();
		int a = number.top();
		number.pop();

		char cur = signal.top();
		signal.pop();

		switch (cur)
		{
		case '+':
			number.push(a + b);
			break;
		case '-':
			number.push(a - b);
			break;
		case '*':
			number.push(a * b);
			break;
		}
	}

	return number.top();
}

void dfs(int cur,string curStr)
{
	if (cur == curStr.size() - 1)
	{
		if (myTarget == calculation(curStr))
		{
			result.push_back(curStr);
		}
		return;
	}

	for (int i = 0; i <= 3; i++)
	{
		

		switch (i)
		{
		case 0:
			dfs(cur+1,curStr);
			break;
		case 1:
			dfs(cur+2,curStr.substr(0,cur+1)+'+'+curStr.substr(cur+1));
			break;
		case 2:
			dfs(cur + 2, curStr.substr(0, cur + 1) + '-' + curStr.substr(cur + 1));
			break;
		case 3:
			dfs(cur + 2, curStr.substr(0, cur + 1) + '*' + curStr.substr(cur + 1));
			break;
		}
	}


}
vector<string> addOperators1(string num, int target) 
{
	//注意，由于字符串表示的数可能超过int的表示范围，所以转化为整数类型时，不能用atoi跟atol
	long long int tt = atoll(num.c_str());   


	if (num == ""||tt>INT_MAX||tt<INT_MIN)return result;

	

	
	if (tt== target&&target!=0)
	{
		result.push_back(num);
		return result;
	}

	myTarget = target;

	dfs(0,num);

	return result;

}


void helper(string num,int target,string temp,long curNum,long preNum)
{
	if (num.size() == 0 && curNum == target)
	{
		result.push_back(temp);
		return;
	}

	for (int i = 1; i <=num.size(); i++)
	{
		string curStr = num.substr(0,i);
		
		if (curStr[0] == '0'&&curStr.size() != 1)
			break;

		long curda = atoll(curStr.c_str());

		if (temp != "")
		{
			helper(num.substr(i), target, temp + '*' + curStr, (curNum - preNum) + curda*preNum, curda*preNum);

			helper(num.substr(i), target, temp + '+' + curStr, curNum + curda, curda);

			helper(num.substr(i), target, temp + '-' + curStr, curNum - curda, -curda);
		}
		else
			helper(num.substr(i), target, curStr, curda, curda);
	}


}

vector<string> addOperators(string num, int target)
{
	helper(num, target, "", 0, 0);
	return result;
}

int main()
{
	string num = "2147483648";
	int target = INT_MIN;

	vector<string>tt = addOperators(num,target);


	return 0;
}