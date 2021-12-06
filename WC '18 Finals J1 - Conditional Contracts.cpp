#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, first = 0, second = 0;
    cin >> n;
    unordered_map <long long, long long> m1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        m1[a]++;
    }
    for (auto b : m1)
    {
        if (b.second > first)
        {
            second = first;
            first = b.second;
        }
        else if (b.second > second) second = b.second;
    }
    cout << first + second << endl;
}

fork us on Github | like us on Facebook | help us translate | terms of service | 
English (en)
