#include<iostream>
#include<string>
#include<vector>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

vector<string> binaryTreePaths(TreeNode* root) 
{
	vector<string>result;

	if (root == NULL)return result;

	vector<string>left = binaryTreePaths(root->left);
	vector<string>right = binaryTreePaths(root->right);

	string a = to_string(root->val);

	for (int i = 0; i < left.size(); i++)
	{
		string cur = a + "->" + left[i];
		result.push_back(cur);
	}
	for (int i = 0; i < right.size(); i++)
	{
		string cur = a + "->" + right[i];
		result.push_back(cur);
	}

	if (result.empty())
		result.push_back(a);

	return result;
}
void main()
{

}