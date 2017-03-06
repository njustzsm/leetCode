#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int candy1(vector<int>& ratings)
{
	if (ratings.size() <= 1)return ratings.size();
	int m = ratings.size();

	vector<int>candyNum(m,1);

	for (int i = 1; i < m; i++)
	{
		if (ratings[i]>ratings[i - 1])
			candyNum[i] = candyNum[i - 1] + 1;
	}
	for (int i = m - 2; i >= 0; i--)
	{
		if (ratings[i] > ratings[i + 1])
		{
			candyNum[i] = max(candyNum[i],candyNum[i+1]+1);
		}
	}

	int result = 0;
	for (int i = 0; i < m; i++)
	{
		result += candyNum[i];
	}
	return result;



}

//³¬Ê±ÁË
int candy(vector<int>& ratings) 
{
	if (ratings.size() <=1)return ratings.size();

	int m = ratings.size();

	vector<int>candyNum(m,1);

	for (int i = 1; i < m; i++)
	{
		if (ratings[i]>ratings[i - 1])
		{
			candyNum[i] = candyNum[i - 1] + 1;
		}
		else if (ratings[i] == ratings[i - 1])
		{
			candyNum[i] = 1;
		}
		else if (ratings[i]<ratings[i - 1])
		{
			if (candyNum[i - 1] != 1)
				candyNum[i] = 1;
			else
			{
				candyNum[i] = 1;
				candyNum[i - 1] = 2;

				int cur = i - 1;

				while (cur-1>=0)
				{
					if (candyNum[cur] < candyNum[cur - 1]||ratings[cur]==ratings[cur-1])
						break;
					else if (candyNum[cur] == candyNum[cur - 1])
					{
						candyNum[cur - 1]++;
					}
					cur--;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < m; i++)
	{
		result += candyNum[i];
	}

	return result;
	


}

void main()
{
	vector<int>rating;
	rating.push_back(2);
	rating.push_back(1);
	int result = candy(rating);
}