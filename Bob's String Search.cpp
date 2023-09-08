#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    vector <long long> hash1(s.size() + 1);
    long long hash2 = 0, power = 1, base = 131, ans = 0, mod = 1e9+7;
    for (long long i = 1; i <= s.size(); i++) hash1[i] = ((hash1[i - 1] * base + (tolower(s[i - 1]) - 'a' + 1)) % mod + mod) % mod;
    for (long long i = 1; i <= t.size(); i++)
    {
        hash2 = ((hash2 * base + (tolower(t[i - 1]) - 'a' + 1)) % mod + mod) % mod;
        power = ((power * base) % mod + mod) % mod;
    }
    for (long long i = 1; i + t.size() - 1 <= s.size(); i++)
    {
        long long j = i + t.size() - 1;
        if (((hash1[j] - hash1[i - 1] * power) % mod + mod) % mod == hash2) ans++;
    }
    cout << ans << "\n";
}
