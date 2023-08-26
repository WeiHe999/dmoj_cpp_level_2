#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, c;
    cin >> n >> m >> c;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    deque <pair <long long, long long> > q1, q2;
    for (long long i = 1; i <= m - 1; i++)
    {
        while (!q1.empty() && q1.back().first > vec1[i]) q1.pop_back();
        while (!q2.empty() && q2.back().first < vec1[i]) q2.pop_back();
        q1.push_back({vec1[i], i});
        q2.push_back({vec1[i], i});
    }
    bool flag = false;
    for (long long i = 1, j = m; j <= n; j++)
    {
        while (!q1.empty() && q1.back().first > vec1[j]) q1.pop_back();
        while (!q2.empty() && q2.back().first < vec1[j]) q2.pop_back();
        q1.push_back({vec1[j], j});
        q2.push_back({vec1[j], j});
        if (q1.front().second < i) q1.pop_front();
        if (q2.front().second < i) q2.pop_front();
        if (q2.front().first - q1.front().first <= c)
        {
            flag = true;
            cout << i << "\n";
        }
        i++;
    }
    if (!flag) cout << "NONE\n";
}
