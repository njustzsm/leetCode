#include<iostream>
#include<string>
#include<map>

using namespace std;

void swap(string&s, int p, int q)
{
	char a = s[p];
	s[p] = s[q];
	s[q] = a;
}


string reverseVowels(string s)
{
	if (s.size() <= 1)return s;

	map<char, bool>hashTable;
	hashTable['a'] = true; hashTable['e'] = true; hashTable['i'] = true;
	hashTable['o'] = true;hashTable['u'] = true;
	hashTable['A'] = true; hashTable['E'] = true; hashTable['I'] = true;
	hashTable['O'] = true; hashTable['U'] = true;
	int p = 0, q = s.size() - 1;

	while (p<q)
	{
		while (p<q&&hashTable.count(s[q])==0)
		{
			q--;
		}
		while (p<q&&hashTable.count(s[p]) == 0)
		{
			p++;
		}

		if (p < q)
		{
			swap(s,p,q);
			p++;
			q--;
		}
	}
	return s;
	
}
int main()
{
	return 0;
}