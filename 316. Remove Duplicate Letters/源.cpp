#include<iostream>
#include<string>
#include<vector>
using namespace std;








string removeDuplicateLetters(string s)
{
	if (s.size() <= 1)return s;

	int countLetter[26] = {0};
	bool choose[26] = {false};

	int count = 0;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (i != 0 && s[i - 1] == s[i])
			continue;

		int index = s[i] - 'a';

		countLetter[index]++;
	}

	string result = "";

	

	
	
	return result;
	

}

int main()
{
	string data = "baa";
	string result = removeDuplicateLetters(data);
	return 0;

}