#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int minDistance(string word1, string word2) 
{
	if (word1.size() == 0)return word2.size();
	if (word2.size() == 0)return word1.size();
	int m = word1.size();
	int n = word2.size();

	int**dp = new int*[m + 1];
	for (int i = 0; i <= m; i++)
	{
		dp[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i <= n; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (word1[i-1] == word2[j-1])
			{
				dp[i][j] = min(min(dp[i - 1][j - 1], 1 + dp[i - 1][j]), 1 + dp[i][j - 1]);
			}
			else
			{
				dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
			}
		}
	}
	return dp[m][n];




}

void main()
{
	string word1 = "a",word2="b";
	int result = minDistance(word1,word2);
}