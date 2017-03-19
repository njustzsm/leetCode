#include<iostream>
#include<stack>


using namespace std;


class MyQueue {
public:
	/** Initialize your data structure here. */

	stack<int>stack1, stack2;

	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */

	int pop() {
		if (!stack2.empty())
		{
			int result = stack2.top();
			stack2.pop();
			return result;
		}
		
		while (!stack1.empty())
		{
			int cur = stack1.top();
			stack1.pop();
			stack2.push(cur);
		}
		return pop();
	

		
	}

	/** Get the front element. */
	int peek() {
		if (!stack2.empty())
		{
			int result = stack2.top();
			return result;
		}
		while (!stack1.empty())
		{
			int cur = stack1.top();
			stack1.pop();
			stack2.push(cur);
		}
		return peek();
		

		
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack1.empty() && stack2.empty();
	}
};


void main()
{

}