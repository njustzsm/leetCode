#include<iostream>
#include<string>
#include<vector>

using namespace std;


int result=INT_MAX;
bool isPar(string s)
{
	if (s.size() == 1)return true;

	int p = 0, q = s.size() - 1;

	while (p<q)
	{
		if (s[p] != s[q])
			return false;
		p++;
		q--;
	}
	return true;

}
void dfs(string s, int curNum)
{
	if (s.size() == 0)
	{
		if (curNum < result)
		{
			result = curNum;
		}
		return;
	}
	if (curNum >= result)return;


	for (int i = 0; i < s.size(); i++)
	{
		string subStr = s.substr(0, i + 1);
		if (isPar(subStr))
		{
			
			if (i == s.size() - 1)
				dfs("", curNum);
			else
				dfs(s.substr(i + 1, s.size() - i - 1), curNum+1);

		}
	}
}


int minCut(string s) 
{
	if (s.size() <= 1||isPar(s))return 0;
	
	int m = s.size();
	bool**isPalindrome = new bool*[m];
	int*minValue = new int[m+1];
	memset(minValue,0,(m+1)*sizeof(int));
	minValue[m] = -1;
	for (int i = 0; i < m; i++)
	{
		isPalindrome[i] = new bool[m];
		memset(isPalindrome[i],false,m*sizeof(bool));
	}
	for (int i = 0; i < m; i++)
	{
		isPalindrome[i][i] = true;
	}

	for (int i = m - 1; i >= 0; i--)
	{
		minValue[i] = minValue[i + 1] + 1;
		for (int j = i+1; j < m; j++)
		{
			if (s[i] == s[j])
			{
				if (i + 1 == j||isPalindrome[i+1][j-1])
				{
					isPalindrome[i][j] = true;

					if (minValue[i]>1 + minValue[j + 1])
						minValue[i] = 1 + minValue[j + 1];
				}
			}
			
				
			
			else
			{
				isPalindrome[i][j] = false;
			}
		}
	}

	return minValue[0];



	
}





void main()
{
	string s = "leet";
	minCut(s);
}