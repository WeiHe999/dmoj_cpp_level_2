#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n)
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

long long letter_arrangements(string str1)
{
    unordered_map <char, long long> m1;
    for (long long x = 0; x < str1.size(); x++) m1[str1[x]]++;
    long long s = factorial(str1.size());
    for (auto a : m1) s /= factorial(a.second);
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k;
    string str1, alpha = "abcdefghijklmnopqrstuvwxyz", str2;
    cin >> n >> k >> str1;
    unordered_set <string> s1;
    if (k == 0)
    {
        cout << letter_arrangements(str1) << "\n";
        return 0;
    }
    else if (k == 1)
    {
        sort(str1.begin(), str1.end());
        for (long long x = 0; x < alpha.size(); x++)
        {
            string tmp(1, alpha[x]);
            str2 = tmp + str1.substr(1);
            sort(str2.begin(), str2.end());
            s1.insert(str2);
        }
    }
    else
    {
        sort(str1.begin(), str1.end());
        for (long long x = 0; x < alpha.size(); x++)
        {
            for (long long y = 0; y < alpha.size(); y++)
            {
                string tmp1(1, alpha[x]), tmp2(1, alpha[y]);
                str2 = tmp1 + tmp2 + str1.substr(2);
                sort(str2.begin(), str2.end());
                s1.insert(str2);
            }
        }
    }
    long long s = 0;
    for (auto a : s1) s += letter_arrangements(a);
    cout << s << "\n";
}
