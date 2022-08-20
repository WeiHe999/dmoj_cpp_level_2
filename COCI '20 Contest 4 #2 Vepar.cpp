#include <bits/stdc++.h>
using namespace std;

int value(int p, int a)
{
    if (a == 0) return 0;
    return a / p + value(p, a / p); 
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> primes, vec1(10000001);
    for (int p = 2; p < 10000001; p++)
    {
        if (vec1[p] == 0) primes.push_back(p);
        for (int i = p; i < 10000001; i += p) vec1[i]++;
    }
    int t, a, b, c, d;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c >> d;
        a--; c--;
        bool flag = true;
        for (auto p : primes)
        {
            if (value(p, b) - value(p, a) > value(p, d) - value(p, c))
            {
                cout << "NE\n";
                flag = false;
                break;
            }
        } 
        if (flag) cout << "DA\n";
    }
}
