#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    vector <int> vec1(4);
    cin >> n >> vec1[1] >> vec1[2] >> vec1[3];
    vector <int> memo(n + 1, -1);
    memo[0] = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (memo[j] == -1) continue;
            if (j + vec1[i] <= n) memo[j + vec1[i]] = max(memo[j] + 1, memo[j + vec1[i]]);
        }
    }
    cout << memo[n] << "\n";
}
