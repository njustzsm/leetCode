#include<iostream>

using namespace std;


struct TrieNode
{
	int count;
	TrieNode*next[26];
	bool exist;
};

TrieNode*creatTrieNode()
{
	TrieNode*node = (TrieNode*)malloc(sizeof(TrieNode));
	node->count = 0;
	node->exist = false;
	memset(node->next,0,sizeof(node->next));
	return node;
}

void Trie_Insert(TrieNode root,char*word)
{
	TrieNode node = root;
	char*p = word;
	int id;
	while (*p)
	{
		id = *p - 'a';
		if (node.next[id] == NULL)
		{
			node.next[id] = creatTrieNode();
		}
		node =*node.next[id];
		p++;
		node.count++;
	}

	node.exist = true;
}

int Trie_Search(TrieNode root, char*word)
{
	TrieNode node = root;
	char*p = word;
	int id;
	while (*p)
	{
		id = *p - 'a';
		if (root.next[id] == NULL)
			return 0;

		node = *node.next[id];
		p++;
	}
	return node.count;
}



void main()
{

}