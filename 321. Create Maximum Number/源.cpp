#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<int> maxArray(vector<int>&nums, int k)
{
	vector<int>result;

	if (nums.size() < k)return result;

	for (int i = 0; i < nums.size(); i++)
	{
		while (!result.empty()&&nums[i]>result[result.size()-1]&&result.size()-1+nums.size()-i>=k)
		{
			result.pop_back();
		}
		result.push_back(nums[i]);
	}

	while (result.size()>k)
	{
		result.pop_back();
	}
	return result;

}

bool compare(vector<int>v1,int p1, vector<int>v2,int p2)
{
	/*while (p1<v1.size()&&p2<v2.size()&&v1[p1]==v2[p2])
	{
		p1++;
		p2++;
	}
	
	if (p1 < v1.size() && p2 < v2.size())
	{
		return v1[p1]>v2[p2];
	}

	return  true;*/
	
	
	while (p1 < v1.size() && p2 < v2.size() && v1[p1] == v2[p2]){
		p1++;
		p2++;
	}
	//如果v2比较短，并且前面的位数相同，那么比较长的数算比较大
	return p2== v2.size() || (p1<v1.size() &&v1[p1] > v2[p2]);

}

vector<int> merge(vector<int>nums1,vector<int>nums2)
{
	vector<int>result;
	int p1 = 0, p2 = 0;


	while (p1 < nums1.size() && p2<nums2.size())
	{
		if (nums1[p1]>nums2[p2])
		{
			result.push_back(nums1[p1++]);
		}
		else if (nums1[p1]<nums2[p2])
			result.push_back(nums2[p2++]);
		else
		{
			if (compare(nums1, p1, nums2, p2))
				result.push_back(nums1[p1++]);
			else
				result.push_back(nums2[p2++]);
		}
	}
	
	if (p1 < nums1.size())
	{
		result.insert(result.end(),nums1.begin()+p1,nums1.end());
	}
	else
	{
		result.insert(result.end(), nums2.begin() + p2, nums2.end());
	}
	return result;

}




vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
{
	int n1 = nums1.size();
	int n2 = nums2.size();


	vector<int>result;

	for (int i = 0; i <=k; i++)
	{
		if (i>n1 || k - i > n2)
			continue;
		vector<int>v1 = maxArray(nums1,i);
		vector<int>v2 = maxArray(nums2,k-i);

		vector<int>cur = merge(v1,v2);
		if (result.size() == 0 || compare(cur,0,result,0))
		{
			result = cur;
		}
	}
	return result;
}

int main()
{
	vector<int>nums1{ 3, 3, 3, 2, 3, 7, 3, 8, 6, 0, 5, 0, 7, 8, 9, 2, 9, 6, 6, 9, 9, 7, 9, 7, 6, 1, 7, 2, 7, 5, 5, 1 };

	vector<int>nums2{5, 6, 4, 9, 6, 9, 2, 2, 7, 5, 4, 3
		, 0, 0, 1, 7, 1, 8, 1, 5, 2, 5, 7, 0, 4, 3, 8, 7, 3, 8, 5, 3, 8, 3, 4, 0, 2, 3, 8, 
		2, 7, 1, 2, 3, 8, 7, 6, 7, 1, 1, 3, 9, 0, 5, 2, 8, 2, 8, 7, 5, 0, 8, 0, 7, 2, 8, 5, 6, 5
		, 9, 5, 1, 5, 2, 6, 2, 4, 9, 9, 7, 6, 5, 7, 9, 2, 8, 8, 3, 5, 9, 5, 1, 8, 8, 4, 6, 6, 3, 8, 4, 6, 6
		, 1, 3, 4, 1, 6, 7, 0, 8, 0, 3, 3, 1, 8, 2, 2, 4, 5, 7, 3, 7, 7, 4, 3, 7, 3, 0, 7, 3, 0, 9, 7, 6, 0, 3, 0, 3
		, 1, 5, 1, 4, 5, 2, 7, 6, 2, 4, 2, 9, 5, 5, 9, 8, 4, 2, 3, 6, 1, 9};

	vector<int>result = maxNumber(nums1, nums2, 160);
	return 0;
}