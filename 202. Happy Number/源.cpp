#include<iostream>
#include<map>


using namespace std;

int getDigitMulty(int data)
{
	int result = 0;
	while (data>0)
	{
		int res = data % 10;
		result += res*res;
		data /= 10;
	}
	return result;
}



bool isHappy(int n) 
{
	if (n < 0)return false;
	if (n == 1)return true;

	map<int, int>check;

	int cur = getDigitMulty(n);



	while (cur!=1&&check.count(cur)==0)
	{
		check[cur] = 1;
		cur = getDigitMulty(cur);
	}
	
	if (cur == 1)return true;
	return false;

}

void main()
{
	bool result = isHappy(2);
}