#include<iostream>
#include<string>
#include<vector>
using namespace std;



vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
	int wordLength = 0;
	int wordNum = 0;

	int src = 0, p = 0;
	vector<string>result;
	
	while (p<words.size())
	{
		if (wordLength+words[p].size()+wordNum <= maxWidth)
		{
			wordNum++;
			wordLength += words[p].size();
			p++;
		}
		else
		{
			if (wordNum == 1)
			{
				string cur = words[src];
				string empty(maxWidth - wordLength,' ');
				//for (int i = 0; i < maxWidth - wordLength; i++)
				//{
				//	cur += " ";
				//}
				cur += empty;
				result.push_back(cur);
			}
			else
			{
				int spaceNum = (maxWidth - wordLength) / (wordNum-1);
				int res = maxWidth - wordLength - spaceNum*(wordNum-1);
				string empty(spaceNum,' ');
				//for (int i = 0; i < spaceNum; i++)
					//empty += " ";
				string cur = words[src];
				for (int i = src + 1; i < p; i++)
				{
					if (res>0)
					{
						cur += empty + " " + words[i];
						res--;
					}
					else
					{
						cur += empty + words[i];
					}
				}
				result.push_back(cur);

			}
			src = p;
			wordLength = wordNum = 0;
		}

	}

	if (wordNum == 1)
	{
		string cur = words[src];
		
		string empty(maxWidth - wordLength,' ');
		cur += empty;
		result.push_back(cur);
	}
	else if (wordNum>1)
	{
		int countN = 0;
		string cur = words[src];
		countN += cur.size();
		for (int i = src + 1; i < p; i++)
		{
				cur +=" " + words[i];
				countN += 1 + words[i].size();
		}
		string empty(maxWidth-countN,' ');
		cur += empty;
		result.push_back(cur);

	}
	return result;
}

void main()
{
	string tt[] = { "What", "must", "be", "shall", "be." };
	//string a = "";
	vector<string>data;
	//data.push_back(a);
	for (int i = 0; i < 5; i++)
		data.push_back(tt[i]);
	vector<string>result = fullJustify(data,12);
}