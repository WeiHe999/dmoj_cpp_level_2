#include <bits/stdc++.h>
using namespace std;

vector <vector <long long> > psa(2501, vector <long long>(2501));

long long psa_sum(long long x1, long long y1, long long x2, long long y2)
{
    return psa[x2 + 1][y2 + 1] - psa[x2 + 1][y1] - psa[x1][y2 + 1] + psa[x1][y1];
}

int main()
{
    long long n, a, b, s = 0;
    cin >> n;
    vector <pair <long long, long long> > vec1;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a >> b;
        vec1.push_back({a, b});
    }
    sort(vec1.begin(), vec1.end());
    for (long long i = 1; i <= n; i++) vec1[i - 1].first = i;
    sort(vec1.begin(), vec1.end(), [](pair <long long, long long> a, pair <long long, long long> b){return a.second < b.second;});
    for (long long i = 1; i <= n; i++) vec1[i - 1].second = i;
    for (long long i = 0; i < n; i++) psa[vec1[i].first][vec1[i].second] = 1;
    for (long long i = 1; i <= n; i++) for (long long j = 1; j <= n; j++) psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
    for (long long i = 0; i < n; i++)
    {
        for (long long j = i; j < n; j++)
        {
            s += psa_sum(0, i, min(vec1[i].first, vec1[j].first) - 1, j) * psa_sum(max(vec1[i].first, vec1[j].first) - 1, i, n - 1, j);
        }
    }
    cout << s + 1 << "\n";
}
