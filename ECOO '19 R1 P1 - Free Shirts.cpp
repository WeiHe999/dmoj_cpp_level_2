#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int shirts, events, d, s, cur_shirts, a, ind;
    vector <int> e;
    for (int x = 0; x < 10; x++)
    {
        cin >> shirts >> events >> d;
        s = 0;
        cur_shirts = shirts;
        e = {};
        for (int y = 0; y < events; y++)
        {
            cin >> a;
            e.emplace_back(a);
        }
        sort(e.begin(), e.end());
        ind = 0;
        for (int z = 1; z <= d; z++)
        {
            if (cur_shirts == 0)
            {
                s++;
                cur_shirts = shirts;
            }
            while (z == e[ind])
            {
                cur_shirts++;
                shirts++;
                ind++;
            }
            cur_shirts--;
        }
        cout << s << endl;
    }
}
