#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;


bool isPalindrome(string str)
{
	int num = str.size();
	if (num <= 1)return true;

	int p = 0, q = num - 1;

	while (p<q)
	{
		if (str[p] != str[q])
			return false;
		p++;
		q--;
	}
	return true;

}

bool isP(string &s, int left, int right) {
	// check if s[left::right] is a palindrome
	while (left<right)
	if (s[left++] != s[right--]) return false;
	return true;
}

//别人的做法
vector<vector<int>> palindromePairs0(vector<string>& words) 
{
	unordered_map<string,int> map0;
	set<int> wLen;
	int it, len = words.size(), it2, sL, lL;
	vector<vector<int>> res;
	for (it = 0; it < len; ++it) {
		// build map and the length set
		map0[words[it]] = it;
		wLen.insert(words[it].size());
	}

	for (it = 0; it < len; ++it) 
	{ // for each string
		string temp = words[it];
		lL = temp.size();
		std::reverse(temp.begin(), temp.end()); // reverse it, step a)
		if (map0.count(temp) && map0[temp] != it)
			res.push_back(vector<int>({ it, map0[temp] })); //step b)


		auto itC = wLen.find(words[it].size());
		for (auto itL = wLen.begin(); itL != itC; ++itL) { // for each possible shorter length
			sL = *itL;
			if (isP(temp, 0, lL - sL - 1) && map0.count(temp.substr(lL - sL)))
				res.push_back(vector<int>({ it, map0[temp.substr(lL - sL)] })); //step c1)
			if (isP(temp, sL, lL - 1) && map0.count(temp.substr(0, sL)))
				res.push_back(vector<int>({ map0[temp.substr(0, sL)], it })); //step c2)                       
		}
	}
	return res;
}

vector<vector<int>> palindromePairs(vector<string>& words) 
{
	map<char, vector<string>>beginList;
	map<char, vector<string>>endList;
	map<string, int>indexList;

	bool haveEmpty = false;


	for (int i = 0; i < words.size(); i++)
	{
		string cur = words[i];
		indexList[cur] = i;

		if (cur == "")
		{
			haveEmpty = true;
			continue;
		}


		char begin = cur[0];
		char end = cur[cur.size() - 1];

		if (beginList.count(begin) == 0)
		{
			vector<string>tt(1,cur);
			beginList[begin] = tt;
		}
		else
		{
			beginList[begin].push_back(cur);
		}

		if (endList.count(end) == 0)
		{
			vector<string>tt(1, cur);
			endList[end] = tt;
		}
		else
		{
			endList[end].push_back(cur);
		}
	}

	vector<vector<int>>result;

	
	for (int i = 0; i < 26; i++)
	{
		char cur = 'a' + i;

		if (beginList.count(cur) == 0||endList.count(cur)==0)
			continue;

		vector<string> curBegin = beginList[cur];
		vector<string>curEnd = endList[cur];

		for (int j = 0; j < curBegin.size(); j++)
		{
			for (int k = 0; k < curEnd.size(); k++)
			{
				if (isPalindrome(curBegin[j] + curEnd[k]))
				{
					vector<int>tt;
					string s1 = curBegin[j];
					string s2 = curEnd[k];

					if (s1 == s2)
						continue;

					tt.push_back(indexList[s1]);
					tt.push_back(indexList[s2]);
					result.push_back(tt);
				}
			}
		}
	}

	if (haveEmpty)
	{
		int emptyIndex = indexList[""];

		for (int i = 0; i < words.size();i++)
		{
			string cur = words[i];
			if (cur == "")
				continue;
			if (isPalindrome(cur))
			{
				vector<int>tt;
				tt.push_back(emptyIndex);
				tt.push_back(i);
				result.push_back(tt);

				tt[0] = i;
				tt[1] = emptyIndex;
				result.push_back(tt);
			}
		}
	}



	return result;


}

int main()
{
	return 0;
}