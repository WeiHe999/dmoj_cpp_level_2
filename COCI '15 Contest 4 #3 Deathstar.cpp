#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a;
    cin >> n;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            cin >> a;
            vec1[i] = (vec1[i] | a);
        }
    }
    for (long long i = 1; i <= n; i++) cout << vec1[i] << " ";
    cout << "\n";
}
