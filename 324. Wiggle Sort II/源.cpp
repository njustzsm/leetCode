#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*void trans(vector<int>&nums,int index)
{
	int p = index - 2;
	int curNum = nums[index];

	while (p>=0&&nums[p]<curNum)
	{
		nums[p + 2] =nums[p];
		p -= 2;
	}
	p += 2;

	nums[p] = curNum;

}

void transRight(vector<int>&nums, int index)
{
	int curNum = nums[index];

	index += 2;

	while (index<nums.size()&&nums[index]>curNum)
	{
		nums[index - 2] = nums[index];
		index += 2;
	}

	index -= 2;
	nums[index] = curNum;
}

void wiggleSort(vector<int>& nums) 
{
	if (nums.size() <= 1)return;
	for (int i = 2; i < nums.size(); i+=2)
	{
		trans(nums,i);
	}

	for (int i = 1; i < nums.size(); i += 2)
	{
		trans(nums,i);
	}

	int index;
	

	if (nums.size() % 2 == 0)
	{
		index = nums.size() - 1;
	}
	else
	{
		index = nums.size() - 2;
	}

	while (nums[0]>nums[index])
	{
		int temp = nums[0];
		nums[0] = nums[index];
		nums[index] = temp;

		transRight(nums,0);
		trans(nums,index);
	}


}
*/

//�÷������±�Ϊż����λ�÷����������н�С�Ĳ��֣��±�Ϊ�����з��ýϴ�Ĳ��֣����ұ��뽵�����У���������������ȵ����
void wiggleSort(vector<int>& nums)
{
	int n = nums.size();
	if (n <= 1)return;

	vector<int>sortV(nums);
	
	sort(sortV.begin(),sortV.end());


	int p = n % 2 == 0 ? n / 2 - 1 : n / 2;
	int q = n - 1;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			nums[i] = sortV[p--];
		}
		else
			nums[i] = sortV[q--];
	}
}
int main()
{
	return 0;
}