#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, base = 131, mod = 1e9+7, s = 1;
    string str1, ans;
    cin >> n >> str1;
    ans = str1[0];
    unordered_map <char, vector <long long> > m1;
    for (int x = 0; x < str1.size(); x++) m1[str1[x]].emplace_back(x);
    vector <long long> hash1(n + 1), hash2(n + 2), power(n + 1);
    power[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        hash1[i] = (hash1[i - 1] * base + (str1[i - 1] - 'A') % mod + mod) % mod;
        power[i] = (power[i - 1] * base % mod + mod) % mod;
    }
    for (long long i = n; i >= 1; i--) hash2[i] = (hash2[i + 1] * base + (str1[i - 1] - 'A') % mod + mod) % mod;
    for (long long l = 1; l <= n; l++)
    {
        for (auto x : m1[str1[l - 1]])
        {
            long long r = x + 1;
            if (r < l + s) continue;
            if (((hash1[r] - hash1[l - 1] * power[r - l + 1] % mod + mod) % mod == (hash2[l] - hash2[r + 1] * power[r - l + 1] % mod + mod) % mod))
            {
                ans = str1.substr(l - 1, r - l + 1);
                s = r - l + 1;
            }
        }
    }
    cout << ans << "\n" << s << "\n";
}
