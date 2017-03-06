#include<iostream>

int divide(int dividend, int divisor)
{
	long long int curDividend = dividend;
	long long int curDivisor = divisor;

	if (divisor == 0)return INT_MAX;
	if (divisor == 1)return dividend;
	if (divisor == -1)
	{
		if (dividend == INT_MIN)
			return INT_MAX;
		return -dividend;
	}

	if (abs(curDividend) < abs(curDivisor))return 0;


	bool isPositive = true;
	

	if (curDividend < 0)
	{
		isPositive = !isPositive;
		curDividend = -curDividend;
	}
	if (curDivisor < 0)
	{
		isPositive = !isPositive;
		curDivisor = -curDivisor;

	}

	long int result = 1;
	long long int temp = curDivisor;
	while (temp<curDividend)
	{
		temp <<=1;
		result <<=1;
	}

	if (temp == curDividend)
	{
		if (isPositive)
			return result;
		return -result;
	}


	result = result >> 1;
	temp = temp >> 1;
	while (true)
	{
		temp += curDivisor;
		if (temp <= curDividend)
			result++;
		else
		{
			if (isPositive)
				return result;
			return -result;
		}
	}
}

void main()
{
	divide(INT_MIN,2);
}