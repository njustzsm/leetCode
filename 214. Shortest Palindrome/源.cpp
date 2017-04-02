#include<iostream>
#include<string>
#include<vector>
using namespace std;



string shortestPalindrome1(string s) 
{
	string str = s;

	reverse(str.begin(),str.end());

	str += s + "#" + str;

	int len1 = s.size(), len2 = str.size();


	vector<int>vec(len2,0);

	for (int i = 1; i < len2; i++)
	{
		int k = vec[i-1];
		while (k>0&&str[k]!=str[i])
		{
			k = vec[k - 1];
		}
		
		if (str[i] == str[k])
		{
			k += 1;
		}
		vec[i] = k;

	}
	return str.substr(len1+1,len1-vec[len2-1])+s;


}

string shortestPalindrome(string s)
{
	int n = s.size();
	string t = s;
	reverse(t.begin(),t.end());
	

	t = s +'#'+ t;
	int*myNext = new int[n*2+2];
	myNext[0] = -1;


	int j = 0, k = -1;
	while (t[j]!='\0')
	{
		while (k!=-1&&t[j]!=t[k])
		{
			k = myNext[k];
		}

		k++;
		j++;
		if (t[j] == t[k])
			myNext[j] = myNext[k];
		else
			myNext[j] = k;
	}

	int length = myNext[2 * n + 1];

	if (length == n)
		return s;
	else
	{
		string tt = s.substr(length);
		reverse(tt.begin(),tt.end());
		return tt + s;
	}
		



}
void main()
{
	string a = "aacecaaa";
	string result = shortestPalindrome(a);
}