#include<iostream>
#include<vector>

using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int p1 = m - 1, p2 = m + n - 1;
	while (p1>=0)
	{
		nums1[p2--] = nums1[p1--];
	}

	 p1 =n;
	 p2 = 0;
	int cur = 0;

	while (p1<n+m&&p2<n)
	{
		if (nums1[p1] < nums2[p2])
		{
			nums1[cur++] = nums1[p1++];
		}
		else
		{
			nums1[cur++] = nums2[p2++];
		}
	}
		while (p1<n+m)
		{
			nums1[cur++] = nums1[p1++];
		}
		
		while (p2<n)
		{
			nums1[cur++] = nums2[p2++];
		}
	





}

void main()
{
	vector<int>nums1(2, 0);
	nums1[0] = 1;
	vector<int>nums2(1, 2);
	//for (int i = 1; i <= 5; i++)
		//nums2[i - 1] = i;
	int m = 1,n=1;

	merge(nums1,m,nums2,n);

}