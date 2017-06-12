#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int> res(k);
	unordered_map<int, int> cnt;

	for (auto n : nums) {
		cnt[n]++;
	}


	auto cmp = [](pair<int, int> p1, pair<int, int>p2){
		return p1.second > p2.second;
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (pq.size() < k) {
			pq.push(make_pair(it->first, it->second));

		}
		else{
			if (it->second > pq.top().second) {
				pq.pop();
				pq.push(make_pair(it->first, it->second));
			}
		}
	}


	
	for (int i = k - 1; i >= 0; i--) {
		res[i] = pq.top().first;
		pq.pop();
	}

	return res;
}
*/

bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first > b.first;
}

vector<int> topKFrequent(vector<int>& nums, int k) 
{
	map<int, int>countNum;
	vector<int>result;
	for (int i = 0; i < nums.size(); i++)
	{
		if (countNum.count(nums[i]) == 0)
		{
			countNum[nums[i]] = 0;
		}
		countNum[nums[i]]++;
	}

	vector<pair<int, int>>list;
	map<int, int>::iterator it = countNum.begin();

	while (it!=countNum.end())
	{
		pair<int, int>tt(it->second,it->first);
		list.push_back(tt);
		it++;
	}

	sort(list.begin(),list.end(),compare);

	for (int i = 0; i < k; i++)
	{
		result.push_back(list[i].second);
	}
	return result;

}


int main()
{
	vector<int>input({1, 1, 1, 2, 2, 3 });
	vector<int>result = topKFrequent(input,2);
	return 0;
}