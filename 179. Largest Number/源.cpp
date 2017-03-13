#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int getDigit(int data)
{
	if (data == 0)return 1;
	int result = 0;

	while (data>0)
	{
		result++;
		data /= 10;
	}
	return result;
}

bool compare(int a, int b)
{
	int lengtha = getDigit(a);
	int lengthb = getDigit(b);

	long long int t1 = a,t2=b;
	
	for (int i = 0; i < lengthb; i++)
	{
		t1 *= 10;
	}
	t1 +=b;
	for (int i = 0; i < lengtha; i++)
	{
		t2 *=10;
	}
	t2 += a;

	if (t1>t2)
	{
		return true;
	}
	return false;
	

}

string largestNumber(vector<int>& nums) 
{
	sort(nums.begin(),nums.end(),compare);
	string result = "";

	if (nums[0] == 0)return "0";

	for (int i = 0; i < nums.size(); i++)
	{
		result += to_string(nums[i]);
	}
	return result;
}


void main()
{
	int numbers[] = { 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	int num = sizeof(numbers) / sizeof(int);

	vector<int>data;
	for (int i = 0; i < num; i++)
	{
		data.push_back(numbers[i]);
	}

	string result = largestNumber(data);
	cout << result << endl;
}