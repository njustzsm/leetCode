#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};



map<TreeNode*, int>trueNum;
map<TreeNode*, int>falseNum;

int Robmax(TreeNode*root,bool robParent)
{
	if (root == NULL)
		return 0;

	if (robParent)
	{
		int value1, value2;
		if (falseNum.count(root->left) == 0)
		{
			value1 = Robmax(root->left, false);
			falseNum[root->left] = value1;
		}
		else
			value1=falseNum[root->left];

		if (falseNum.count(root->right) == 0)
		{
			value2 = Robmax(root->right, false);
			falseNum[root->right] = value2;
		}
		else
		{
			value2=falseNum[root->right];
		}

		return value1+value2;
	}
	else
	{
		int leftFalse, rightFalse, leftTrue, rightTrue;
		if (falseNum.count(root->left) == 0)
		{
			leftFalse = Robmax(root->left, false);
			falseNum[root->left] =leftFalse;
		}
		else
		{
			leftFalse = falseNum[root->left];
		}

		if (falseNum.count(root->right) == 0)
		{
			rightFalse = Robmax(root->right, false);
			falseNum[root->right] = rightFalse;
		}
		else
		{
			rightFalse = falseNum[root->right];
		}

		if (trueNum.count(root->left) == 0)
		{
			leftTrue = Robmax(root->left, true);
			trueNum[root->left] = leftTrue;
		}
		else
		{
			leftTrue = trueNum[root->left];
		}

		if (trueNum.count(root->right) == 0)
		{
			rightTrue = Robmax(root->right, true);
			trueNum[root->right] = rightTrue;
		}
		else
		{
			rightTrue = trueNum[root->right];
		}



		//int value1 = Robmax(root->left, false) + Robmax(root->right, false);
		//int value2 = root->val + Robmax(root->left, true) + Robmax(root->right, true);

		return max(leftFalse+rightFalse,root->val+leftTrue+rightTrue);
	}


}
int rob(TreeNode* root) 
{
	bool robParent = false;

	return Robmax(root,robParent);
}


int main()
{
	return 0;
}