#include<iostream>
#include<vector>
#include<queue>


using namespace std;




vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{

	int takeNum = 0;
	vector<int>result;

	bool*check = new bool[numCourses];
	memset(check, false, numCourses*sizeof(bool));

	int*pointIn = new int[numCourses];
	memset(pointIn, 0, numCourses*sizeof(int));


	vector<int>*pointOut = new vector<int>[numCourses];


	for (int i = 0; i < prerequisites.size(); i++)
	{
		pair<int, int>cur = prerequisites[i];

		pointIn[cur.first]++;
		pointOut[cur.second].push_back(cur.first);

	}

	for (int i = 0; i < numCourses; i++)
	{
		if (pointIn[i] == 0 && !check[i])
		{
			check[i] = true;
			takeNum++;

			result.push_back(i);
			queue<int>que;

			que.push(i);

			while (!que.empty())
			{
				int cur = que.front();
				que.pop();

				for (int j = 0; j < pointOut[cur].size(); j++)
				{
					pointIn[pointOut[cur][j]]--;

					if (!check[pointOut[cur][j]] && pointIn[pointOut[cur][j]] <= 0)
					{
						result.push_back(pointOut[cur][j]);
						takeNum++;
						check[pointOut[cur][j]] = true;
						que.push(pointOut[cur][j]);
					}
				}
			}

			if (takeNum == numCourses)
				return result;
		}
	}
	
	result.clear();
	return result;



}

void main()
{
	vector<pair<int, int>> prerequisites;
	int n = 1;
	//bool result = canFinish(n, prerequisites);
}