#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, w, s = 0;
    cin >> n >> w;
    vector <long long> weights(n + 1), values(n + 1), memo(w + 1, -1);
    for (long long i = 1; i <= n; i++) cin >> weights[i] >> values[i];
    memo[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = w; j >= 0; j--)
        {
            if (memo[j] == -1) continue;
            // cout << "round-" << i << ", j=" << j << endl;
            if (j + weights[i] <= w) 
            {
                // cout << memo[j] << endl;
                memo[j + weights[i]] = max(memo[j] + values[i], memo[j + weights[i]]);
            }
            
        }
        // print(memo);
    }
    for (auto x : memo) s = max(x, s);
    cout << s << "\n";
}
