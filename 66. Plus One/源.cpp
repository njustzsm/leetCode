#include<iostream>
#include<vector>

using namespace std;


vector<int> plusOne(vector<int>& digits) 
{
	int num = digits.size();
	int add = 1;

	for (int i = num - 1; i >= 0; i--)
	{
		int cur = digits[i] + add;
		add = cur / 10;
		digits[i] = cur % 10;
		if (add == 0)break;
	}

	if (add == 0)
	{
		vector<int>result;
		for (int i = 0; i < num; i++)
		{
			result.push_back(digits[i]);
		}
		return result;
	}
	else
	{
		vector<int>result;
		result.push_back(add);
		for (int i = 0; i < num; i++)
			result.push_back(digits[i]);
		return result;
	}

}

void main()
{
	vector<int>digits;
	digits.push_back(5); digits.push_back(6);
	digits.push_back(2); digits.push_back(0);
	digits.push_back(0); digits.push_back(4);
	digits.push_back(6); digits.push_back(2);
	digits.push_back(4); digits.push_back(9);
	plusOne(digits);
}