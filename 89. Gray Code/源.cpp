#include<iostream>
#include<vector>

using namespace std;


vector<int> grayCode(int n) 
{
	vector<int>result;
	if (n == 0)return result;

	for (int i = 0; i < 1<<n; i++)
	{
		result.push_back(i^i>>1);
	}
	return result;
}
void main()
{

}