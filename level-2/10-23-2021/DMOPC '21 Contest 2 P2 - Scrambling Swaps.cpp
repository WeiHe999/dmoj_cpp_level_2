#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, q, c, d;
    cin >> n >> q;
    char a;
    vector <int> t, query, front, end, output;
    unordered_map <int, int> m1;
    for (int i = 0; i < n; i++)
    {
        front.push_back(i + 1);
        end.push_back(i + 1);
    }
    for (int x = 0; x < q; x++)
    {
        cin >> a;
        if (a != 'Q')
        {
            cin >> c;
            cin >> d;
            if (a == 'B') swap(front[c-1], front[d-1]);
            else swap(end[c-1], end[d-1]);
        }
        else
        {
            if (a == 'Q')
            {
                for (int b = 0; b < n; b++)
                {
                    cin >> c;
                    query.emplace_back(c);
                }
                for (int k = 0; k < n; k++) m1[end[k]] = query[k];
                for (int f = 0; f < n; f++)
                {
                    if (f != n - 1) cout << m1[front[f]] << " ";
                    else cout << m1[front[f]];
                }
                cout << endl;
                query = {};
            }
        }
    }
}
