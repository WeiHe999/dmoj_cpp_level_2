#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector <long long> vec1;
    for (long long i = 0; i < n; i++)
    {
        long long tmp, a = min(k - n + i + 1, m);
        if (a == 0) break;
        if (a > i)
        {
            tmp = min(i + 1, m);
            a = tmp;
        }
        else tmp = vec1[i - a];
        vec1.push_back(tmp);
        k -= a;
    }
    if (k == 0 && vec1.size() == n)
    {
        for (long long i = 0; i < n; i++)
        {
            cout << vec1[i];
            if (i != n - 1) cout << " ";
        }
    }
    else cout << -1;
    cout << "\n";
}
