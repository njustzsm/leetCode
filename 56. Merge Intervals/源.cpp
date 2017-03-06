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

bool compare(Interval a, Interval b)
{
	if (a.start < b.start)return true;
	return false;
}

vector<Interval> merge(vector<Interval>& intervals) 
{
	if (intervals.size() <= 1)return intervals;

	sort(intervals.begin(), intervals.end(), compare);

	int p = 0;
	vector<Interval> result;
	Interval cur=intervals[0];
	while (p<intervals.size())
	{
			if (cur.end >= intervals[p].start&&cur.end < intervals[p].end)
			{
				cur.end = intervals[p].end;
			}
			else if (cur.end < intervals[p].start)
			{
				result.push_back(cur);
				cur = intervals[p];
			}
		p++;
	}
	result.push_back(cur);
	return result;
}
void main()
{

}