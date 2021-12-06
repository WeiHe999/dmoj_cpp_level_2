#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	long long n, m, l = 0, r = 0, s, minl = INT_MAX;
	vector <long long> vec1(500000);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> vec1[i];
	for (int i = 1; i < n; i++) vec1[i] += vec1[i - 1];
	for (; r < n; )
	{
	    if (l > 0) s = vec1[r] - vec1[l - 1];
	    else s = vec1[r];
		if (s >= m)
		{
			minl = min(minl, r - l + 1);
			l++;
		}
		else r++;
	}
	if (minl == INT_MAX) cout << -1;
    else cout << minl << endl;
}
