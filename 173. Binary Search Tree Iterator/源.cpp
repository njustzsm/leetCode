#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class BSTIterator {
public:

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		
	};

	
	TreeNode*cur ;
	stack<TreeNode*>curStack;

	BSTIterator(TreeNode *root) {
		cur = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (!curStack.empty() || cur != NULL)
			return true;
		return false;
	}

	/** @return the next smallest number */
	int next() {

		while (cur!=NULL)
		{
			curStack.push(cur);
			cur = cur->left;
		}

		if (!curStack.empty())
		{
			TreeNode*node= curStack.top();
			curStack.pop();
			if (node->right != NULL)cur = node->right;
			return node->val;
		}





	}
};

void main()
{

}