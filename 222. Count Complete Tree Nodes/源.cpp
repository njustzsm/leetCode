#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool isLeaf(TreeNode* root,int num, int length)
{
	int target = pow(2,length-1);
	
	TreeNode*p = root;

	for (int i = 0; i < length; i++)
	{
		if (num&target)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}

		target= target>>1;
		if (p == NULL)
			return false;
	}
	return true;
}

int countNodes(TreeNode* root) 
{
	int result = 0;
	if (root == NULL)return result;

	int h = 0;
	
	TreeNode*p = root;
	while (p != NULL)
	{
		h++;
		p = p->left;
	}

	if (h == 1)return 1;

	result = pow(2, h-1) - 1;


	int maxValue = pow(2,h-1)-1;

	

	int left = 0, right = maxValue;

	while (left<right)
	{
		int mid = (left + right) / 2;
		if (isLeaf(root, mid, h - 1))
		{
			left = mid + 1;
		}
		else
		{
			if (isLeaf(root, mid - 1, h - 1))
			{
				left = right = mid - 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}


	if (isLeaf(root,left,h-1))
	{
		result += left + 1;
	}
	else
		result += left;

	return result;
	
	
}
void main()
{
	TreeNode*data[501];
	for (int i = 1; i <= 500; i++)
	{
		data[i] = new TreeNode(i);
	}

	for (int i = 500 / 2; i >= 1; i--)
	{
		data[i]->left = data[i * 2];
		if (i * 2 + 1 <= 500)
		{
			data[i]->right = data[i * 2 + 1];
		}
	}

	int result = countNodes(data[1]);
}