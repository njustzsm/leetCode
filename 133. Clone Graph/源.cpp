#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	
};
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
{
	if (node == NULL)return NULL;

	UndirectedGraphNode*root = new UndirectedGraphNode(node->label);
	
	map<UndirectedGraphNode*, int>check;

	map<int, UndirectedGraphNode*>countN;
	queue<UndirectedGraphNode*>que;

	que.push(node);

	countN[root->label] = root;
	check[node] = 1;


	while (!que.empty())
	{
		UndirectedGraphNode*curNode = que.front();
		que.pop();

		for (int i = 0; i < curNode->neighbors.size(); i++)
		{
			int label = curNode->neighbors[i]->label;
			if (countN.count(label) == 0)
			{
				UndirectedGraphNode*tempNode = new UndirectedGraphNode(label);
				countN[label] = tempNode;
			}

			countN[curNode->label]->neighbors.push_back(countN[label]);

			if (check.count(curNode->neighbors[i]) == 0)
			{
				que.push(curNode->neighbors[i]);
				check[curNode->neighbors[i]] = 1;
			}

		}

	}


	return countN[node->label];







}
void main()
{

}