#include<iostream>
#include<math.h>
using namespace std;


bool isPowerOfThree(int n) 
{
	if (n <= 0)return false;
	double src = n*1.0;
	

	int result = (log2(src)/log2(3.0));

	return pow(3, result) == n;

}

int main()
{
	isPowerOfThree(243);
	return 0;
}