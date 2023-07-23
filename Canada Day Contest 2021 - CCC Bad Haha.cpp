#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        string n;
        int k, cnt = 0, cur;
        cin >> n >> k;
        if (k == 0)
        {
            cout << n << "\n";
            continue;
        }
        stack <int> s;
        vector <int> vec1, vec2;
        bool flag = false;
        for (int i = 0; i < n.size(); i++)
        {
            cur = n[i] - '0';
            if (flag)
            {
                s.push(cur);
                continue;
            }
            while (!s.empty() && s.top() > cur)
            {
                vec1.emplace_back(s.top());
                s.pop();
                cnt++;
                if (cnt == k)
                {
                    flag = true;
                    break;
                }
            }
            s.push(cur);
        }
        sort(vec1.begin(), vec1.end());
        if (cnt < k)
        {
            cur = vec1[0];
            while (!s.empty() && s.top() > cur)
            {
                vec1.emplace_back(s.top());
                s.pop();
                cnt++;
                if (cnt == k) break;
            }
        }
        sort(vec1.begin(), vec1.end());
        while (!s.empty())
        {
            vec2.emplace_back(s.top());
            s.pop();
        }
        for (int i = vec2.size() - 1; i >= 0; i--) cout << vec2[i];
        for (auto i : vec1) cout << i;
        cout << "\n";
    }
}
