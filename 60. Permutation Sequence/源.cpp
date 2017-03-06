#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool* isCheck;


int Calc(int n)
{
	int result=1;
	while (n>0)
	{
		result *= n;
		n--;
	}
	return result;
}


int getKth(int k)
{
	int p = 1;
	while(k>0)
	{
		if (!isCheck[p])
		{
			k--;
		}
		p++;
	}
	return --p;
}

string getK(int n, int k)
{
	if (n == 1)
	{
		string result = "";
		int value = getKth(1);
		char a = '0' + value;
		result += a;
		return result;
	}
	int step = Calc(n - 1);
	int nn = k / step;
	if (nn == 0)
	{
		int value = getKth(1);
		isCheck[value] = true;
		char a = value + '0';
		return a + getK(n - 1, k);
	}
	else
	{
		int res = k - nn*step;
		if (res != 0)
		{
			int value = getKth(nn + 1);
			isCheck[value] = true;
			char a = '0' + value;
			return a + getK(n - 1, res);
		}
		else
		{
			int value = getKth(nn);
			isCheck[value] = true;
			char a = '0' + value;
			return a + getK(n - 1, step);
		}
	}
}

string getPermutation(int n, int k)
{
	isCheck = new bool[n+1];
	memset(isCheck,false,(n+1)*sizeof(bool));
	
	return getK(n,k);
}



void main()
{
	
}