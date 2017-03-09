#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


int maximumGap(vector<int>& nums) 
{
	int n = nums.size();

	if (n < 2)return 0;

	int minAll = INT_MAX, maxAll = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (nums[i]>maxAll)
			maxAll = nums[i];
		if (nums[i] < minAll)
			minAll = nums[i];
	}

	if (maxAll == minAll)return 0;

	double gap = ((double)(maxAll - minAll)) / (n - 1);


	vector<int> minV(n-1,INT_MAX);
	vector<int> maxV(n-1,INT_MIN);



	for (int i = 0; i < n; i++)
	{
		if (nums[i] != maxAll)
		{
			int index = (nums[i] - minAll) / gap;
			minV[index] = min(minV[index],nums[i]);
			maxV[index] = max(maxV[index],nums[i]);
		}
	}


	int result = INT_MIN;

	int p = 0, q = 0;

	while (minV[p]==INT_MAX)
	{
		p++;
	}

	q = p + 1;


	while (q<n - 1)
	{
		while (q<n-1&&minV[q]==INT_MAX)
		{
			q++;
		}

		if (q < n - 1)
		{
			result = max(result,minV[q]-maxV[p]);
			p = q;
			q++;
		}
	}
	


	result = max(result,maxAll-maxV[p]);
	
	return result;
	
}

void main()
{

}