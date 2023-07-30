#include <bits/stdc++.h>
using namespace std;

long long n;
vector <vector <bool> > check(1000, vector <bool>(1000, false));

long long solve()
{
    long long s = 0;
    for (long long i = 0; i < n; i++)
    {
        vector <bool> vec1(n, true);
        for (long long j = i; j < n; j++)
        {
            long long tmp = 0;
            for (long long k = 0; k < n; k++)
            {
                if (!check[j][k]) vec1[k] = false;
                if (vec1[k])
                {
                    tmp++;
                    s += tmp;
                }
                else tmp = 0;
            }
        }
    }
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    vector <vector <long long> > pasture(n, vector <long long>(n));
    for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) cin >> pasture[i][j];
    for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) if (pasture[i][j] >= 100) check[i][j] = true;
    long long s = solve();
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            if (pasture[i][j] > 100) check[i][j] = true;
            else check[i][j] = false;
        }
    }
    cout << s - solve() << "\n";
}
