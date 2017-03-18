#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<queue>
using namespace std;

struct point
{
	int left;
	int right;
	int height;
	point(int a, int b, int c) :left(a), right(b), height(c)
	{
		
	}
};


vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
{
	int m = buildings.size();
	vector<pair<int, int>>result;

	if (m == 0)return result;

	
	
	
	priority_queue<point*>que;

	for (int i = 0; i < m; i++)
	{
		point*p = new point(buildings[i][0], buildings[i][1], buildings[i][2]);
	}

	
	

	


}
void main()
{

}