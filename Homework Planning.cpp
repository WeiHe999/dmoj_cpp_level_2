#include <bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& arr, int k)
{
	vector<int> ans;
	priority_queue<pair<int, int> > heap;

	for (int i = 0; i < k; i++)
		heap.push({ arr[i], i });

	ans.push_back(heap.top().first);

	for (int i = k; i < arr.size(); i++) {

		heap.push({ arr[i], i });

		while (heap.top().second <= i - k)
			heap.pop();

		ans.push_back(heap.top().first);
	}

	return ans;
}

int main()
{
    int a, n, k;
    cin >> n >> k;
	vector<int> arr;
	for (int i=0; i<n; i++)
	{
	    cin >> a;
	    arr.push_back(a);
	    
	}

	vector<int> result = maxSlidingWindow(arr, k);

	for (auto i : result)
		cout << i << " ";

	return 0;
}
