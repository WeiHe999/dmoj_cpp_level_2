#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <string> vec1(n);
    vector <vector <char> > vec2(n, vector <char>(n));
    vector <int> counts(n);
    for (int i = 1; i <= n; i++) cin >> vec1[i - 1];
    for (int j = 0; j < n; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++) if (vec1[i][j] == 'S') cnt++;
        counts[j] = cnt;
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i >= n - counts[j]) vec2[i][j] = 'S';
            else vec2[i][j] = '.';
        }
    }
    for (auto x : vec2)
    {
        for (auto y : x) cout << y;
        cout << "\n";
    }
}
