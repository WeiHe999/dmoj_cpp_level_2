#include <bits/stdc++.h>
using namespace std;

int rec(int a, int b, int c, int d, vector <vector <int> > &vec1, vector <vector <vector <vector <int> > > > &dp)
{
	if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
	if (a == c && b == d) return 0;
	int maxa = 1e9;
	for (int i = 1; i <= d - b; i++) maxa = min(maxa, rec(a, b, c, b + i - 1, vec1, dp) + rec(a, b + i, c, d, vec1, dp));
	for (int i = 1; i <= c - a; i++) maxa = min(maxa, rec(a, b, a + i - 1, d, vec1, dp) + rec(a + i, b, c, d, vec1, dp));
	return dp[a][b][c][d] = maxa + vec1[c][d] - vec1[a - 1][d] - vec1[c][b - 1] + vec1[a - 1][b - 1];
}
int main () {
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m;
	cin >> n >> m;
	vector <vector <int> > vec1(n + 1, vector <int>(m + 1));
	vector <vector <vector <vector <int> > > > dp(n + 1, vector <vector <vector <int> > >(m + 1, vector <vector <int> >(n + 1, vector <int>(m + 1, -1))));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> vec1[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) vec1[i][j] += vec1[i][j - 1];
	for (int j = 1; j <= m; j++) for (int i = 1; i <= n; i++) vec1[i][j] += vec1[i - 1][j];
	cout << rec(1, 1, n, m, vec1, dp) << "\n";
}
