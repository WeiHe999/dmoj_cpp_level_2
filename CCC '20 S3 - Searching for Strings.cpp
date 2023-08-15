#include <bits/stdc++.h>
using namespace std;

const long long MM = 1e9+7;

vector <long long> hash1(200001), hash2(200001), power1(200001), power2(200001);

long long hashed(long long l, long long r)
{
    long long h1 = (hash1[r] - hash1[l + 1] * power1[r - l - 1] % MM + MM) % MM;
    long long h2 = (hash2[r] - hash2[l + 1] * power2[r - l - 1] % MM + MM) % MM;
    return (h1 << 31) | h2;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2;
    cin >> str1 >> str2;
    long long n = str1.size(), m = str2.size();
    hash1[0] = 0;
    hash2[0] = 0;
    power1[0] = 1;
    power2[0] = 1;
    long long base1 = 131, base2 = 137;
    vector <long long> freq1(26), freq2(26);
    for (int i = 0; i < n; i++) freq1[str1[i] - 'a']++;
    for (int i = 1; i <= m; i++)
    {
        hash1[i] = (hash1[i - 1] * base1 + str2[i - 1]) % MM;
        power1[i] = power1[i - 1] * base1 % MM;
        hash2[i] = (hash2[i - 1] * base2 + str2[i - 1]) % MM;
        power2[i] = power2[i - 1] * base2 % MM;
    }
    unordered_set <long long> s1;
    for (int i = 1; i <= m; i++)
    {
        freq2[str2[i - 1] - 'a']++;
        if (i > n) freq2[str2[i - n - 1] - 'a']--;
        if (freq1 == freq2) s1.insert(hashed(i - n - 1, i));
    }
    cout << s1.size() << "\n";
}
