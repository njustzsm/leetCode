#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

map<TreeNode*, int>maxPath;

int GetRootMaxLength(TreeNode* root)
{
	if (root->left == NULL&&root->right == NULL)
	{
		maxPath[root] = root->val;
		return root->val;
	}

	if (root->left == NULL)
	{
		maxPath[root] =max( root->val + GetRootMaxLength(root->right),root->val);
		return maxPath[root];
	}
	if (root->right == NULL)
	{
		maxPath[root] =max(root->val + GetRootMaxLength(root->left),root->val);
		return maxPath[root];
	}

	maxPath[root] =max(root->val + max(GetRootMaxLength(root->right), GetRootMaxLength(root->left)),root->val);
	return maxPath[root];
}


int maxPathSum(TreeNode* root) 
{
	if (root == NULL)return 0;

	GetRootMaxLength(root);

	int result = INT_MIN;

	queue<TreeNode*>que;
	que.push(root);

	while (!que.empty())
	{
		TreeNode*curNode = que.front();
		que.pop();
		
		int curResult =curNode->val;
		
		if (curNode->left != NULL)
		{
			if (maxPath[curNode->left] > 0)
				curResult += maxPath[curNode->left];
			que.push(curNode->left);
		}
		if (curNode->right != NULL)
		{
			if (maxPath[curNode->right]>0)
				curResult += maxPath[curNode->right];
			que.push(curNode->right);
		}
		if (curResult > result)
			result = curResult;
	}
	return result;

}

void main()
{

}