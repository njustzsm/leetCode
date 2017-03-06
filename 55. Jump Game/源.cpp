#include<iostream>
#include<vector>

using namespace std;

vector<int> data;

bool isReach(int src,int dst)
{
	if (dst == 0)return true;
	if (src < 0 && dst != 0)return false;

	if (data[src] >= dst - src)
		return isReach( src - 1, src);
	else
		return isReach(src-1,dst);

}
bool canJump(vector<int>& nums) 
{
	data = nums;
	if (nums.size() <= 1)return true;
	return isReach(nums.size() - 2,nums.size()-1);
}

void main()
{

}