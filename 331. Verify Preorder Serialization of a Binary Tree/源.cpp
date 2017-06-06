#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;

vector<string>splitList;

vector<string> split(string str)
{
	vector<string>result;

	if (str.empty())
		return result;

	int p = 0, q = 0;

	while (q<str.size())
	{
		while (q<str.size()&&str[q]!=',')
		{
			q++;
		}
		string tmp = str.substr(p,q-p);
		result.push_back(tmp);
		q++;
		p = q;
		
	}


	return result;
	


}

bool check(int src, int dst)
{

	if (src > dst)return true;

	if (splitList[src] == "#")
	{
		if (src == dst)
			return true;
		else
			return false;
	}

	int charNum = 0;
	int nullNum = 0;

	int p = src + 1;

	while (p <= dst&&charNum != nullNum - 1)
	{
		if (splitList[p] != "#")
		{
			charNum++;
		}
		else
			nullNum++;

		p++;
	}

 	if (charNum != nullNum - 1)
		return false;

	int q = p;
	charNum = nullNum = 0;
	while (q <= dst&&charNum != nullNum - 1)
	{
		if (splitList[q] != "#")
		{
			charNum++;
		}
		else
			nullNum++;
		q++;
	}

	if (charNum != nullNum - 1||q<=dst)
		return false;

	return check(src + 1, p-1) && check(p, dst);
}

bool isValidSerialization(string preorder)
{

	
	splitList = split(preorder);

	return check(0,splitList.size()-1);

}
bool isValidSerialization1(string preorder) 
{
	vector<string>que = split(preorder);

	stack<int>his;

	if (preorder == "#")return true;

	for (int i = 0; i < que.size(); i++)
	{
		string cur = que[i];

		if (cur != "#")
		{
			if (his.empty() && i != 0)
				return false;
			his.push(0);
		}
		else
		{
			if (his.empty())
				return false;
			his.push(2);
		}

		while (!his.empty() && his.top() == 2)
		{
			his.pop();
			if (!his.empty())
				his.top()++;
		}
	}

	return his.empty();
}


int main()
{
	string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	bool result = isValidSerialization(str);
	return 0;
}