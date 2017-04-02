#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator 
{
public:
	bool isValid;
	int peekNumber;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
	{
		

		isValid=false;
		peekNumber=0;
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() 
	{
		if (isValid)
			return peekNumber;
		else
		{
			peekNumber = next();
			isValid = true;
			return peekNumber;
		}
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
	{
		if (isValid)
		{
			isValid = false;
			return peekNumber;
		}
		else
		{
			return Iterator::next();
		}
	}

	bool hasNext() const 
	{
		if (isValid)
			return true;
		else
			return Iterator::hasNext();
	}
};


int main()
{
	return 0;
}