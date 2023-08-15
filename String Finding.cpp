#include <bits/stdc++.h>
using namespace std;

const long long base = 131, mod = 1e9+7;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    vector <long long> hash1(s.size() + 1), hash2(t.size() + 1), power1(s.size() + 1), power2(t.size() + 1);
    power1[0] = 1;
    power2[0] = 1;
    for (long long x = 1; x <= s.size(); x++)
    {
        hash1[x] = (hash1[x - 1] * base % mod + (s[x - 1] - 'a') + mod) % mod;
        power1[x] = (power1[x - 1] * base % mod + mod) % mod;
    }
    for (long long x = 1; x <= t.size(); x++)
    {
        hash2[x] = (hash2[x - 1] * base % mod + (t[x - 1] - 'a') + mod) % mod;
        power2[x] = (power2[x - 1] * base % mod + mod) % mod;
    }
    for (long long l = 1; l + t.size() - 1 <= s.size(); l++)
    {
        long long r = l + t.size() - 1;
        if ((hash1[r] - hash1[l - 1] * power1[r - l + 1] % mod + mod) % mod == hash2[t.size()])
        {
            cout << l - 1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}
