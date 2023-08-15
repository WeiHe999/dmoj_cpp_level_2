#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, s = 0;
    cin >> n >> k;
    vector <long long> vec1(n + 1);
    deque <pair <long long, long long> > q1, q2;
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    for (long long l = 1, r = 1; r <= n; r++)
    {
        while (!q1.empty() && q1.back().first > vec1[r]) q1.pop_back();
        while (!q2.empty() && q2.back().first < vec1[r]) q2.pop_back();
        q1.push_back({vec1[r], r});
        q2.push_back({vec1[r], r});
        while (q2.front().first - q1.front().first > k)
        {
            l++;
            if (q1.front().second < l) q1.pop_front();
            if (q2.front().second < l) q2.pop_front();
        }
        s += r - l + 1;
    }
    cout << s << "\n";
}
