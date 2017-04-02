#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int nthUglyNumber(int n) 
{
	vector<int>data;
	data.push_back(1);

	int num_2 =0, num_3 = 0, num_5 = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int nextOne = min(min(data[num_2]*2,data[num_3]*3),data[num_5]*5);

		data.push_back(nextOne);

		while (data[num_2] * 2 <= nextOne)
		{
			num_2++;
		}
		while (data[num_3] * 3 <= nextOne)
		{
			num_3++;
		}
		while (data[num_5] * 5 <= nextOne)
		{
			num_5++;
		}

	}

	return data[data.size()-1];

}
void main()
{

}