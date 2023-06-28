#include <bits/stdc++.h>
using namespace std;


int func(vector<int> arr, int n)
{

	int max = 1, len = 1;
	
	for (int i=1; i<n; i++)
	{

		if (arr[i] <= arr[i-1])
			len++;
		else
		{

			if (max < len)
				max = len;

			len = 1;
		}
	}

	if (max < len)
		max = len;
	
	return max;
}

int main()
{
	int n, a;
	cin >> n;
	vector<int> v1;
	for (int i=0; i<n; i++)
	{
	    cin >> a;
	    v1.push_back(a);
	}
	cout << func(v1, n) << endl;
}
