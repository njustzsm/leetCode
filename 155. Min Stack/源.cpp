#include<iostream>
#include<vector>


using namespace std;

class MinStack {
public:
	
	int curMin=INT_MAX;
	vector<int>data;
	vector<int>minValue;

	MinStack() {

	}

	void push(int x) {
		data.push_back(x);

		if (curMin > x)
			curMin = x;
		minValue.push_back(curMin);

	}

	void pop() {
		data.pop_back();

		minValue.pop_back();

		if (minValue.empty())
		{
			curMin = INT_MAX;
		}
		else
		{
			curMin = minValue[minValue.size()-1];
		}

	}

	int top() {
		if (!data.empty())
			return data[data.size()-1];
		return 0;
	}

	int getMin() {
		return curMin;
	}
};

void main()
{

}