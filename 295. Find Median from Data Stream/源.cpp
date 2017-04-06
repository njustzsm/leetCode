#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<queue>
using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */

	priority_queue<int>maxHeap;
	priority_queue<int,vector<int>,greater<int>>  minHeap;


	MedianFinder() 
	{

	}

	void addNum(int num) 
	{
		if (maxHeap.empty()||num<=maxHeap.top())
			maxHeap.push(num);
		else if (minHeap.empty()||num>=minHeap.top())
			minHeap.push(num);
		else
		{
			maxHeap.push(num);
		}


		if (maxHeap.size() > minHeap.size() + 1)
		{
			int tt = maxHeap.top();
			maxHeap.pop();
			minHeap.push(tt);
		}
		else if (maxHeap.size() + 1 < minHeap.size())
		{
			int tt = minHeap.top();
			minHeap.pop();
			maxHeap.push(tt);
		}

		
	}

	double findMedian()
	{
		if (minHeap.empty() && maxHeap.empty())
			return 0;
		if (minHeap.size() > maxHeap.size())
			return minHeap.top();
		else if (maxHeap.size() > minHeap.size())
			return maxHeap.top();
		else
			return (maxHeap.top()*1.0 + minHeap.top()) / 2.0;
	}
};


int main()
{
	return 0;
}