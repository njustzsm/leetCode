#include<iostream>
#include<vector>

using namespace std;


int titleToNumber(string s) 
{
	int num = 1;
	int result = 0;

	for (int i = s.size() - 1; i >= 0; i--)
	{
		int cur = s[i] - 'A';
		cur++;
		result += cur*num;
		num *=26;
	}
	return result;
}
void main()
{

}