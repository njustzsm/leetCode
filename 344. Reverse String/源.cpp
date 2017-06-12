#include<iostream>
#include<string>


using namespace std;

void swap(string&s, int p, int q)
{
	char a = s[p];
	s[p] = s[q];
	s[q] = a;
}


string reverseString(string s) 
{
	if (s.size()<=1)return s;
	int p = 0, q = s.size() - 1;

	while (p<q)
	{
		swap(s,p,q);
		p++;
		q--;
	}
	return s;
}
int main()
{
	return 0;
}