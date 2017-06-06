#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;


int num;
vector<string>result;
map<string, set<string>>src2dst;
map<pair<string, string>, int>ticketCount;


void dfs(vector<string>&curPath)
{
	if (!result.empty())
		return;

	if (curPath.size() == num + 1)
	{
		result = curPath;
		return;
	}

	string src = curPath[curPath.size()-1];

	set<string>::iterator it = src2dst[src].begin();

	while (result.empty()&&it!=src2dst[src].end())
	{
		string next = *it;
		pair<string, string>tt(src,next);
		if (ticketCount[tt] == 0)
		{
			it++;
			continue;
		}
			

		ticketCount[tt]--;
		curPath.push_back(next);
		dfs(curPath);
		curPath.pop_back();

		ticketCount[tt]++;

		it++;
	}


}

vector<string> findItinerary(vector<pair<string, string>> tickets) 
{
	num = tickets.size();
	for (int i = 0; i < num; i++)
	{
		pair<string, string>tt = tickets[i];
		if (src2dst.count(tt.first) == 0)
		{
			set<string> tmp;
			tmp.insert(tt.second);
			src2dst[tt.first] = tmp;
		}
		else
			src2dst[tt.first].insert(tt.second);

		if (ticketCount.count(tt) == 0)
		{
			ticketCount[tt] = 1;
		}
		else
			ticketCount[tt]++;
	}

	string tt = "JFK";
	vector<string>path;
	path.push_back(tt);
	
	dfs(path);


	return result;
}

int main()
{
	string data[][2] = { { "JFK", "BZE" }, { "BNE", "MHH" }, { "MHH", "BAK" }, { "ADL", "VIE" }, { "COO", "TCB" },
	{"LST", "BNE" }, { "JFK", "TCB" }, { "VIE", "GGT" }, { "ADL", "JFK" }, { "TCB", "AXA" }, { "BZE", "BNE" },
	{ "TCB", "PER" }, { "BAK", "COO" }, { "GGT", "ADL" }, { "AXA", "BIM" }, { "PER", "ADL" }, { "BIM", "LST" }, { "BNE", "BRU" } };

	int leng = 18;
	vector<pair<string, string>>input;
	for (int i = 0; i < leng; i++)
	{
		pair<string, string>tmp(data[i][0],data[i][1]);
		input.push_back(tmp);
	}
	findItinerary(input);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}