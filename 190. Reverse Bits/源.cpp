#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>

using namespace std;

uint32_t reverseBits(uint32_t n) {

	unsigned int result = 0;
	unsigned int tag = 1;

	for (int i = 0; i < 32; i++)
	{
		if (n&tag)
		{
			result=result<<1;
			result += 1;
		}
		else
			result=result<< 1;

		tag=tag<< 1;

	}



	return result;

}

void main()
{
	unsigned int tt = 1;

	unsigned int result = reverseBits(tt);
}