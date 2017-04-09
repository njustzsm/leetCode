#include<iostream>
#include<vector>
#include<map>
using namespace std;


//用线段树实现
class NumArray {
public:
	struct TreeNode
	{
		int left;
		int right;
		int sum;
		TreeNode*leftChild;
		TreeNode*rightChild;

		TreeNode(int a, int b, int c) :left(a), right(b), sum(c)
		{
			leftChild = rightChild = NULL;
		}

	};

	vector<int>data;
	TreeNode*root;
	TreeNode*CreateTree(int left, int right)
	{
		if (left > right)return NULL;
		if (left == right)
		{
			TreeNode*newNode = new TreeNode(left, right, data[left]);
			return newNode;
		}

		int mid = (left + right) / 2;

		TreeNode*curNode = new TreeNode(left, right, 0);

		TreeNode*leftNode = CreateTree(left, mid);
		TreeNode*rightNode = CreateTree(mid + 1, right);

		curNode->leftChild = leftNode;
		curNode->rightChild = rightNode;
		curNode->sum = leftNode->sum + rightNode->sum;
		return curNode;
	}


	NumArray(vector<int> nums) {
		data = nums;
		root = CreateTree(0,data.size()-1);
	}

	void Update(TreeNode*cur, int index, int val)
	{
		if (cur->left <= index&&cur->right >= index)
		{
			cur->sum += -data[index] + val;

			int mid = (cur->left + cur->right) / 2;

			if (mid >= index&&cur->leftChild!=NULL)
				Update(cur->leftChild, index, val);
			else if (mid <index&&cur->rightChild != NULL)
				Update(cur->rightChild,index,val);
		}
	}

	void update(int i, int val) 
	{
		Update(root,i,val);
		data[i] = val;
	}

	int findRange(TreeNode*cur,int i,int j)
	{
		if (i > j)return 0;
		if (cur->left == i&&cur->right == j)
			return cur->sum;

		int mid = (cur->left + cur->right) / 2;

		if (mid >= j)
			return findRange(cur->leftChild,i,j);
		else if (mid < i)
		{
			return findRange(cur->rightChild, i, j);
		}
		else
			return findRange(cur->leftChild, i, mid) + findRange(cur->rightChild, mid + 1, j);
	}


	int sumRange(int i, int j) {
		return findRange(root,i,j);
	}
};

int main()
{
	vector<int>data = {1,3,5};
	NumArray tool(data);

	cout<<tool.sumRange(0,2)<<endl;
	tool.update(1,2);
	cout<<tool.sumRange(0,2)<<endl;
	
	return 0;
}