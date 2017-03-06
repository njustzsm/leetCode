#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};


RandomListNode *copyRandomList(RandomListNode *head) 
{
	if (head == NULL)return NULL;


	map<RandomListNode*, int>isCheck;
	map<int, RandomListNode*>isMap;


	RandomListNode*cur = head;
	int curNum = 0;

	while (cur!=NULL)
	{
		isCheck[cur] = curNum;
		RandomListNode*temp = new RandomListNode(cur->label);
		isMap[curNum] = temp;

		if (curNum != 0)
			isMap[curNum - 1]->next = isMap[curNum];

		cur = cur->next;
		curNum++;
	}
	
	cur = head;
	curNum = 0;
	while (cur!=NULL)
	{
		if (isCheck.count(cur->random) > 0)
		{
			int ramdon = isCheck[cur->random];
			isMap[curNum]->random = isMap[ramdon];

			
		}
		curNum++;
		cur = cur->next;
		
	}


	return isMap[0];
	
	
	


}




void main()
{

}