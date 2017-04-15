#include<iostream>
#include<vector>

using namespace std;



int nthSuperUglyNumber(int n, vector<int>& primes) 
{
	if (n == 0)return 0;
	int*result = new int[n];
	int*indexList = new int[primes.size()];

	for (int i = 0; i < primes.size(); i++)
		indexList[i] = 0;

	
	result[0] = 1;
	
	for (int i = 1; i < n; i++)
	{
		int tempIndex, val = INT_MAX;
		for (int j = 0; j <primes.size(); j++)
		{
			if (result[indexList[j]]*primes[j] < val)
			{
				tempIndex = indexList[j];
				val = result[indexList[j]] * primes[j];
			}
		}
		result[i] = val;
		for (int j = 0; j < primes.size(); j++)
		{
			while (result[indexList[j]] * primes[j] <= val)
			{
				indexList[j]++;
			}
		}
	}
	return result[n - 1];


}

int main()
{
	vector<int>data{2,3,5};
	int n = 4;
	int tt = nthSuperUglyNumber(n,data);
	return 0;
}