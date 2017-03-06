#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> TwoSum(vector<int>& nums, int p, int q, int target)
{
	vector<vector<int>> result;

	set<vector<int>>data;
	while (p<q)
	{
		if (nums[p] + nums[q] == target)
		{
			vector<int> tt;
			tt.push_back(nums[p]);
			tt.push_back(nums[q]);
			data.insert(tt);
			p++;
			q--;
		}
		else if (nums[p] + nums[q] >target)
		{
			q--;
		}
		else if (nums[p] + nums[q] < target)
		{
			p++;
		}
	}

	set<vector<int>>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
		result.push_back(*it);
	}



	return result;

}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>>result;
	set<vector<int>>data;

	if (nums.size() < 4)return result;

	sort(nums.begin(),nums.end());

	int num = nums.size();

	for (int i = 0; i < num-3; i++)
	{
		for (int j = i + 1; j < num - 2; j++)
		{
			vector<vector<int>>output = TwoSum(nums,j+1,nums.size()-1,target-nums[i]-nums[j]);
			
			while (output.size()>0)
			{
				vector<int>tt = output[output.size() - 1];
				output.pop_back();

				tt.push_back(nums[i]);
				tt.push_back(nums[j]);
				data.insert(tt);
			}
		}
	}

	set<vector<int>>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
		result.push_back(*it);
	}
	return result;

}

int main()
{
	return 0;
}