#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    stack <pair <long long, long long> > s1;
    for (long long i = 1; i <= n; i++)
    {
        if (!s1.empty())
        {
            if (s1.top().first > vec1[i]) s++;
            else s += s1.top().second;
        }
        pair <long long, long long> cur;
        bool flag = false;
        while (!s1.empty() && s1.top().first <= vec1[i])
        {
            if (s1.top().first == vec1[i])
            {
                cur = s1.top();
                flag = true;
            }
            s1.pop();
            if (!s1.empty())
            {
                if (s1.top().first > vec1[i]) s++;
                else s += s1.top().second;
            }
        }
        if (flag) s1.push({vec1[i], cur.second + 1});
        else s1.push({vec1[i], 1});
    }
    cout << s << "\n";
}
