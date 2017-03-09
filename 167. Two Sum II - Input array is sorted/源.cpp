#include<iostream>
#include<vector>

using namespace std;


vector<int> twoSum(vector<int>& numbers, int target) 
{
	int m = numbers.size();
	vector<int>result;
	if (m <= 1)return result;

	int p = 0, q = m-1;

	while (numbers[p]+numbers[q]!=target&&p<q)
	{
		if (numbers[p] + numbers[q] < target)
		{
			p++;
		}
		else
			q--;
	}
	if (p < q)
	{
		result.push_back(p+1);
		result.push_back(q+1);
	}
	return result;
}

void main()
{

}