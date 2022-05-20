#include <bits/stdc++.h>
using namespace std;

bool check(vector <long long> vec1, unordered_map <long long, long long> m1, long long n, long long s)
{
    long long index = 0;
    long long minimum = m1[vec1[index]];
    bool flag = true;
    for (long long x = 1; x < n; x++)
    {
        minimum += s;
        index = lower_bound(vec1.begin(), vec1.end(), minimum) - vec1.begin();
        if (index == vec1.size())
        {
            flag = false;
            break;
        }
        if (m1[vec1[index]] > minimum) minimum = m1[vec1[index]];
    }
    if (flag) return true;
    else return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long left = 1, right = LLONG_MIN, mid, n, m, a, b, ans = 1;
    cin >> n >> m;
    unordered_map <long long, long long> m1;
    vector <long long> vec1;
    for (long long x = 0; x < m; x++)
    {
        cin >> a >> b;
        right = max(b, right);
        vec1.emplace_back(b);
        m1[b] = a;
    }
    sort(vec1.begin(), vec1.end());
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (check(vec1, m1, n, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}
