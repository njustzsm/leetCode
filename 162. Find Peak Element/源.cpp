#include<iostream>
#include<string>
#include<vector>


using namespace std;



int findPeakElement(vector<int>& nums)
{

	int m = nums.size();
	if (m == 1)return 0;

	
	int low = 0;
	int high = m - 1;

	while (low<high)
	{
		int mid = (low + high) / 2;

		if (nums[mid] < nums[mid + 1])
		{
			low = mid +1;
		}
		else
		{
			high = mid;
		}



	}
	return low;


}

void main()
{

}