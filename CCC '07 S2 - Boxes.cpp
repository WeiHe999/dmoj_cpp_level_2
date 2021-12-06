#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, l, w, h;
    cin >> n;
    vector <vector <int> > box_size;
    vector <int> sorted;
    bool test;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> w >> h;
        sorted = {l, w, h};
        sort(sorted.begin(), sorted.end());
        box_size.push_back({l * w * h, sorted[0], sorted[1], sorted[2]});
    }
    sort(box_size.begin(), box_size.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        test = true;
        cin >> l >> w >> h;
        for (int j = 0; j < n; j++)
        {
            if (l * w * h <= box_size[j][0])
            {
                sorted = {l, w, h};
                sort(sorted.begin(), sorted.end());
                if (box_size[j][1] >= sorted[0] && box_size[j][2] >= sorted[1] && box_size[j][3] >= sorted[2])
                {
                    cout << box_size[j][1] * box_size[j][2] * box_size[j][3] << endl;
                    test = false;
                    break;
                }
            }
        }
        if (test) cout << "Item does not fit." << endl;
    }
}
