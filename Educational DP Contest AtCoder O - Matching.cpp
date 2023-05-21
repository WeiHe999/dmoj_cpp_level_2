#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	int n, num;
	cin >> n;
	vector <vector <int> > vec1(n + 1, vector <int>(n + 1));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> vec1[i][j];
	vector <int> dp((1 << n) + 1);
	dp[1] = 1;
	for (int i = 0; i < (1 << n); i++)
	{
		num = __builtin_popcount(i);
		for (int j = 0; j < n; j++)
		{
		    if (!(i & (1 << j)) && vec1[num + 1][j + 1]) dp[(i | (1 << j)) + 1] = (dp[(i | (1 << j)) + 1] + dp[i + 1]) % int(1e9 + 7);
		}
	}
	cout << dp[(1 << n)] << "\n";
}
