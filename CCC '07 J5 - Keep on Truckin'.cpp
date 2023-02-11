#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long a, b, n, m, cnt = 0;
    cin >> a >> b >> n;
    vector <long long> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    for (long long x = 0; x < n; x++)
    {
        cin >> m;
        motels.emplace_back(m);
    }
    sort(motels.begin(), motels.end());
    vector <long long> memo(motels.size());
    memo[0] = 1;
    for (long long x = 0; x < motels.size(); x++)
    {
        for (long long i = x + 1; i < motels.size(); i++)
        {
            if (motels[i] > motels[x] + b) break;
            if (motels[i] >= motels[x] + a) memo[i] += memo[x];
        }
    }
    cout << memo[motels.size() - 1] << "\n";
}
