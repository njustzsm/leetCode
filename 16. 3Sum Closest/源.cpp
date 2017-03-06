#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int minvalue = 9999999;
int result=0;

int threeSumClosest(vector<int>& nums, int target) {

	int minvalue = 9999999;
	int result = 0;

	sort(nums.begin(),nums.end());

	int n = nums.size();

	for (int i = 0; i < n-2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n ; k++)
			{
				int sum = nums[i] + nums[j] + nums[k];

				if (abs(sum - target) < minvalue)
				{
					result = sum;
					minvalue = abs(sum - target);
				}
				if (sum>target)break;
			}
		if (nums[i] + nums[j] > target)break;
		}

	}

	return result;

}

int main()
{
	int tt[] = { 56, 57, -47, -14, 23, 31, 20, 39, -51, 7, 
		-4, 43, -53, 32, 24, 56, -28, 90, -75, -6, 21,
		-100, 41, -84, 95, 95, 44, 84, 70, -22, -86,
		-6, 90, -87, 65, -28, -29, -94, 98, -28, -100, 23,
		-25, 6, -56, -54, -5, 53, -88, -25, -31, -71, -13,
		-62, 73, -35, -78, 16, 99, 97, 84, -27, -43, -50, 18, 
		-16, -61, 7, -17, 16, -92, 28, 43, -38, -33, -27, 84, -72
		, -100, -91, -97, -99, 59, -63, 73, 99, 98, -100, -37, -80,
		3, 18, 93, -81, 12, -75, -43, 99, 10, 10, -6, 13, 0, 76, -82, 
		-5, 27, -38, -81, 77, -55, -100, 90, -32, -25, -15, -16, 68, 
		-6, 87, 65, -38, 82, 78, -61, 87, -72, 46, 50, -60, 86, 39,
		69, 85, -49, 28 };

	//- 289
	vector<int>data;
	//data.push_back(0); data.push_back(1); data.push_back(2);
	for (int i = 0; i < 136; i++)
		data.push_back(tt[i]);

	threeSumClosest(data,-289);

	return 0;
}