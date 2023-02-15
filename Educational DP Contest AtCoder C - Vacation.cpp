#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <vector <int> > vec1(n + 1, vector <int>(4)), memo(n + 1, vector <int>(4));
    for (int x = 1; x <= n; x++) cin >> vec1[x][1] >> vec1[x][2] >> vec1[x][3];
    memo[1][1] = vec1[1][1], memo[1][2] = vec1[1][2], memo[1][3] = vec1[1][3];
    for (int x = 2; x <= n; x++)
    {
        memo[x][1] = max(memo[x - 1][2], memo[x - 1][3]) + vec1[x][1];
        memo[x][2] = max(memo[x - 1][1], memo[x - 1][3]) + vec1[x][2];
        memo[x][3] = max(memo[x - 1][1], memo[x - 1][2]) + vec1[x][3];
    }
    cout << max(max(memo[n][1], memo[n][2]), memo[n][3]) << "\n";
}
