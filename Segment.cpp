#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, l, r, s = 0, cur;
    cin >> n;
    vector <pair <int, int> > vec1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        vec1[i] = {r, l};
    }
    sort(vec1.begin(), vec1.end());
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || vec1[i].second >= cur)
        {
            s++;
            cur = vec1[i].first;
        }
    }
    cout << s << "\n";
}
