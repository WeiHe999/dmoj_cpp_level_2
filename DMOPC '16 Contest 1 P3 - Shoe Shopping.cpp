#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1);
    vector <double> memo(n + 1);
    for (int x = 1; x <= n; x++) cin >> vec1[x];
    for (int x = 1; x <= n; x++)
    {
        memo[x] = memo[x - 1] + vec1[x];
        if (x >= 2) memo[x] = min(memo[x - 2] + (min(vec1[x - 1], vec1[x]) / 2.0) + max(vec1[x - 1], vec1[x]), memo[x]);
        if (x >= 3)
        {
            vector <int> tmp = {vec1[x - 2], vec1[x - 1], vec1[x]};
            sort(tmp.begin(), tmp.end());
            memo[x] = min(memo[x - 3] + tmp[1] + tmp[2], memo[x]);
        }
    }
    cout << setprecision(1) << fixed << memo[n] << "\n";
}
