#include<iostream>
#include<vector>

using namespace std;

int merge(vector<long long int>&sums,int start,int end,long long int lower,long long int upper)
{
	if (start > end)return 0;

	if (start == end)
	{
		if (sums[start]>= lower&&sums[start] <= upper)
			return 1;
		else
			return 0;
	}


	int mid = (start + end) / 2;

	int count = merge(sums, start, mid,lower,upper) + merge(sums, mid + 1, end,lower,upper);

	for (int i = start; i <= mid; i++)
	{

		int src = mid + 1;
		int dst = end;

		int j=-1, k=-1;

		while (src<=dst)
		{
			int curMid = (src + dst) / 2;
			if (sums[curMid] - sums[i] > lower)
			{
				if (curMid == mid + 1 || sums[curMid - 1] - sums[i] < lower)
				{
					j = curMid;
					break;
				}
				else
					dst = curMid - 1;
			}
			else if (sums[curMid] - sums[i] < lower)
				src = curMid + 1;
			else
			{
				if (curMid == mid + 1 || sums[curMid - 1] - sums[i] < lower)
				{
					j = curMid;
					break;
				}
				else
					dst = curMid - 1;
			}
		}

		src = mid + 1;
		dst = end;
		while (src<=dst)
		{
			int curMid = (src + dst) / 2;
			if (sums[curMid] - sums[i] > upper)
			{
				dst = curMid - 1;
			}
			else if (sums[curMid] - sums[i] < upper)
			{
				if (curMid == end || sums[curMid + 1] - sums[i]>upper)
				{
					k = curMid;
					break;
				}
				else
				{
					src = curMid + 1;
				}
			}
			else
			{
				if (curMid == end || sums[curMid + 1] - sums[i]>upper)
				{
					k = curMid;
					break;
				}
				else
				{
					src = curMid + 1;
				}
			}
		}

		if (j >= 0 && k >= 0 && j <= k)
			count += k - j + 1;
	}

	long long int*temp = new long long int[end - start + 1];
	int p = start, q = mid + 1;
	int index = 0;

	while (p<=mid&&q<=end)
	{
		if (sums[p] < sums[q])
		{
			temp[index++] = sums[p++];
		}
		else
			temp[index++] = sums[q++];
	}
	while (p <= mid)
	{
		temp[index++] = sums[p++];
	}
	while (q<=end)
	{
		temp[index++] = sums[q++];
	}



	for (int i = 0; i < index; i++)
	{
		sums[i + start] = temp[i];
	}

	return count;

}

int countRangeSum(vector<int>& nums, int lower, int upper) 
{
	int n = nums.size();
	vector<long long int>sum(n,0);
	

	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0)
			sum[i] = nums[i];
		else
			sum[i] = sum[i - 1] + nums[i];
	}
	
	return merge(sum,0,n-1,lower,upper);
}

int main()
{
	vector<int>nums{ -1, -3, 1, 1, 0, 0 };
	int lower = -2, upper = 1;
	int result = countRangeSum(nums,lower,upper);
	return 0;
}
