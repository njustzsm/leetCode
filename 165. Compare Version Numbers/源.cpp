#include<iostream>
#include<string>
#include<queue>
using namespace std;


queue<int> splitString(string a)
{
	queue<int>result;

	while (!a.empty())
	{
		bool check = false;
		for (int i=0; i < a.size(); i++)
		{
			if (a[i] == '.')
			{
				string t = a.substr(0,i);
				a = a.substr(i + 1);
				int tt = atoi(&t[0]);
				result.push(tt);
				check = true;
				break;
			}
		}

		if (!check)
		{
			int t = atoi(&a[0]);
			result.push(t);
			return result;
		}

	}
}

int compareVersion(string version1, string version2) 
{
	queue<int>q1 = splitString(version1);
	queue<int>q2 = splitString(version2);

	while (!q1.empty()&&!q2.empty())
	{
		int cur1 = q1.front();
		q1.pop();
		int cur2 = q2.front();
		q2.pop();

		if (cur1 > cur2)return 1;
		if (cur1 < cur2)return -1;
	}

	while (!q1.empty())
	{
		int cur = q1.front();
		q1.pop();
		if (cur != 0)return 1;
	}

	while (!q2.empty())
	{
		int cur = q2.front();
		q2.pop();
		if (cur > 0)
			return -1;
	}


	

	return 0;
	



}


void main()
{

}