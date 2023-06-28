#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        s = max(vec1[i], s);
    }
    vector <long long> vec2(s + 1);
    for (long long i = 1; i <= s; i++) for (long long j = i; j <= s; j += i) vec2[j] += i * i;
    for (long long i = 1; i <= n; i++) cout << vec2[vec1[i]] << "\n";
}
