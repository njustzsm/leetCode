#include<iostream>
#include<queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (root == NULL||p==NULL||q==NULL)return NULL;

	if (p == q)return p;

	TreeNode*nodep = root;
	queue<TreeNode*>quep;

	while (nodep!=NULL&&nodep->val!=p->val)
	{
		quep.push(nodep);
		if (nodep->val < p->val)
			nodep = nodep->right;
		else
			nodep = nodep->left;
	}

	if (nodep == NULL)return NULL;
	else
		quep.push(p);

	TreeNode*nodeq = root;
	queue<TreeNode*>queq;

	while (nodeq!=NULL&&nodeq->val!=q->val)
	{
		queq.push(nodeq);
		if (nodeq->val < q->val)
			nodeq = nodeq->right;
		else
			nodeq = nodeq->left;
	}
	if (nodeq == NULL)return NULL;
	else
		queq.push(q);


	TreeNode*result = NULL;
	while (!quep.empty()&&!queq.empty())
	{
		if (quep.front() == queq.front())
		{
			result = quep.front();
			quep.pop();
			queq.pop();
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
	TreeNode*node3 = new TreeNode(3);
	node2->left = node1;
	node2->right = node3;
	TreeNode*result = lowestCommonAncestor(node2,node1,node3);
}
