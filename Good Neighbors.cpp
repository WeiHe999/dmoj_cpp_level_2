#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, s = 0;
    cin >> r >> c;
    vector <vector <int> > vec1(r + 1, vector <int>(c + 1));
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> vec1[i][j];
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            vector <pair <int, int> > ops = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
            for (auto x : ops) if (vec1[i + x.first][j + x.second] == vec1[i][j]) s = max(vec1[i][j], s);
        }
    }
    cout << s << "\n";
}
