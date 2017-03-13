#include<iostream>
#include<vector>

using namespace std;

void Ro(vector<int>& nums,int src,int dst)
{
	while (src<dst)
	{
		int temp = nums[src];
		nums[src] = nums[dst];
		nums[dst] = temp;
		src++;
		dst--;
	}
}


void rotate(vector<int>& nums, int k) 
{
	int n = nums.size();

	if (n <= 1)return;

	k = k%n;

	if (k == 0)return;

	Ro(nums,0,n-1);
	Ro(nums,0,k-1);
	Ro(nums,k,n-1);




}

void main()
{

}