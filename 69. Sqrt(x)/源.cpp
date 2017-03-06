#include<iostream>
#include<algorithm>

int mySqrt(int x) 
{
	if (x == 0 || x == 1)return x;
	long long int p = 0, q = x;
	while (q-p>1)
	{
		long long int mid = (p + q) / 2;

		long long int curX = mid*mid;
		if (curX < x)
		{
			p = mid;
		}
		else if (curX>x)
		{
			q = mid;
		}
		else
			return mid;
	}

	long long int tt = x;

	if (p*p==tt)return p;
	if (q*q==tt)return q;
	return p;


	
}

void main()
{
	int x = 2147395599;
	int result = mySqrt(x);
}