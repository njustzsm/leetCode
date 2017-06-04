#include<iostream>
#include<vector>
#include<string>

using namespace std;


vector<string> split(string str)
{
	vector<string>result;

	if (str.empty())
		return result;

	int p = 0, q = 0;

	while (q<str.size())
	{
		while (q<str.size()&&str[q]!=',')
		{
			q++;
		}
		string tmp = str.substr(p,q-p);
		result.push_back(tmp);
		q++;
		p = q;
		
	}


	return result;
	


}

bool isValidSerialization(string preorder) 
{
	return false;
}

int main()
{
	return 0;
}