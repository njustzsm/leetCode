#include<iostream>
#include<algorithm>
using namespace std;

double myPow(double x, int n) 
{
	if (n == 0)
		return 1.0;

	if (n < 0)
	{
		if (n == INT_MIN)
			return 1 / pow(x, INT_MAX) / x;
		else
			return 1.0 / pow(x,-n);
	}
	else
	{
		if (n % 2 == 0)
		{
			double temp = myPow(x,n>>1);
			return temp*temp;
		}
		else
		{
			double temp = myPow(x,(n-1)>>1);
			return temp*temp*x;
		}
	}
	
	
	
}

void main()
{

}