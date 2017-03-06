#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval>result;
	if (intervals.size() == 0)
	{
		result.push_back(newInterval);
		return result;
	}

	bool*check = new bool[intervals.size()];
	memset(check,false,intervals.size()*sizeof(bool));

	bool isChange = false;

	for (int i = 0; i < intervals.size(); i++)
	{
		Interval cur = intervals[i];

		if (!(cur.end<newInterval.start||cur.start>newInterval.end))
		{
			check[i] = true;
			isChange = true;
		}
	}
	if (isChange)
	{
		int i = 0;
		while (!check[i])
		{
			result.push_back(intervals[i]);
			i++;
		}
		while (check[i]&&i<intervals.size())
		{
			newInterval.start = min(newInterval.start,intervals[i].start);
			newInterval.end = max(newInterval.end,intervals[i].end);
			i++;
		}
		result.push_back(newInterval);

		while (!check[i] && i<intervals.size())
		{
			result.push_back(intervals[i]);
			i++;
		}
		return result;
	}
	else
	{
		bool isPush = false;

		for (int i = 0; i < intervals.size(); i++)
		{
			if (!isPush)
			{
				if (intervals[i].start < newInterval.start)
					result.push_back(intervals[i]);
				else
				{
					i--;
					isPush = true;
					result.push_back(newInterval);
				}
			}
			else
				result.push_back(intervals[i]);
			
				
		}
		if (!isPush)
			result.push_back(newInterval);

		return result;
	}
	
}
void main()
{

}