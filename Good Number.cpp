#include <bits/stdc++.h>
using namespace std;

long long case1(long long a)
{
    string str1 = "0123456789";
    for (auto b : str1)
    {
        long long c = stol(string(to_string(a).size(), b));
        if (c >= a) return c;
    }
}

long long case2(long long a)
{
    string str1 = "0123456789", str2 = to_string(a), str3 = to_string(a);
    long long mina = LLONG_MAX;
    for (int b = 0; b < str2.size(); b++)
    {
        for (auto c : str1)
        {
            for (auto d : str1)
            {
                for (auto &e : str3)
                {
                    e = d;
                }
                str3[b] = c;
                long long f = stol(str3);
                if (f >= a && f < mina) mina = f;
            }
        }
    }
    return mina;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long a, k;
    cin >> a >> k;
    if (k == 0)
    {
        cout << case1(a) << endl;
    }
    else
    {
        cout << case2(a) << endl;
    }
}
