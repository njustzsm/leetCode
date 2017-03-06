#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int min(int a, int b)
{
	if (a < b)return a;
	return b;
}

int max(int a, int b)
{
	if (a>b)return a;
	return b;
}

int maxArea(vector<int>data)
{
	int p = 0, q = data.size() - 1;
	int maxValue = 0;

	while (p<q)
	{
		int height = min(data[p],data[q]);
		maxValue = max(maxValue,(q-p)*height);

		if (data[p] < data[q])
		{
			int k = p;
			while (k<q&&data[k]<=data[p])
			{
				k++;
			}
			p = k;
		}
		else
		{
			int k = q;
			while (k>p&&data[k] <= data[q])
			{
				k--;
			}
			q = k;
		}
	}
	return maxValue;


}




int main()
{
	vector<int>pp;
	pp.push_back(1);
	pp.push_back(1);
	cout << maxArea(pp);
	return 0;
}