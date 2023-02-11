#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1), memo(n + 1);
    for (int x = 1; x <= n; x++) cin >> vec1[x];
    memo[1] = vec1[1];
    for (int i = 2; i <= n; i++) memo[i] = max(memo[i - 2] + vec1[i], memo[i - 1]);
    cout << memo[n] << "\n";
}
