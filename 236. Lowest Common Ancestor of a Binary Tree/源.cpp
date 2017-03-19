#include<iostream>
#include<queue>
#include<map>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (root == NULL || p == NULL || q == NULL)return NULL;
	if (p == q)return p;

	queue<TreeNode*>que;
	map<TreeNode*, TreeNode*>child_father;

	child_father[root] = NULL;

	que.push(root);

	while (!que.empty())
	{
		TreeNode*father = que.front();
		que.pop();

		if (father->left != NULL)
		{
			child_father[father->left] = father;
			que.push(father->left);
		}
		if (father->right != NULL)
		{
			child_father[father->right] = father;
			que.push(father->right);
		}

	}
	
	stack<TreeNode*>path1, path2;

	TreeNode*pp = p;

	while (pp!=NULL)
	{
		path1.push(pp);
		pp = child_father[pp];
	}
	pp = q;
	while (pp!=NULL)
	{
		path2.push(pp);
		pp = child_father[pp];
	}
	TreeNode*result = NULL;

	while (!path1.empty()&&!path2.empty())
	{
		if (path1.top() == path2.top())
		{
			result = path1.top();
			path1.pop();
			path2.pop();
		}
		else
			break;
	}
	return result;



}
void main()
{
	TreeNode*node1 = new TreeNode(1);
	TreeNode*node2 = new TreeNode(2);
	node2->left = node1;

	TreeNode*result=lowestCommonAncestor(node2, node1, node2);

}