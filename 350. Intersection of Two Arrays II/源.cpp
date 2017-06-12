#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int>map;

	for (int i = 0; i < nums1.size(); i++)
	{
		if (map.count(nums1[i]) == 0)
		{
			map[nums1[i]] = 0;
		}
		map[nums1[i]]++;
	}

	unordered_map<int, int>intersec;

	for (int i = 0; i < nums2.size(); i++)
	{
		if (map.count(nums2[i]) != 0)
		{
			if (intersec.count(nums2[i]) == 0)
			{
				intersec[nums2[i]]=0;
			}
			intersec[nums2[i]]++;

			map[nums2[i]]--;

			if (map[nums2[i]] == 0)
			{
				map.erase(nums2[i]);
			}
		}
	}

	vector<int>result;

	unordered_map<int, int>::iterator it = intersec.begin();

	while (it != intersec.end())
	{
		for (int i = 0; i < it->second;i++)
			result.push_back(it->first);
		it++;
	}

	return result;

}
int main()
{
	return 0;
}