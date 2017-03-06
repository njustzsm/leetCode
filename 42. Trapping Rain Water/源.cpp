#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int calc(int p,int q,int bottom,vector<int>height)
{
	int result = 0;
	int curHeight = min(height[p],height[q]);

	for (int i = p + 1; i < q; i++)
	{
		if (height[i] >= curHeight)
			continue;
		else
		{
			if (height[i] <= bottom)
			{
				result += curHeight - bottom;
			}
			else
			{
				result += curHeight - height[i];
			}
		}
	}
	return result;

}
int trap(vector<int>& height) 
{
	if (height.size() <= 2)return 0;

	int curBottom = 0,result=0;
	int p = 0, q = height.size() - 1;

	while (q - p >= 2 && height[p] <= curBottom)
	{
		p++;
	}
	while (q - p >= 2 && height[q] <= curBottom)
	{
		q--;
	}
	
	while (q-p>=2)
	{
		int curResult = calc(p,q,curBottom,height);
		result += curResult;

		curBottom = min(height[p],height[q]);

		if (height[p] < height[q])
		{
			int value = height[p];
			while (q-p>=2&&height[p]<=value)
			{
				p++;
			}
		}
		else if (height[p] > height[q])
		{
			int value = height[q];
			while (q - p >= 2 && height[q] <= value)
			{
				q--;
			}
		}
		else
		{
			int value = height[p];
			while (q - p >= 2 && height[p] <= value)
			{
				p++;
			}
			value = height[q];
			while (q - p >= 2 && height[q] <= value)
			{
				q--;
			}
		}
	}
	return result;
}

void main()
{

}