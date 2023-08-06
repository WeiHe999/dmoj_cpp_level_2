#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, s = 0, r1;
    cin >> n >> k;
    vector <long long> vec1(2 * n + 1), psa(2 * n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        psa[i] = psa[i - 1] + vec1[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        vec1[n + i] = vec1[i];
        psa[n + i] = psa[n + i - 1] + vec1[i];
    }
    deque <pair <long long, long long> > q1;
    for (long long l = 0, r = 1; r <= 2 * n; r++)
    {
        r1 = r - 1;
        while (!q1.empty() && q1.back().first > psa[r1]) q1.pop_back();
        q1.push_back({psa[r1], r1});
        if (r1 - l >= k) l++;
        if (q1.front().second < l) q1.pop_front();
        s = max(psa[r] - q1.front().first, s);
    }
    cout << s << "\n";
}
