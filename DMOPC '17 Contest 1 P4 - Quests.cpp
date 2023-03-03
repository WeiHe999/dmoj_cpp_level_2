#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, h, s = 0;
    cin >> n >> h;
    vector <vector <long long> > vec1(n + 1, vector <long long>(4)), memo(2, vector <long long>(h + 1, -1));
    for (long long x = 1; x <= n; x++) cin >> vec1[x][0] >> vec1[x][1] >> vec1[x][2] >> vec1[x][3];
    memo[0][0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = h; j >= 0; j--)
        {
            if (memo[0][j] == -1) continue;
            if (j + vec1[i][1] <= h) memo[1][j + vec1[i][1]] = max(memo[0][j] + vec1[i][0], memo[1][j + vec1[i][1]]);
        }
        for (long long j = 0; j <= h; j++)
        {
            if (memo[1][j] == -1) continue;
            if (j + vec1[i][3] <= h) memo[1][j + vec1[i][3]] = max(memo[1][j] + vec1[i][2], memo[1][j + vec1[i][3]]);
        }
        vector <vector <long long> > tmp(2, vector <long long>(h + 1, -1));
        for (long long j = 0; j <= h; j++)
        {
            memo[1][j] = max(memo[0][j], memo[1][j]);
            tmp[0][j] = memo[1][j];
        }
        memo = tmp;
    }
    for (long long i = 1; i <= h; i++) s = max(memo[0][i], s);
    cout << s << "\n";
}
