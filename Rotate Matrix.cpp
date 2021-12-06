#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int h, w, a;
    cin >> h >> w;
    vector <vector <int> > myvector;
    vector <int> tmp;
    for (int x = 0; x < h; x++)
    {
        tmp = {};
        for (int y = 0; y < w; y++)
        {
            cin >> a;
            tmp.emplace_back(a);
        }
        myvector.push_back(tmp);
    }
    for (int y = w - 1; y >= 0; y--)
    {
        for (int x = 0; x < h; x++) cout << myvector[x][y] << " ";
        cout << endl;
    }
}
