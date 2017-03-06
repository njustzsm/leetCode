#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>>result;
int countN = 1;
void GenerateSpiral(int x,int y,int width)
{
	for (int i = y; i < y + width; i++)
	{
		result[x][i] = countN++;
	}
	for (int i = x + 1; i < x + width; i++)
	{
		result[i][y + width - 1] = countN++;
	}
	for (int i = y + width - 2; i >= y; i--)
	{
		result[x + width - 1][i] = countN++;
	}
	for (int i = x + width - 2; i >= x + 1; i--)
	{
		result[i][y] = countN++;
	}
}


vector<vector<int>> generateMatrix(int n) 
{

	vector<int>list;
	list.resize(n);
	for (int i = 0; i < n; i++)
		result.push_back(list);

	int x = 0, y = 0;
	int width = n;

	while (width>0)
	{
		GenerateSpiral(x,y,width);
		x++;
		y++;
		width -= 2;
	}
	return result;
}

void main()
{

}