#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2;
    cin >> str1 >> str2;
    vector <long long> hash1(str1.size() + 1), hash2(str2.size() + 1), power1(str1.size() + 1), power2(str2.size() + 1);
    long long base = 131;
    power1[0] = 1;
    for (long long x = 1; x <= str1.size(); x++)
    {
        hash1[x] = (hash1[x - 1] * base % mod + (str1[x - 1] - 'a') + mod) % mod;
        power1[x] = (power1[x - 1] * base % mod + mod) % mod;
    }
    power2[0] = 1;
    for (long long x = 1; x <= str2.size(); x++)
    {
        hash2[x] = (hash2[x - 1] * base % mod + (str2[x - 1] - 'a') + mod) % mod;
        power2[x] = (power2[x - 1] * base % mod + mod) % mod;
    }
    for (long long k = min(str1.size(), str2.size()); k >= 1; k--)
    {
        long long l1 = str1.size() - k + 1, r1 = str1.size(), l2 = 1, r2 = k;
        if ((hash1[r1] - hash1[l1 - 1] * power1[r1 - l1 + 1] % mod + mod) % mod == (hash2[r2] - hash2[l2 - 1] * power2[r2 - l2 + 1] % mod + mod) % mod)
        {
            cout << str1 + str2.substr(k) << "\n";
            return 0;
        }
    }
    cout << str1 + str2 << "\n";
}
