#include<iostream>
#include<vector>

using namespace std;


bool isSelfCrossing(vector<int>& x)
{
	if (x.size() < 4)
		return false;
	int north = x[0];
	int west = x[1];
	int south = x[2];
	int east = x[3];

	if (south > north||west>east)
		return false;
	
	return true;

}



int main()
{
	return 0;
}