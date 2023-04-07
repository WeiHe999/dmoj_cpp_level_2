#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector <int> vec1(n + 1);
    vector <bool> memo(k + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    memo[0] = false;
    for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) if (vec1[j] <= i && !memo[i - vec1[j]]) memo[i] = true;
    if (memo[k]) cout << "First\n";
    else cout << "Second\n";
}
