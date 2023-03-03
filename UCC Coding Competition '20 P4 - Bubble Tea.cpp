#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1), memo(n + 1);
    for (int x = 1; x <= n; x++) cin >> vec1[x];
    memo[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        memo[i] = memo[i - 1] + vec1[i];
        if (i >= 2) memo[i] = min(memo[i - 2] + max(vec1[i], vec1[i - 1]) + min(vec1[i], vec1[i - 1]) * 3 / 4, memo[i]);
        if (i >= 3) memo[i] = min(memo[i - 3] + vec1[i] + vec1[i - 1] + vec1[i - 2] - min({vec1[i], vec1[i - 1], vec1[i - 2]}) / 2, memo[i]);
    }
    cout << memo[n] << "\n";
}
