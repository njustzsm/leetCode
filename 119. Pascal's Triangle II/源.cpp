#include<iostream>
#include<vector>
using namespace std;


vector<int> getRow(int rowIndex) 
{

	if (rowIndex ==0 || rowIndex == 1)
	{
		return vector<int>(rowIndex+1,1);
	}

	vector<int>list0, list1;
	list0.push_back(1); list0.push_back(1);

	for (int i = 1; i < rowIndex; i++)
	{
		if (list0.size() == 0)
		{
			list0.push_back(1);
			for (int j = 0; j < list1.size() - 1; j++)
			{
				int cur = list1[j] + list1[j + 1];
				list0.push_back(cur);
			}
			list0.push_back(1);
			list1.clear();
		}
		else
		{
			list1.push_back(1);
			for (int j = 0; j < list0.size() - 1; j++)
			{
				int cur = list0[j] + list0[j + 1];
				list1.push_back(cur);
			}
			list1.push_back(1);
			list0.clear();
		}
	}

	if (list0.size() == 0)
		return list1;
	return list0;


}

void main()
{

}