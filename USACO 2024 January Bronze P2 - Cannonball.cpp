#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	int n, x, a, b;
	cin >> n >> x;
	vector <pair <int, int> > vec1(n + 1);
	vector <bool> vis(n + 1);
	for (int i = 1; i <= n; i++)
	{
	    cin >> a >> b;
	    vec1[i] = {a, b};
	}
	int d = 1, p = 1, s = 0;
	for (int i = 0; i < 5000000; i++)
	{
	    if (x < 1 || x > n) break;
		if (vec1[x].first == 1 && p >= vec1[x].second && !vis[x])
		{
			vis[x] = true;
			s++;
		}
		if (vec1[x].first == 0)
		{
			d = -d;
			p += vec1[x].second;
		}
		x += d * p;
	}
	cout << s << "\n";
}
