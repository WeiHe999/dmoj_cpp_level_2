#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <pair <int, int> > vec1;
    for (int i = 0; i < n; i++)
    {
        char d;
        cin >> d >> a;
        vec1.push_back({a, 0});
        if (d == 'G') vec1[i].second = -1;
        else vec1[i].second = 1;
    }
    sort(vec1.begin(), vec1.end());
    int mina = n;
    for (int b = 0; b < n; b++)
    {
        int s = 0;
        for (int c = 0; c < b; c++) if (vec1[c].second == 1) s++;
        for (int d = b + 1; d < n; d++) if (vec1[d].second == -1) s++;
        mina = min(s, mina);
    }
    cout << mina << endl;
}
