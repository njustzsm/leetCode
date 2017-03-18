#include<iostream>
#include<algorithm>
using namespace std;


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	long long int A0 = A;
	long long int B0 = B;
	long long int C0 = C;
	long long int D0 =D;
	long long int E0 = E;
	long long int F0 = F;
	long long int G0 = G;
	long long int H0 = H;

	long long int areaA = (C0 - A0)*(D0 - B0);
	long long int areaB = (G0-E0)*(H0-F0);

	long long int width =(C0 - A0) + (G0 - E0) - (max(C0, G0) - min(A0, E0));
	long long int height =(D0 - B0) + (H0 - F0) - (max(D0,H0)-min(B0,F0));

	if (width > 0 && height > 0)
	{
		return areaA + areaB - width*height;
	}
	return areaA + areaB;

}

void main()
{

}