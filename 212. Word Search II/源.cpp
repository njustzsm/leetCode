#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;


struct trieNode
{
	bool isExist;
	map<int, trieNode*>hashMap;
	string curStr;
};

int grid[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
set<string>result;
int m, n;
vector<vector<char>> graph;
bool**check;

void addWord(trieNode*root,string word)
{
	trieNode*p = root;
	for (int i = 0; i < word.size(); i++)
	{
		int id = word[i] - 'a';

		if (p->hashMap.count(id) == 0)
		{
			trieNode*addNode = new trieNode();
			addNode->isExist = false;
			addNode->curStr = p->curStr + word[i];
			p->hashMap[id]=addNode;
		}

		p = p->hashMap[id];
	}
	p->isExist = true;
}

void search(trieNode*root, int x, int y)
{

	if (root->isExist)
	{
		result.insert(root->curStr);
	}

	for (int i = 0; i < 4; i++)
	{
		int xx = x + grid[i][0];
		int yy = y + grid[i][1];
		if (xx >= 0 && xx < m&&yy >= 0 && yy < n&&!check[xx][yy] && root->hashMap.count(graph[xx][yy] - 'a'))
		{
			check[xx][yy] = true;
			search(root->hashMap[graph[xx][yy] - 'a'],xx,yy);
			check[xx][yy] = false;
		}
	}
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
	trieNode*root = new trieNode();
	root->isExist = false;
	root->curStr = "";

	m = board.size();
	n = board[0].size();
	graph = board;

	for (int i = 0; i < words.size(); i++)
	{
		addWord(root,words[i]);
	}

	check = new bool*[m];
	for (int i = 0; i < m; i++)
	{
		check[i] = new bool[n];
		memset(check[i],false,n*sizeof(bool));
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int id = graph[i][j] - 'a';
			if (root->hashMap.count(id))
			{
				for (int k = 0; k < m; k++)
				{
					memset(check[k], false, n*sizeof(bool));
				}
				check[i][j] = true;
				search(root->hashMap[id], i, j);
			}

			
		}
	}
	
	vector<string>tt;

	set<string>::iterator it= result.begin();
	for (; it != result.end(); it++)
	{
		tt.push_back(*it);
	}

	return tt;



}


void main()
{
	string dict[] = { "aa" };
	string word[] = { "aaa" };
	vector<char>list;
	vector<vector<char>>boards;
	vector<string>words;

	for (int i = 0; i < 1; i++)
	{
		list.clear();
		for (int j = 0; j < 2; j++)
			list.push_back(dict[i][j]); 

		boards.push_back(list);
	}
	for (int i = 0; i < 1; i++)
		words.push_back(word[i]);

	vector<string>tt = findWords(boards,words);
		
}