#include<iostream>
#include<vector>

using namespace std;


int minPatches(vector<int>& nums, int n) 
{
	int index =0;
	int addResult = 0;

	long long int curRange =1;

	if (nums.empty()||nums[index] != 1)
		addResult++;
	else
		index++;



	while (true)
	{
		if (curRange >= n)
			break;

		if (index < nums.size())
		{
			long long int res = nums[index];
			if (res <= curRange+1)
			{
				curRange+= res;
			}
			else
			{
				addResult++;
				curRange += curRange + 1;
				index--;
			}
			index++;
		}
		else
		{
			addResult++;
			curRange += curRange + 1;
		}
		
	}
	return addResult;
}


int main()
{

}