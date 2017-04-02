#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;




int numSquares(int n) 
{
	int*data = new int[n+1];
	data[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = INT_MAX;
		for (int j = 1; j*j <=i; j++)
		{
			tmp = min(tmp,data[i-j*j]+1);
		}
		data[i] = tmp;
	}

	return data[n];

}
void main()
{

}