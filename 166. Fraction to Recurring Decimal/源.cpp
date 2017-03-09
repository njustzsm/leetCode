#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;




string fractionToDecimal(int numerator, int denominator) 
{
	if (numerator == 0)return "0";
	if (denominator == 0)return "";


	string result = "";

	long long int numeratorA = numerator, denominatorA = denominator;

	if (numeratorA < 0)numeratorA = -numeratorA;
	if (denominatorA < 0)denominatorA = -denominatorA;

	long long int number = numeratorA / denominatorA;

	
	result+=to_string(number);
	

	long long int res = numeratorA - number*denominatorA;
	if (res == 0)
	{
		return to_string((long long int)numerator / denominator);
	}
		

	result += '.';

	vector<int>tt;
	map<int, int>resIndex;

	
	

	while (res!=0&&resIndex.count(res)==0)
	{
		resIndex[res] = tt.size();
		res *= 10;
		int cur = res / denominatorA;
		tt.push_back(cur);
		res -= cur*denominatorA;
	}


	if (res==0)
	{
		for (int i = 0; i<tt.size(); i++)
		{
			result += '0' + tt[i];
		}
		if ((numerator>0 && denominator > 0) || (numerator < 0 && denominator < 0))
			return result;
		else
			return "-" + result;
	}
	else
	{
		for (int i = 0; i<resIndex[res]; i++)
		{
			result += '0' + tt[i];
		}

		result += "(";
		for (int i = resIndex[res]; i<tt.size(); i++)
		{
			result += '0' + tt[i];
		}
		result += ")";

		if ((numerator>0 && denominator > 0) || (numerator < 0 && denominator < 0))
			return result;
		else
			return "-" + result;
		
	}

}

void main()
{
	int a = INT_MIN;
	int b =1;
	fractionToDecimal(a,b);
}