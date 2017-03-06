#include<iostream>


int reverse(int x) 
{
	bool tag =false;
	if (x < 0)tag = true;

	long long int s = x;
	if (tag)
		s = -s;


	long long int result = 0;

	while (s>0)
	{
		int res = s % 10;
		s = s / 10;
		result = 10 * result + res;
	}

	if (tag)
		result = -result;

	if (result<INT_MIN || result>INT_MAX)return 0;
	return result;


}

void main()
{
	int x = 1;
	reverse(x);
}