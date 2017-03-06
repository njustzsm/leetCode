#include<iostream>
#include<string>

using namespace std;

string convert1(string s, int numRows)
{
	if (s.size() < numRows || numRows == 1)return s;

	string result = s;
	int index = 0;

	int num = 2 * numRows - 2;

	for (int j = 0; j < numRows; j++)
	{
		for (int i = 0; i < s.size(); i += num)
		{
			if (i == 108 && j == 47)
			{
				int tt = 0;
			}
			if (j == 0 || j == numRows - 1)
			{
				if (i + j < s.size())
				{
					result[index++] = s[i + j];
				}
			}
			else
			{
				if (i + j<s.size())
					result[index++] = s[i + j];
				if (i+j+ 2 * (numRows - 1 - j)<s.size())
					result[index++] = s[i+j + 2 * (numRows - 1 - j)];
			}

		}
	}



	return result;




}
string convert(string s, int numRows) 
{
	if (s.size() < numRows||numRows==1)return s;

	string result =s;

	int numCols = (s.size() / (2 * numRows - 2)) * 2;
	if (s.size() -numCols*(2 * numRows - 2)>0)
		numCols++;
	if (s.size() - numCols*(2 * numRows - 2) > numRows)
		numCols++;

	char**grid = new char*[numRows];
	for (int i = 0; i < numRows; i++)
	{
		grid[i] = new char[numCols];
		for (int j = 0; j < numCols; j++)
		{
			grid[i][j] = ' ';
		}
	}

	int index=0;
	for (int i = 0; i <numCols; i+=2)
	{
		int t = 0;
		while (index<s.size()&&t<numRows)
		{
			grid[t++][i * 2] = s[index++];
		}
		t = numRows - 2;
		while (index<s.size() && t>=1)
		{
			grid[t--][i * 2 + 1] = s[index++];
		}
		
	}

	int tt = 0;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			if (grid[i][j] != ' ')
			{
				result[tt++]= grid[i][j];
			}
		}
	}
	return result;


}

void main()
{
	string s = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
	string result=convert1(s,55);
}