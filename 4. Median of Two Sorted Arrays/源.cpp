#include<iostream>
#include<vector>

using namespace std;


int getNum(vector<int>nums,int cur)
{
	if (nums.size() == 0)return 0;
	if (cur < nums[0])return 0;
	if (nums[nums.size() - 1] < cur)return nums.size();

	int p = 0, q = nums.size() - 1;

	while (p<q)
	{

	}

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	int m = nums1.size();
	int n = nums2.size();
	if (m + n == 0)return 0;
	if (m + n == 1)
	{
		if (nums1.size() != 0)
			return nums1[0];
		return nums2[0];
	}
	if (m + n == 2)
	{
		double t = 0;
		for (int i = 0; i < m; i++)
			t += nums1[i];
		for (int i = 0; i < n; i++)
			t += nums2[i];

		return t / 2;
	}


	
	

}

int main()
{
	vector<int>l1;
	vector<int>l2;

	l1.push_back(1);
	l1.push_back(2);
	l2.push_back(3);
	l2.push_back(4);

	double result = findMedianSortedArrays(l1,l2);
	return 0;
}