#include<iostream>

using namespace std;

bool isBadVersion(int version)
{
	if (version >= 1702766719)
		return true;
	return false;
}


int firstBadVersion(int n)
{
	long long int p = 1, q = n;

	while (p<q)
	{
		long long int mid = (p + q) / 2;

		if (isBadVersion(mid))
		{
			if (mid == 1 || !isBadVersion(mid - 1))return mid;

			q = mid - 1;

		}
		else
			p = mid + 1;
	}
	return p;


}
void main()
{
	int a = 2126753390;
	int result = firstBadVersion(a);
}