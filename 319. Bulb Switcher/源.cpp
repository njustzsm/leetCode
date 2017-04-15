#include<iostream>
#include<vector>
#include<math.h>
using namespace std;



int bulbSwitch(int n) 
{
	if (n == 0)return 0;

	int result = 0;
	

	for (int i = 1; i <= sqrt(n); i++)
	{
			result++;
	}
	return result;

}

int main()
{
	int result = bulbSwitch(2);
	cout << result;
	return 0;
}