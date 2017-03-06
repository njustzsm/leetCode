#include<iostream>
#include<string>


using namespace std;

string thousand[4] = { "","M", "MM", "MMM" };
string hundred[10] = { "","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
string ten[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
string one[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };


string intToRoman(int num) 
{
	string result;
	int resNum;

	resNum = num / 1000;
	num %= 1000;
	result += thousand[resNum];

	resNum = num / 100;
	num %= 100;
	result += thousand[resNum];

	resNum = num / 10;
	num %= 10;
	result += thousand[resNum];

	result += thousand[num];

	return result;
}

/*
ÂÞÂíÊý×Ö

1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

1000~3000: {"M", "MM", "MMM"}.
*/

int main()
{
	return 0;
}