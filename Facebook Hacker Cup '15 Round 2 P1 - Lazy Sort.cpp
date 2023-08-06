#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        int n, a, min, max;
        cin >> n;
        deque <int> q1, q2, q3;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            q1.push_front(a);
        }
        q2 = q1;
        q3.push_front(q2.front());
        min = q2.front(), max = q2.front();
        q2.pop_front();
        while (!q2.empty())
        {
            if (q2.front() == min - 1)
            {
                min--;
                q3.push_front(q2.front());
                q2.pop_front();
            }
            else if (q2.front() == max + 1)
            {
                max++;
                q3.push_back(q2.front());
                q2.pop_front();
            }
            else if (q2.back() == min - 1)
            {
                min--;
                q3.push_front(q2.back());
                q2.pop_back();
            }
            else if (q2.back() == max + 1)
            {
                max++;
                q3.push_back(q2.back());
                q2.pop_back();
            }
            else break;
        }
        if (q2.empty())
        {
            cout << "Case #" << x << ": yes\n";
            continue;
        }
        q2 = q1;
        q3.push_front(q2.back());
        min = q2.back(), max = q2.back();
        q2.pop_back();
        while (!q2.empty())
        {
            if (q2.front() == min - 1)
            {
                min--;
                q3.push_front(q2.front());
                q2.pop_front();
            }
            else if (q2.front() == max + 1)
            {
                max++;
                q3.push_back(q2.front());
                q2.pop_front();
            }
            else if (q2.back() == min - 1)
            {
                min--;
                q3.push_front(q2.back());
                q2.pop_back();
            }
            else if (q2.back() == max + 1)
            {
                max++;
                q3.push_back(q2.back());
                q2.pop_back();
            }
            else break;
        }
        if (q2.empty()) cout << "Case #" << x << ": yes\n";
        else cout << "Case #" << x << ": no\n";
    }
}
