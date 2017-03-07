#include<iostream>
#include<map>
#include<queue>


using namespace std;

class LRUCache {
public:
	struct listNode
	{
		int key;
		int value;
		listNode*next;
		listNode*pre;
		listNode(int a, int b)
		{
			key = a;
			value = b;
			next = pre = NULL;
		}
	};

	int capacity,curCapacity=0;
	listNode*head = NULL, *tail = NULL;

	map<int, listNode*>key_Node;
	

	LRUCache(int capacity) 
	{
		this->capacity = capacity;
	}

	int get(int key) 
	{
		if (key_Node.size()==0||key_Node.count(key) == 0)
			return -1;
		else
		{
			listNode*cur = key_Node[key];
			if (cur == head)
				return cur->value;
			else
			{
				if (cur != tail)
				{
					cur->pre->next = cur->next;
					cur->next->pre = cur->pre;
					cur->next = head;
					head->pre = cur;
					cur->pre = NULL;
					head = cur;
				}
				else
				{
					tail = cur->pre;
					tail->next = NULL;
					cur->next = head;
					head->pre = cur;
					cur->pre = NULL;
					head = cur;
				}
				

				return cur->value;
			}
		}
	}

	void put(int key, int value) 
	{
		if (curCapacity < capacity)
		{
			if (key_Node.count(key) == 0)
			{
				curCapacity++;
				listNode*cur = new listNode(key,value);
				key_Node[key] = cur;
				if (head == NULL)
				{
					head = tail = cur;
				}
				else
				{
					cur->next = head;
					head->pre = cur;
					head = cur;
				}

			}
			else
			{
				listNode*cur = key_Node[key];
				cur->value = value;
				if (cur != head)
				{
					if (cur != tail)
					{
						cur->pre->next = cur->next;
						cur->next->pre = cur->pre;
						cur->next = head;
						head->pre = cur;
						cur->pre = NULL;
						head = cur;
					}
					else
					{
						listNode*node = tail;
						tail = tail->pre;
						tail->next = NULL;

						node->next = head;
						head->pre = node;
						node->pre = NULL;
						head = node;
					}
					
				}
			}
		}
		else
		{
			if (key_Node.count(key) == 0)
			{
				listNode*cur = new listNode(key,value);
				cur->next = head;
				head->pre = cur;
				head = cur;
				key_Node[key] = cur;
				key_Node.erase(tail->key);
				
				listNode*node = tail;
				tail = tail->pre;
				tail->next = NULL;
				delete node;
				node = NULL;

			}
			else
			{
				listNode*cur = key_Node[key];
				cur->value = value;
				if (cur != head)
				{
					if (cur != tail)
					{
						cur->pre->next = cur->next;
						cur->next->pre = cur->pre;
						cur->next = head;
						head->pre = cur;
						cur->pre = NULL;
						head = cur;
					}
					else
					{
						tail = cur->pre;
						tail->next = NULL;

						cur->next = head;
						head->pre = cur;
						cur->pre = NULL;
						head = cur;
					}

					
				}
			}
		}
	}
};

void main()
{
	LRUCache obj = LRUCache(2);
	obj.put(1,1);
	obj.put(2, 2);
	obj.get(1);
	obj.put(3,3);
	obj.get(2);
	obj.put(4,4);
	obj.get(1);
	obj.get(3);
	obj.get(4);
}