#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, d, t = 0;
    cin >> n >> d;
    vector <vector <long long> > vec1(n + 1, vector <long long>(3));
    for (long long i = 1; i <= n; i++) cin >> vec1[i][0] >> vec1[i][1] >> vec1[i][2];
    for (long long i = 1; i <= n; i++)
    {
        t += vec1[i][0] - vec1[i - 1][0];
        long long left = t % (vec1[i][1] + vec1[i][2]);
        if (left < vec1[i][1]) t += vec1[i][1] - left;
    }
    cout << t + d - vec1[n][0] << "\n";
}
