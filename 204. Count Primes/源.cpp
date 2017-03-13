#include<iostream>
#include<math.h>
#include<vector>
using namespace std;


vector<int>primerNum;
bool isPrime(int n)
{
	if (n == 1)return false;
	if (n == 2)return true;

	int m = sqrt(n);
	for (int i = 0; i <=primerNum.size(); i++)
	{
		if (primerNum[i] > m)
			break;

		if (n%primerNum[i] == 0)
			return false;
	}
	return true;
}

int countPrimes(int n) 
{


	int result = 0;

	for (int i = 2; i <n; i++)
	{
		if (isPrime(i))
		{
			primerNum.push_back(i);
			result++;
		}
			
	}
	return result;
}

void main()
{

}