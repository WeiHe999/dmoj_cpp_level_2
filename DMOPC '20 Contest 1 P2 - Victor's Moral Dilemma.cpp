#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, d, a, b, begin, end, f, s, tot;
    cin >> n >> d;
    vector <long long> psa = {0};
    for (long long i = 1; i <= n; i++)
    {
        cin >> a;
        psa.emplace_back(psa[i - 1] + a);
    }
    begin = 1;
    end = n;
    for (long long i = 0; i < d; i++)
    {
        cin >> b;
        f = psa[begin + b - 1] - psa[begin - 1];
        tot = psa[end] - psa[begin - 1];
        s = tot - f;
        if (f < s)
        {
            end = begin + b - 1;
            cout << s << endl;
        }
        else
        {
            begin = begin + b;
            cout << f << endl;
        }
    }
}
