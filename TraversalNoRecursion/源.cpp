#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int>preOrder(TreeNode*root)
{
	vector<int>result;
	stack<TreeNode*>sta;
	TreeNode*p = root;

	while (!sta.empty()||p!=NULL)
	{
		while (p !=NULL)
		{
			sta.push(p);
			result.push_back(p->val);
			p = p->left;
		}
		
		if (!sta.empty())
		{
			TreeNode*cur = sta.top();
			sta.pop();
			p = cur->right;
		}
	}
	return result;


}

vector<int>inOrder(TreeNode*root)
{
	vector<int>result;

	stack<TreeNode*>sta;


	
	TreeNode*p = root;

	while (!sta.empty()||p!=NULL)
	{
		while (p!=NULL)
		{
			sta.push(p);
			p = p->left;
		}

		if (!sta.empty())
		{
			TreeNode*cur = sta.top();
			sta.pop();
			result.push_back(cur->val);
			p = cur->right;
		}


	}



	return result;
}

vector<int>postPrder(TreeNode*root)
{
	vector<int>result;

	TreeNode*pre = NULL;

	stack<TreeNode*>sta;

	sta.push(root);

	while (!sta.empty())
	{
		TreeNode*node = sta.top();

		if ((node->left == NULL&&node->right == NULL) || (pre != NULL && (pre == node->left || pre == node->right)))
		{
			pre = node;
			result.push_back(node->val);
			sta.pop();
		}
		else
		{
			if (node->right != NULL)
			{
				sta.push(node->right);
			}
			if (node->left != NULL)
			{
				sta.push(node->left);
			}
		}
	}
	return result;
}

void Print(vector<int>data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void main()
{
	TreeNode* nodes[16];
	for (int i = 1; i <= 15; i++)
	{
		nodes[i] = new TreeNode(i);
	}

	for (int i = 1; i <=15 / 2; i++)
	{
		nodes[i]->left = nodes[i * 2];
		nodes[i]->right = nodes[i * 2 + 1];
	}

	vector<int>preResult = preOrder(nodes[1]);
	vector<int>inResult = inOrder(nodes[1]);
	vector<int>postResult = postPrder(nodes[1]);
	Print(preResult);
	Print(inResult);
	Print(postResult);
}