#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, x, cnt = 0;
    cin >> n;
    stack <int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (!s.empty() && s.top() > x) s.pop();
        if (!s.empty() && s.top() == x) continue;
        if (x != 0)
        {
            cnt++;
            s.push(x);
        }
    }
    cout << cnt << "\n";
}
