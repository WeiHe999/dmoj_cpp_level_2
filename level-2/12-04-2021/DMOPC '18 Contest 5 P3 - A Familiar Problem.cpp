#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	long long n, m, best = 0, csum;
	vector <long long> vec1(200001);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> vec1[i];
	csum = vec1[0];
	for (int l = 0, r = 0; r < n; )
	{
		if (csum < m)
		{
		    if (r - l + 1 > best) best = r - l + 1;
			csum += vec1[++r];
		}
		else
		{
			csum -= vec1[l++];
			if (l > r) csum += vec1[++r];
		}
	}
    cout << best << endl;
}
