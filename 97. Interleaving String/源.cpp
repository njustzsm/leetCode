#include<iostream>
#include<string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) 
{
	//»ØËÝ·¨£¬³¬Ê±
	if (s1.size() + s2.size() != s3.size())return false;
	if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0)return true;
	
	int* check = new int[s3.size()];
	int*p1Index = new int[s3.size()];
	int*p2Index = new int[s3.size()];

	memset(check,0,s3.size()*sizeof(int));
	memset(p1Index, 0, s3.size()*sizeof(int));
	memset(p2Index, 0, s3.size()*sizeof(int));

	int p1 = 0, p2 = 0, p3 = 0;

	while (p3<s3.size())
	{
		char cur=s3[p3];

		if (p1 < s1.size() && s1[p1] == cur&&p2 < s2.size() && s2[p2] == cur)
		{
			check[p3] = 1;
			p1Index[p3] = p1;
			p2Index[p3] = p2;
			p1++;
		}
		else if (p1 < s1.size() && s1[p1] == cur)
		{
			p1++;
		}
		else if (p2 < s2.size() && s2[p2] == cur)
		{
			p2++;
		}
		else
		{
			int tt = p3;
			while (tt>=0)
			{
				if (check[tt] == 2)
				{
					check[tt] = 0;
					p1Index[tt] = 0;
					p2Index[tt] = 0;
				}
				else if (check[tt] == 1)
				{
					p1 = p1Index[tt];
					p2 = p2Index[tt];
					p2++;
					p3 = tt;
					check[tt] = 2;
					break;
				}
				tt--;
			}
			if (tt < 0)return false;
		}
		p3++;
	}

	return true;
	

}


bool isInterleave1(string s1, string s2, string s3)
{
	int l1 = s1.size(),l2=s2.size(),l3=s3.size();
	if (l1 + l2 != l3)return false;
	if (l1 == 0 && l2 == 0 && l3 == 0)return true;

	bool**grid = new bool*[l1+1];
	for (int i = 0; i < l1+1; i++)
	{
		grid[i] = new bool[l2+1];
		memset(grid[i], false, l2 + 1);
	}

	grid[0][0] = true;
	for (int i = 1; i <= l2; i++)
	{
		grid[0][i] = grid[0][i - 1] && s2[i - 1] == s3[i - 1];
	}

	for (int i = 1; i <= l1; i++)
	{
		grid[i][0] = grid[i - 1][0] && s1[i - 1] == s3[i - 1];
	}

	for (int i = 1; i <= l1; i++)
	{
		for (int j = 1; j <= l2; j++)
		{
			grid[i][j] = (grid[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (grid[i][j-1]&&s2[j-1]==s3[i+j-1]);
		}
	}

	return grid[l1][l2];


}
void main()
{
	string s1 = "ab";
	string s2 = "bc";
	string s3 = "babc";
	//isInterleave(s1,s2,s3);
}