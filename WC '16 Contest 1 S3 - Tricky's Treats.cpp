#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, t, a, b, s = 0;
    cin >> n >> m >> t;
    vector <pair <long long, long long> > vec1;
    priority_queue <long long, vector <long long>, greater <long long> > q1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a >> b;
        if (2 * a + t <= m) vec1.push_back({a, b});
    }
    sort(vec1.begin(), vec1.end());
    long long prev = 0, sum = 0;
    for (auto x : vec1)
    {
        q1.push(x.second);
        sum += x.second;
        m -= (long long)2 * (x.first - prev) + t;
        prev = x.first;
        while (m < 0)
        {
            sum -= q1.top();
            q1.pop();
            m += t;
        }
        s = max(sum, s);
    }
    cout << s << "\n";
}
