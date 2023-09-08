#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, cnt1 = 1, cnt2 = 1, factorial = 1;
    cin >> n;
    set <long long> s1, s2;
    vector <long long> vec1(n + 1), vec2(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        s1.insert(vec1[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec2[i];
        s2.insert(vec2[i]);
    }
    for (long long i = 2; i <= n - 1; i++) factorial *= i;
    for (long long i = 1; i <= n; i++)
    {
        long long ind1 = 1, ind2 = 1;
        for (auto x : s1)
        {
            if (x == vec1[i]) break;
            ind1++;
        }
        for (auto x : s2)
        {
            if (x == vec2[i]) break;
            ind2++;
        }
        cnt1 += ind1 * factorial;
        cnt2 += ind2 * factorial;
        if (n - i != 0) factorial = factorial / (n - i);
        s1.erase(vec1[i]);
        s2.erase(vec2[i]);
    }
    cout << abs(cnt1 - cnt2) << "\n";
}
