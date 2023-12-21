#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a;
    vector <int> vec1(5000001);
    vector <bool> comp(5000001, false);
    vector <int> maximum = {2, 1, 2, 3};
    vec1[1] = 1;
	for (int i = 2; i <= 5000000; i++)
	{
		if (!comp[i])
		{
			for (int j = i; j < 5000000; j += i) comp[j] = true;
			maximum[i % 4] = i;
		}
		vec1[i] = (i - maximum[i % 4]) / 2 + 1;
	}
    cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		int s = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (vec1[a] / 2 < s / 2) s = vec1[a];
		}
		if (s % 2 == 1) cout << "Farmer John\n";
		else cout << "Farmer Nhoj\n";
	}
}
