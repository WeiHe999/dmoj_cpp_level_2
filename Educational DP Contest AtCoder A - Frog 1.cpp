#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1);
    for (int x = 1; x <= n; x++) cin >> vec1[x];
    unordered_map <int, int> memo = {{1, 0}};
    for (int x = 2; x <= n; x++)
    {
        if (x == 2) memo[x] = memo[x - 1] + abs(vec1[x] - vec1[x - 1]);
        else memo[x] = min(memo[x - 1] + abs(vec1[x] - vec1[x - 1]), memo[x - 2] + abs(vec1[x] - vec1[x - 2]));
    }
    cout << memo[n] << "\n";
}
