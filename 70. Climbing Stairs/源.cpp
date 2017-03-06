#include<iostream>

int climbStairs(int n) 
{
	int countN = 1;
	int p = 1, q = 1;
	
	while (countN<n)
	{
		int temp = p + q;
		p = q;
		q = temp;
		countN++;
	}
	return q;
}

void main()
{

}