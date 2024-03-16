#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b, c;
	cin >> n >> q;
	vector <int> vec1(n), vec2(n);
	for (int i = 0; i < n; i++) cin >> vec1[i];
	for(int i = 0; i < n; i++)
	{
		cin >> vec2[i];
		vec1[i] -= vec2[i];
	}
    sort(vec1.begin(), vec1.end());
	for (int i = 0; i < q; i++)
	{
	    cin >> a >> b;
		c = n - (lower_bound(vec1.begin(), vec1.end(), b + 1) - vec1.begin());
		if (c >= a) cout << "YES\n";
		else cout << "NO\n";
	}
}
