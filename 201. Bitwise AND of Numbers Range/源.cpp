#include<iostream>

using namespace std;


int rangeBitwiseAnd(int m, int n) 
{
	int result = 0;

	int tag = 1;
	for (int i = 0; i < 30; i++)
		tag = tag << 1;

	while (tag>0)
	{
		if ((m&tag) && (n&tag))
		{
			result = result | tag;
		}
		else if ((!(m&tag)) && (n&tag))
		{
			return result;
		}
		tag = tag >> 1;
	}

	return result;

}
void main()
{

}