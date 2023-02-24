#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector <int> vec1(k + 1), memo(n + 1, 1e9);
    for (int i = 1; i <= k; i++) cin >> vec1[i];
    memo[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j + vec1[i] <= n) memo[j + vec1[i]] = min(memo[j] + 1, memo[j + vec1[i]]);
        }
    }
    if (memo[n] != 1e9) cout << "Roberta wins in " << memo[n] << " strokes.\n";
    else cout << "Roberta acknowledges defeat.\n";
}
