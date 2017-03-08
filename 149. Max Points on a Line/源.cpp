#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

bool compare(Point a,Point b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}


int maxPoints(vector<Point>& points) 
{
	int m = points.size();
	if (m <= 2)return m;

	int maxResult= 2;
	map<double, int>result;

	sort(points.begin(), points.end(), compare);

	for (int i = 0; i < m; i++)
	{

		int curSameX = 0,curMax=0;
		Point curPoint = points[i];
		result.clear();
		int tt = i;	
		while (tt<m&&points[tt].x==curPoint.x&&points[tt].y==curPoint.y)
		{
			tt++;
		}


		for (int j = tt; j < m; j++)
		{
			if (curPoint.x == points[j].x)
			{
				curSameX++;
				continue;
			}

			double deltaX = points[j].x - curPoint.x;
			double deltaY = points[j].y - curPoint.y;
			long double k = deltaY/deltaX;

			if (result.count(k) == 0)
			{
				result[k] = 1;
				if (curMax < result[k])
					curMax = result[k];
			}
			else
			{
				result[k]++;
				if (curMax < result[k])
					curMax = result[k];
			}
		}

		if (curMax < curSameX)
			curMax = curSameX;

		curMax += tt - i;

		if (curMax>maxResult)
			maxResult = curMax;
	}


	
	return maxResult;



	
}

void main()
{
	
	vector<Point>points;
	Point a(0,0);
	Point b(94911151, 94911150);
	Point c(94911152, 94911151);
	points.push_back(a);
	points.push_back(b);
	points.push_back(c);
	int result = maxPoints(points);
}