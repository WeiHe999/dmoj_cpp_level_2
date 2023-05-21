#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s1, s2, s = 0;
    cin >> n;
    vector <long long> vec1(n + 1);
    vector <long long> result(30);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    for (long long i = 29; i >= 0; i--)
    {
        s1 = 0, s2 = 0;
        for (long long j = 1; j <= n; j++)
        {
            if (vec1[j] & (1ll << i)) s1 += (n - j + 1) * j;
            else s2 += (n - j + 1) * j;
        }
        //if (s1 == 0) continue;
        if (s1>0 && s2 < s1) result[i] = 1;
    }
    for (long long i = 0; i <= 29; i++) s += result[i] * (1 << i);
    cout << s << "\n";
}
