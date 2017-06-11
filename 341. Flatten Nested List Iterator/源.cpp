#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class NestedInteger {
	public:
		    // Return true if this NestedInteger holds a single integer, rather than a nested list.
			    bool isInteger() const;
		
			     // Return the single integer that this NestedInteger holds, if it holds a single integer
			     // The result is undefined if this NestedInteger holds a nested list
			     int getInteger() const;
		
			    // Return the nested list that this NestedInteger holds, if it holds a nested list
		     // The result is undefined if this NestedInteger holds a single integer
			     const vector<NestedInteger> &getList() const;
		
};

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = 0; i < nestedList.size(); i++)
		{
			NestedInteger it = nestedList[i];
			
			flat(it);
		}
	}

	void flat(NestedInteger it)
	{
		if (it.isInteger())
		{
			int tt = it.getInteger();
			que.push(tt);
		}
		else
		{
			const vector<NestedInteger>& tmp = it.getList();

			for (int i = 0; i < tmp.size(); i++)
			{
				flat(tmp[i]);
			}
		}
	}

	int next() {
		int result = que.front();
		que.pop();
		return result;
	}

	bool hasNext() {
		return !que.empty();
	}
private:
	queue<int>que;
};

int main()
{
	return 0;
}