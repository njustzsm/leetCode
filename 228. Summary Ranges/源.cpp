#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) 
{
	vector<string>result;
	int m = nums.size();
	if (m == 0)return result;

	int src = 0;

	for (int i = 0; i < m; i++)
	{
		if (i - src != nums[i] - nums[src])
		{
			if (i - src == 1)
			{
				string cur = to_string(nums[src]);
				result.push_back(cur);

				src = i;
				i--;
			}
			else
			{
				string cur = "->";

				cur =to_string(nums[src])+ cur;
				cur += to_string(nums[i-1]);
				result.push_back(cur);
				src = i;
				i--;

			}

		}
		
	}

	if (src == m - 1)
	{
		string cur = to_string(nums[src]);
		result.push_back(cur);
	}
	else
	{
		string cur = "->";
		cur = to_string(nums[src]) + cur;
		cur += to_string(nums[m-1]);
		result.push_back(cur);
	}




	return result;


}
void main()
{

}