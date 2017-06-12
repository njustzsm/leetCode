#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	unordered_map<int,bool>map;

	for (int i = 0; i < nums1.size(); i++)
	{
		map[nums1[i]] = true;
	}

	unordered_map<int, bool>intersec;

	for (int i = 0; i < nums2.size(); i++)
	{
		if (map.count(nums2[i]) != 0)
		{
			intersec[nums2[i]] = true;
		}
	}

	vector<int>result;

	unordered_map<int, bool>::iterator it = intersec.begin();

	while (it != intersec.end())
	{
		result.push_back(it->first);
		it++;
	}

	return result;

}
int main()
{
	return 0;
}