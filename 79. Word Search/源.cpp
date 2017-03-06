#include<iostream>
#include<string>
#include<vector>
using namespace std;

int grid[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int m, n;
bool**check;
bool result = false;
vector<vector<char>>data;
bool succes = false;
void isMatch(string word,int x,int y)
{
	if (succes)
		return;
	if (word.size()<=1)
	{
		succes = true;
		result = true;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int xx =x+grid[i][0];
		int yy = y + grid[i][1];
		if (xx >= 0 && xx < m&&yy >= 0 && yy < n&&!check[xx][yy] && word[1] == data[xx][yy]&&!succes)
		{
			check[xx][yy] = true;
			isMatch(word.substr(1),xx,yy);
			check[xx][yy] = false;
		}
	}

}

bool exist(vector<vector<char>>& board, string word) 
{
	m = board.size();
	if (m == 0)return false;
	n = board[0].size();
	data = board;
	check = new bool*[m];
	for (int i = 0; i < m; i++)
	{
		check[i] = new bool[n];
		memset(check[i],false,n*sizeof(bool));
	}

	if (word.size() == 0)return false;

	char cur = word[0];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cur == board[i][j])
			{
				check[i][j]=true;
				isMatch(word,i,j);
				check[i][j] =false;
			}
			if (result)
				return true;
		}
	}
	return false;

}

void main()
{
	vector<vector<char>>board;
	vector<char>list;
	list.push_back('a');
	list.push_back('a');
	board.push_back(list);

	string word = "aaa";
	exist(board, word);

}