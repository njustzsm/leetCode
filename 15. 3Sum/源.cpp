#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


/*
//ԭ�ⷨ
void QuickSort(int src,int end,vector<int>& nums)
{
if (src >= end)return;

int cur = nums[src];

int p = src, q = end;

while (p<q)
{
while (nums[q]>=cur&&p<q)
{
q--;
}
while (nums[p]<=cur&&p<q)
{
p++;
}

if (p < q)
{
int tt = nums[p];
nums[p] = nums[q];
nums[q] = tt;
}

}

nums[src] = nums[p];
nums[p] = cur;

QuickSort(src,p-1,nums);
QuickSort(p+1,end,nums);


}


vector<vector<int>> threeSum(vector<int>& nums) {
int n = nums.size();

QuickSort(0,n-1,nums);


int lastI,lastJ,lastK;

vector<vector<int>>result;

for (int i = 0; i < n-2; i++)
{
if (i == 0)lastI = nums[i];
else
{
if (lastI == nums[i])
continue;
else
lastI = nums[i];
}

for (int j = i + 1; j < n-1; j++)
{
if (j == i+1)lastJ = nums[j];
else
{
if (lastJ == nums[j])
continue;
else
lastJ = nums[j];
}

int tmpSum = nums[i] + nums[j];
if (tmpSum>0)break;

for (int k = j + 1; k < n; k++)
{
if (k == j+1)lastK = nums[k];
else
{
if (lastK == nums[k])
continue;
else
{
lastK = nums[k];
}
}

if (tmpSum + nums[k] == 0)
{
vector<int>tmp;
tmp.push_back(nums[i]); tmp.push_back(nums[j]); tmp.push_back(nums[k]);
result.push_back(tmp);
break;
}
else if (tmpSum + nums[k] >0)
break;
}


}
}
return result;
}
*/


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

vector<vector<int>> threeSum(vector<int>& nums)
{
	
	vector<vector<int>>result;

	if (nums.size() < 3)return result;

	int lastRes=0;

	sort(nums.begin(),nums.end());

	for (int i = 0; i < nums.size() - 2; i++)
	{
		if (nums[i]>0)break;

		int res = 0 - nums[i];

		if (i != 0 && res == lastRes)
			continue;
		lastRes = res;

		vector<vector<int>>output = TwoSum(nums,i+1,nums.size()-1,res);

		while (output.size()>0)
		{
			vector<int>tt = output[output.size()-1];
			output.pop_back();
			tt.push_back(nums[i]);
			result.push_back(tt);
		}
	}

	return result;
}

int main()
{
	vector<int>data;

	data.push_back(1);
	data.push_back(-1);
	data.push_back(-1);
	data.push_back(0);
	//data.push_back(-1);
	//data.push_back(-4);

	
}
