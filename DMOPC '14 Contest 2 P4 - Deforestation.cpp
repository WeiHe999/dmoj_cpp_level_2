#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	int n, q, a, b, c, d;
	cin >> n;
	vector <int> vec1, vec2;
	cin >> c;
	vec1.emplace_back(c);
	vec2.emplace_back(c);
	for (int i = 1; i < n; i++)
	{
	    cin >> d;
		vec1.emplace_back(d);
		vec2.emplace_back(d + vec2[i - 1]);
	}
    cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;
		if (a == 0) cout << vec2[b] << endl;
	    else cout << vec2[b] - vec2[a - 1] << endl;
	}
}

