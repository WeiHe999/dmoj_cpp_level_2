#include <bits/stdc++.h>
using namespace std;

int results(int x, int a1, int a2, int b1, int b2)
{
	if (a1 <= x && x <= a2) x = a1 + a2 - x;
	if (b1 <= x && x <= b2) x = b1 + b2 - x;
	return x;
}
 
int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a1, a2, b1, b2, k1, p, cur, res[101];
	cin >> n >> k >> a1 >> a2 >> b1 >> b2;
	for (int i = 1; i <= n; i++)
	{
		p = 1;
		cur = results(i, a1, a2, b1, b2);
		while (cur != i)
		{
			p++;
			cur = results(cur, a1, a2, b1, b2);
		}
		int k1 = k % p;
		for (int j = 0; j < k1; ++j) cur = results(cur, a1, a2, b1, b2);
		res[cur] = i;
	}
	for (int i = 1; i <= n; i++) cout << res[i] << endl;
}
