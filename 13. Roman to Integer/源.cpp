#include<iostream>
#include<string>


using namespace std;

string thousand[4] = { "", "M", "MM", "MMM" };
string hundred[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
string ten[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
string one[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

int romanToInt(string s) 
{
	int result = 0;

	int tt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'M')
			tt++;
		else
			break;

		
	}

	result += tt * 1000;
	s = s.substr(tt);


		tt = 0;
		int index = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'C')
				tt++;
			else if (s[i] == 'D')
			{
				if (i == 0)
					tt += 5;
				else
					tt += 3;
			}
			else if (s[i] == 'M')
				tt += 8;
			else
				break;

			index++;
		}
		result += tt * 100;
		s = s.substr(index);

		tt = 0;
		index = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'X')
				tt++;
			else if (s[i] == 'L')
			{
				if (i == 0)
					tt += 5;
				else
					tt += 3;
			}
			else if (s[i] == 'C')
			{
				tt += 8;
			}
			else
				break;
			index++;
		}
		result += tt * 10;
		s = s.substr(index);



		tt = 0;
		index = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'I')
				tt++;
			else if (s[i] == 'V')
			{
				if (i == 0)
					tt += 5;
				else
					tt += 3;
			}
			else if (s[i] == 'X')
				tt += 8;
			else
				break;

			index++;
		}

		result += tt;
	
		return result;


}

int main()
{
	return 0;
}