#include<iostream>
#include<vector>


using namespace std;


int missingNumber(vector<int>& nums) 
{
	int n = nums.size();

	long long int sum =n*(n-1)/2,curSum=0;
	for (int i = 0; i < n; i++)
	{
		curSum += nums[i];
	}

	return sum - curSum;
	


}

void main()
{

}