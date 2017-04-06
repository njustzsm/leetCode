#include<string>
#include<vector>
#include<map>
using namespace std;

string getHint(string secret, string guess) 
{
	int n = secret.size();

	bool*check = new bool[n];
	memset(check,false,n*sizeof(bool));

	int bulk, cow;
	bulk = cow = 0;

	int curMap[10] = {0};

	for (int i = 0; i < n; i++)
	{
		if (secret[i] == guess[i])
		{
			check[i] = true;
			bulk++;
		}
		else
		{
			curMap[secret[i] - '0']++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (check[i])continue;

		char cur = guess[i];

		if (curMap[cur - '0']>0)
		{
			curMap[cur - '0']--;
			cow++;
		}
	}

	return to_string(bulk) + "A" + to_string(cow) + "B";



}

int main()
{
	return 0;
}