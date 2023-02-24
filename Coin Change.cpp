#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int x, n;
    cin >> x >> n;
    vector <int> vec1(n + 1), memo(x + 1, 1e9);
    for (int a = 1; a <= n; a++) cin >> vec1[a];
    memo[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j + vec1[i] <= x) memo[j + vec1[i]] = min(memo[j] + 1, memo[j + vec1[i]]);
        }
    }
    cout << memo[x] << "\n";
}
