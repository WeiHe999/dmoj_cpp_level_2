#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, ans = 0;
    string s;
    cin >> n >> s;
    vector <int> freqr(n + 1), freqb(n + 1), ind;
    for (int i = 0; i < s.size(); i++)
    {
        freqr[i + 1] = freqr[i];
        freqb[i + 1] = freqb[i];
        if (s[i] == 'R') freqr[i + 1]++;
        else if (s[i] == 'B') freqb[i + 1]++;
        else if (s[i] == 'G') ind.emplace_back(i);
    }
    for (int i = 0; i < ind.size(); i++)
    {
        int s1, s2;
        if (i == 0) s1 = freqr[ind[i] + 1];
        else s1 = freqr[ind[i] + 1] - freqr[ind[i - 1] + 1];
        if (i == ind.size() - 1) s2 = freqb[s.size()] - freqb[ind[i] + 1];
        else s2 = freqb[ind[i + 1] + 1] - freqb[ind[i] + 1];
        ans += s1 * s2;
    }
    cout << ans << "\n";
}
