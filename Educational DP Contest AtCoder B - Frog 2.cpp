#include <bits/stdc++.h>
using namespace std;

const int MM = 1e9;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector <int> vec1(n + 1), memo(n + 1, MM);
    memo[1] = 0;
    for (int x = 1; x <= n; x++) cin >> vec1[x];
    for (int x = 2; x <= n; x++) for (int a = max(1, x - k); a < x; a++) memo[x] = min(memo[a] + abs(vec1[x] - vec1[a]), memo[x]);
    cout << memo[n] << "\n";
}
