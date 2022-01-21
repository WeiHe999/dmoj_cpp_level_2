#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t, n, a, price, cnt, k;
    string name;
    long long ans = 0;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        map <string, vector <pair <int, int> > > items;
        cin >> n;
        for (int y = 0; y < n; y++)
        {
            cin >> a;
            for (int z = 0; z < a; z++)
            {
                cin >> name >> price >> cnt;
                items[name].emplace_back(price, cnt);
            }
        }
        for (auto b = items.begin(); b != items.end(); b++) sort(b->second.begin(), b->second.end(), greater<pair <int, int> >());
        cin >> k;
        ans = 0;
        for (int c = 0; c < k; c++)
        {
            cin >> name >> cnt;
            vector <pair <int, int> > vec1 = items[name];
            while (cnt > 0)
            {
                int remain = min(cnt, vec1.back().second);
                ans += vec1.back().first * remain;
                cnt -= remain;
                vec1.pop_back();
            }
        }
        cout << ans << endl;
    }
}
