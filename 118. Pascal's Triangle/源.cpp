#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>>result;

	if (numRows == 0)
		return result;
	if (numRows == 1)
	{
		vector<int>list(1,1);
		result.push_back(list);
		return result;
	}
	if (numRows == 2)
	{
		vector<int>list(1, 1);
		result.push_back(list);
		list.push_back(1);
		result.push_back(list);
		return result;
	}

	vector<int>list0(1,1);
	vector<int>list1(2, 1);
	result.push_back(list0);
	result.push_back(list1);

	for (int i = 2; i < numRows; i++)
	{
		vector<int>preList = result[result.size() - 1];

		vector<int>list;
		list.push_back(1);
		for (int j = 0; j < preList.size() - 1; j++)
		{
			int cur = preList[j] + preList[j + 1];
			list.push_back(cur);
		}
		list.push_back(1);
		result.push_back(list);
	}


	return result;
}

void main()
{
	generate(3);
}