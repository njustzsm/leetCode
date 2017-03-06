#include<iostream>
#include<vector>

using namespace std;

//Ã∞¿∑À„∑®
int jump(vector<int>& nums) 
{
	if (nums.size() <= 1)return 0;

	int countN = 1;
	int totaldst = nums.size() - 1;
	int src = 0, maxdst = src + nums[src];

	while (maxdst<totaldst)
	{
		countN++;
		int curLength = maxdst;
		for (int i = src; i <= maxdst; i++)
		{
			if (i + nums[i] > curLength)
			{
				curLength = i + nums[i];

			}
		}
		src = maxdst + 1;
		maxdst = curLength;
	}
	return countN;
}

void main()
{

}