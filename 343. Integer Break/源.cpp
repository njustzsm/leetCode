#include<iostream>
#include<algorithm>
using namespace std;

int his[59] = {0};

int getMax(int n)
{
	int maxResult = n;
	for (int i = 1; i <= n-1; i++)
	{
		int value0, value1;
		if (his[i] == 0)
			his[i] = getMax(i);;
		if (his[n - i] == 0)
			his[n - i] = getMax(n-i);
		maxResult = max(maxResult, his[i]*his[n-i]);
	}
	return maxResult;
}

int integerBreak(int n) 
{
	if (n == 1)return 1;


	int maxResult = 1;

	for (int i = 1; i <= n / 2; i++)
	{
		maxResult = max(maxResult, getMax(i)*getMax(n - i));
	}
	return maxResult;
}



int main()
{
	return 0;
}