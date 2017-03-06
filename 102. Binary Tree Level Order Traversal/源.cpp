#include<iostream>
#include<queue>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) 
{
	
	vector<vector<int>>result;
	if (root == NULL)return result;


	queue<TreeNode*>cur;
	cur.push(root);
	vector<int>list;

	while (!cur.empty())
	{
		int n = cur.size();

		for (int i = 0; i < n; i++)
		{
			TreeNode*node = cur.front();
			cur.pop();

			list.push_back(node->val);
			if (node->left != NULL)
				cur.push(node->left);
			if (node->right != NULL)
				cur.push(node->right);
		}
		result.push_back(list);
		list.clear();
	}
	return result;


}
void main()
{

}