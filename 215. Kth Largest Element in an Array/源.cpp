#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b)
{
	return a > b;
}

int findKthLargest(vector<int>& nums, int k)
{
	vector<int>heap(nums.begin(),nums.begin()+k);
	make_heap(heap.begin(),heap.end(),compare);

	for (int i = k; i < nums.size(); i++)
	{
		if (nums[i]>heap[0])
		{
			heap[0] = nums[i];
			make_heap(heap.begin(), heap.end(), compare);
		}
	}
	return heap[0];
}
void main()
{

}