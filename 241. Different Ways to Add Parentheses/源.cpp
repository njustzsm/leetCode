#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;









vector<int> diffWaysToCompute(string input) 
{
	vector<int>result;

	if (input.empty())
		return result;
	

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*')
		{
			vector<int>left = diffWaysToCompute(input.substr(0,i));
			vector<int>right = diffWaysToCompute(input.substr(i+1));

			for (int j = 0; j < left.size(); j++)
			{
				for (int k = 0; k < right.size(); k++)
				{
					switch (input[i])
					{
					case '+':
						result.push_back(left[j]+right[k]);
						break;
					case '-':
						result.push_back(left[j] - right[k]);
						break;
					case '*':
						result.push_back(left[j] * right[k]);
						break;
					}
				}
			}



		}
	}
	if (result.empty())
		result.push_back(atoi(input.c_str()));
	return result;
}


void main()
{
	vector<int>tt = diffWaysToCompute("2*3-4*5");
}