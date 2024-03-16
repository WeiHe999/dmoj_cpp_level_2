#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, s = 0;
    string str1;
    cin >> n >> m >> str1;
    vector <long long> vec1(n);
    for (long long i = 0; i < n; i++) cin >> vec1[i];
    vector <bool> vecl(n), vecr(n);
    for (long long i = 0; i < n; i++)
    {
        if (str1[i] == 'R' && str1[(i + 1) % n] == 'L')
        {
            vecl[i] = true;
            vecr[(i + 1) % n] = true;
        }
    }
    for (long long i = 0; i < n; i++) s += vec1[i];
    for (long long i = 0; i < n; i++)
    {
        long long sum = 0;
        if (vecl[i])
        {
            long long j = (i - 1 + n) % n;
            while (str1[j] == 'R')
            {
                sum += vec1[j];
                j--;
                if (j < 0) j += n;
            }
        }
        if (vecr[i])
        {
            long long j = (i + 1) % n;
            while (str1[j] == 'L')
            {
                sum += vec1[j];
                j++;
                if (j >= n) j -= n;
            }
        }
        s -= min(sum, m);
    }
    cout << s << "\n";
}
