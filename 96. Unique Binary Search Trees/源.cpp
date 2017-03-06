#include<iostream>


using namespace std;



int helper(int begin,int end)
{
	if (begin>=end)
		return 1;

	int result=0;

	for (int i = begin; i <= end; i++)
	{
		result += helper(begin, i - 1)*helper(i+1,end);
	}
	return result;

	
}

int numTrees(int n) 
{
	if (n == 0)return 0;

	int*g = new int[n + 1];

	memset(g,0,(n+1)*sizeof(int));
	g[0] = g[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= i - 1;j++)
		{
			g[i] += g[j] * g[i - j - 1];
		}
	}

	return g[n];

	
}
void main()
{

}