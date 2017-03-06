#include<iostream>
#include<queue>

using namespace std;

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};


void connect(TreeLinkNode *root) 
{
	if (root == NULL)return;

	queue<TreeLinkNode*>que;

	que.push(root);

	while (!que.empty())
	{
		int n = que.size();

		TreeLinkNode*preNode = NULL;

		for (int i = 0; i < n; i++)
		{
			TreeLinkNode*curNode = que.front();
			que.pop();

			if (curNode->left != NULL)que.push(curNode->left);
			if (curNode->right != NULL)que.push(curNode->right);

			

			if (preNode == NULL)
			{
				preNode = curNode;
			}
			else
			{
				preNode->next = curNode;
				preNode = curNode;
			}
		}
		preNode->next = NULL;
	}


}

void main()
{

}