#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) 
	{
		
		if (root == NULL)return "[]";
		string result = "["+to_string(root->val);

		queue<TreeNode*>que;
		que.push(root);

		while (!que.empty())
		{
			int n = que.size();

			for (int i = 0; i < n; i++)
			{
				TreeNode*node = que.front();
				que.front();
				que.pop();

				if (node->left != NULL)
				{
					result += "," + to_string(node->left->val);
					que.push(node->left);
				}
				else
				{
					result += ",null";
				}

				if (node->right != NULL)
				{
					result += "," + to_string(node->right->val);
					que.push(node->right);
				}
				else
				{
					result += ",null";
				}
			}
		}

		result += "]";
		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) 
	{
		if (data.size() == 2)return NULL;

		data = data.substr(1);
		data = data.substr(0, data.size() - 1);
		data += ",";

		queue<string>que;
		int pre = 0;
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == ',')
			{
				string cur = data.substr(pre,i-pre);
				pre = i + 1;
				que.push(cur);
			}
		}

		TreeNode*root = new TreeNode(atoi(que.front().c_str()));
		que.pop();
		queue<TreeNode*>nodeQue;
		nodeQue.push(root);

		while (!que.empty()&&!nodeQue.empty())
		{
			TreeNode*curRoot = nodeQue.front();
			nodeQue.pop();

			string leftChild = que.front();
			que.pop();
			string rightChild = que.front();
			que.pop();

			if (leftChild == "null")
			{
				curRoot->left = NULL;
			}
			else
			{
				TreeNode*leftNode = new TreeNode(atoi(leftChild.c_str()));
				curRoot->left = leftNode;
				nodeQue.push(leftNode);
			}

			if (rightChild == "null")
			{
				curRoot->right = NULL;
			}
			else
			{
				TreeNode*rightNode = new TreeNode(atoi(rightChild.c_str()));
				curRoot->right = rightNode;
				nodeQue.push(rightNode);
			}


		}
		return root;


	}
};

int main()
{

	return 0;
}