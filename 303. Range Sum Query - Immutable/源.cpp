#include<iostream>
#include<vector>


using namespace std;
class NumArray {
public:

	vector<long long int>sums;
	NumArray(vector<int> nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0)
			{
				sums.push_back(nums[i]);
			}
			else
				sums.push_back(sums[i-1]+nums[i]);
		}
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return sums[j];
		else
			return sums[j] - sums[i - 1];
	}
};

int main()
{
	return 0;
}