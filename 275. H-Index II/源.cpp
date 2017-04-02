#include<iostream>
#include<vector>

using namespace std;




int hIndex(vector<int>& citations) 
{
	int n = citations.size();
	if (n == 0)return 0;
	int result= 0;

	int p = 0,q=n-1;

	while (p<q)
	{
		int mid = (p + q) / 2;

		if (n - mid <= citations[mid])
		{
			q = mid;
		}
		else
			p = mid + 1;
	}

	if (n - q <= citations[q])
		return n-q;
	return n-q - 1;


}
void main()
{

}