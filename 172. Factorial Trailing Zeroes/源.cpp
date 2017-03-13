#include<iostream>
#include<math.h>


int trailingZeroes(int n) 
{
	int result = 0;
	

	while (n>=5)
	{
		result += n / 5;
		n /= 5;

	}
	return result;
}

void main()
{
	int result = trailingZeroes(200);
}