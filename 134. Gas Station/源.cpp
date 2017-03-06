#include<vector>
#include<algorithm>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	if (gas.size() <= 0)return -1;
	if (gas.size() == 1)
	{
		if (gas[0] >= cost[0])return 0;
		return -1;
	}

	int gasSum = 0, costSum = 0;
	int m = gas.size();

	int p = 0, q =0;

	gasSum = 0;
	costSum = 0;

	while (p<m)
	{
		if (gasSum + gas[q] >= costSum + cost[q])
		{
			gasSum +=gas[q]; 
			costSum += cost[q];
			q = q + 1;
			if (q == m)q = 0;

			if (p == q&&gasSum != 0)
				return p;
		}
		else
		{
			if (gasSum != 0)
			{
				gasSum -= gas[p];
				costSum -= cost[p];
				p++;
			}
			else
			{
				p++;
				q++;
				if (q == m)
					q = 0;
			}
		}
	}

	return -1;




	


}

void main()
{
	vector<int>gas, cost;
	gas.push_back(2); gas.push_back(4);
	cost.push_back(3); cost.push_back(4);
	canCompleteCircuit(gas,cost);
}