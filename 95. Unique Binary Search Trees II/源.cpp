#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


vector<TreeNode*>result;


void InputTreeNode(TreeNode**root,int value)
{
	if (*root == NULL)
	{
		*root = new TreeNode(value);
		return;
	}
	else
	{
		if ((*root)->val < value)
		{
			InputTreeNode(&((*root)->right), value);
		}
		else
		{
			InputTreeNode(&((*root)->left), value);
		}
	}
}

int*data;
bool*check;
void dfs(int cur,int n)
{
	if (cur == n+1)
	{
		TreeNode*root = NULL;
		for (int i = 1; i <= n; i++)
		{
			InputTreeNode(&root,data[i]);
		}
		result.push_back(root);
		return;
	}


	for (int i = 1; i <=n; i++)
	{
		if (!check[i])
		{
			data[cur] = i;
			check[i] = true;
			dfs(cur+1,n);
			check[i] = false;
		}
	}
}

bool isEqual(TreeNode*a,TreeNode*b)
{
	if (a == NULL&&b != NULL)return false;
	if (a != NULL&&b == NULL)return false;
	if (a == NULL&&b == NULL)return true;
	if (a->val != b->val)return false;
	return isEqual(a->left, b->left) && isEqual(a->right, b->right);
}

vector<TreeNode*> generateTrees(int n) 
{
	if (n == 0)return result;
	data = new int[n+1];
	check = new bool[n + 1];
	memset(data, 0,(n+1)*sizeof(int));
	memset(check, false, (n + 1)*sizeof(bool));

	dfs(1,n);

	vector<TreeNode*>tt;

	for (int i = 0; i < result.size(); i++)
	{
		if (i == 0)
		{
			tt.push_back(result[i]);
		}
		else
		{
			bool isPush = true;
			TreeNode*cur = result[i];
			for (int j = 0; j < tt.size(); j++)
			{
				if (isEqual(cur,tt[j]))
				{
					isPush = false;
					break;
				}
			}
			if (isPush)
			tt.push_back(cur);
		}
	}

	return tt;
}

vector<TreeNode *> Helper(int begin, int end)
{
	vector<TreeNode*>ret;
	
	if (begin > end)
		ret.push_back(NULL);
	else if (begin==end)
	{
		TreeNode*node = new TreeNode(begin);
		ret.push_back(node);
	}
	else
	{
		for (int i = begin; i <= end; i++)
		{
			vector<TreeNode*>leftChild = Helper(begin,i-1);
			vector<TreeNode*>rightChild = Helper(i+1,end);

			for (int j = 0; j < leftChild.size(); j++)
			{
				for (int k = 0; k < rightChild.size(); k++)
				{
					TreeNode*rootNode = new TreeNode(i);
					rootNode->left = leftChild[j];
					rootNode->right = rightChild[k];
					ret.push_back(rootNode);
				}
			}
		}
	}

	return ret;
}

vector<TreeNode*> TgenerateTrees(int n)
{
	if (n == 0)
	{
		vector<TreeNode*>result;
		return result;
	}
	return Helper(1,n);
}

void main()
{

}