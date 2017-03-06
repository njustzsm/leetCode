#include<iostream>


bool isPalindrome(int x) 
{
	if (x == INT_MAX || x == INT_MIN)
		return false;

	int src = x;

	if (x < 0)x = -x;

	int y = 0;

	while (x>0)
	{
		int res = x % 10;
		y = y * 10 + res;
		x /= 10;
	}

	if (src == y)return true;
	return false;


}



void main()
{
	int x = 1;
	isPalindrome(x);
}