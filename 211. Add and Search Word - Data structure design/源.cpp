#include<iostream>
#include<string>


using namespace std;

class WordDictionary {
public:
	struct trieNode
	{
		trieNode*next[26];
		bool isExist;
	};

	trieNode*root;
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new trieNode();
		root->isExist = false;
		memset(root->next,0,sizeof(root->next));
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {

		trieNode*p = root;
		for (int i = 0; i < word.size(); i++)
		{
			int id = word[i] - 'a';

			if (p->next[id] == NULL)
			{
				p->next[id] = new trieNode();
				p->next[id]->isExist = false;
				memset(p->next[id]->next, 0, sizeof(p->next[id]->next));
			}
			p = p->next[id];
		}
		p->isExist = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */

	bool trieSearch(trieNode*root,string word)
	{
		if (word.size() == 0 && root->isExist)
			return true;

		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == '.')
			{
				string nextStr = word.substr(i+1);

				for (int j = 0; j < 26; j++)
				{
					if (root->next[j] && trieSearch(root->next[j], nextStr))
						return true;
				}
				return false;
			}
			else
			{
				int id = word[i] - 'a';
				if (root->next[id] == NULL)
					return false;
				else
					root = root->next[id];
			}
		}
		if (root->isExist)
			return true;
		return false;
	}


	bool search(string word) 
	{
		return trieSearch(root,word);
	}
};


void main()
{
	string word = "";
	WordDictionary*obj = new WordDictionary();
	obj->addWord(word);
	bool param_2 = obj->search(word);
}