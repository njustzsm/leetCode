#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */

	queue<int>que1,que2;

	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {

		if (que1.empty() && que2.empty())
		{
			que1.push(x);
		}
		else if (!que1.empty())
		{
			que1.push(x);
		}
		else
		{
			que2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{

		if (que1.empty() && que2.empty())
		{
			return 0;
		}
		else if (!que1.empty())
		{
			int tt = 0;
			while (que1.size()>1)
			{
				tt = que1.front();
				que1.pop();
				que2.push(tt);
			}

			tt = que1.front();
			que1.pop();
			return tt;
		}
		else
		{
			int tt = 0;
			while (que2.size()>1)
			{
				tt = que2.front();
				que2.pop();
				que1.push(tt);
			}

			tt = que2.front();
			que2.pop();
			return tt;
		}
	}

	/** Get the top element. */
	int top() {
		if (que1.empty() && que2.empty())
		{
			return 0;
		}
		else if (!que1.empty())
		{
			int tt = 0;
			while (!que1.empty())
			{
				tt = que1.front();
				que1.pop();
				que2.push(tt);

			}
			return tt;
		}
		else
		{
			int tt = 0;
			while (!que2.empty())
			{
				tt = que2.front();
				que2.pop();
				que1.push(tt);

			}
			return tt;
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return que1.empty() && que2.empty();
	}
};


void main()
{

}