#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int largestRectangleArea(vector<int>& heights) 
{
	if (heights.size() == 0)return 0;
	
	vector<int>stack;
	int result = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		if (stack.empty() || heights[i]>=stack[stack.size()-1])
		{
			stack.push_back(heights[i]);
		}
		else
		{
			int n = 0;
			while (!stack.empty() && stack[stack.size() - 1]>heights[i])
			{
				n++;
				if (result < n*stack[stack.size() - 1])
				{
					result = n*stack[stack.size() - 1];
				}
				stack.pop_back();
			}
			for (int j = 0; j <= n; j++)
			{
				stack.push_back(heights[i]);
			}
		}
	}

	if (stack[0] == stack[stack.size() - 1])
	{
		int value = stack[0] * stack.size();
		if (value > result)return value;
		return result;
	}
	else
	{
		int n = stack.size();
		for (int i = 0; i < stack.size(); i++)
		{
			int value = n*stack[i];
			if (result < value)result = value;
			n--;
		}
		return result;
	}
	
	
}

void main()
{
	vector<int>heights;
	heights.push_back(2);
	heights.push_back(1);
	heights.push_back(5);
	heights.push_back(6);
	heights.push_back(2);
	heights.push_back(3);
	largestRectangleArea(heights);
}