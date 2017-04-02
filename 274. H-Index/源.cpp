#include<iostream>
#include<vector>

using namespace std;

int result = 0,n=0;
vector<int>data;


void quickSort(int src,int dst)
{
	if (src > dst)return;

	int cur = data[src];

	int p = src, q = dst;


	while (p<q)
	{
		while (data[q] >= cur&&p<q)
		{
			q--;
		}

		while (data[p] <= cur&&p<q)
		{
			p++;
		}

		if (p < q)
		{
			data[p] += data[q];
			data[q] = data[p] - data[q];
			data[p] = data[p] - data[q];
		}
	}

	data[src] = data[p];
	data[p] = cur;

	if (n - p <= data[p] && n - p>result)
	{
		result = n - p;
	}

	quickSort(src,p-1);
	quickSort(p+1,dst);


}

int hIndex(vector<int>& citations)
{
	n = citations.size();
	data = citations;
	quickSort(0,n-1);

	return result;
}


void main()
{

}