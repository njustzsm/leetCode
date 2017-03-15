#include<iostream>
#include<string>
using namespace std;


class Trie {
public:
	/** Initialize your data structure here. */


	int count;
	Trie*next[26];
	bool exist;
	


	Trie() 
	{
		count = 0;
		exist = false;
		memset(next,0,26*sizeof(Trie*));
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie*p = this;

		for (int i = 0; i < word.size(); i++)
		{
			int id = word[i] - 'a';
			if (p->next[id] == NULL)
			{
				p->next[id] = new Trie();
			}

			p = p->next[id];
			p->count++;
		}
		p->exist = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {

		Trie*p = this;
		for (int i = 0; i < word.size(); i++)
		{
			int id = word[i] - 'a';

			if (p->next[id] == NULL)
				return false;
			else
			{
				p = p->next[id];
			}
		}
		return p->exist;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie*p = this;

		for (int i = 0; i < prefix.size(); i++)
		{
			int id = prefix[i] - 'a';
			if (p->next[id] == NULL)
				return false;
			else
				p = p->next[id];
		}
		if (p->count>0)
			return true;
		return false;

	}
};

void main()
{
	string word = "hello world";
	string prefix = "hello";
	Trie* obj = new Trie();
	obj->insert(word);
	bool param_2 = obj->search(word);
	bool param_3 = obj->startsWith(prefix);
}