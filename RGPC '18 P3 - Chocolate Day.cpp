#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, t, ba, bb, bc, best = -1, lv;
	vector <long long> pfx(1000010);
	cin >> n >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> ba >> bb >> bc;
		pfx[ba] += bc;
		pfx[bb + 1] -= bc;
	}
	for(int i = 1; i <= n; i++) pfx[i] += pfx[i - 1];
	for(int i = 1; i <= n; i++) pfx[i] += pfx[i - 1];
	cin >> lv;
	int l = 1, r = 0;
	while (r <= n)
	{
		long long sum = pfx[r] - pfx[l - 1];
		if (sum <= lv)
		{
		    if (r - l + 1 > best) best = r - l + 1;
			r++;
		}
		else l++;
	}
    cout << best << endl;
}
