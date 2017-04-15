#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
int maxProduct(vector<string>& words) {
	int n = words.size();

	bool**check = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		check[i] = new bool[n];
		memset(check[i], true, n*sizeof(bool));
	}

	set<int>countLetter[26];


	for (int i = 0; i < words.size(); i++)
	{
		string s = words[i];
		for (int j = 0; j < s.size(); j++)
		{
			countLetter[s[j] - 'a'].insert(i);
		}
	}

	for (int i = 0; i < 26; i++)
	{
		set<int>cur = countLetter[i];
		if (cur.size() == n)return 0;

		for (set<int>::iterator it = cur.begin(); it != cur.end(); it++)
		{
			set<int>::iterator it1 = ++it;
			it--;
			for (; it1 != cur.end(); it1++)
			{
				check[*it][*it1] = false;
			}
		}
	}

	unsigned int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (check[i][j])
			{
				if (result<words[i].size()*words[j].size())
					result = words[i].size()*words[j].size();
			}
		}
	}






	return result;
}


int main()
{
	vector<string>data{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	int result = maxProduct(data);
	cout << result << endl;
	return 0;
}