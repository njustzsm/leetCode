#include<iostream>
#include<math.h>

using namespace std;

bool isPowerOfFour(int num) 
{
	if (num == 0)return false;
	int rate = log2(num);

	if (pow(2, rate) != num||rate%2!=0)
		return false;

	return true;
}

int main()
{

}