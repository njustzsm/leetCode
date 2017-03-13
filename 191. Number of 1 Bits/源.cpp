#include<iostream>
#include<stdint.h>
using namespace std;


int hammingWeight(uint32_t n) 
{
	int result = 0;

	unsigned int tag = 1;

	for (int i = 0; i < 32; i++)
	{
		if (n&tag)
		{
			result++;
		}
		tag = tag << 1;
	}

	return result;


}
void main()
{

}