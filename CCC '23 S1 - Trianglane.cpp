#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int c, ans = 0, a;
    cin >> c;
    vector <vector <long long> > vec1(3, vector <long long>(c + 1));
    vector <vector <bool> > vec2(3, vector <bool>(c + 1, false));
    for (long long i = 1; i <= 2; i++) for (long long j = 1; j <= c; j++) vec1[i][j] = 3;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> a;
            if (a == 1)
            {
                vec2[i][j] = true;
                if (j % 2 == 1 && i == 1) vec1[2][j]--;
                if (j < c) vec1[i][j + 1]--;
                if (j > 1) vec1[i][j - 1]--;
                if (j % 2 == 1 && i == 2) vec1[i - 1][j]--;
            }
        }
    }
    for (int i = 1; i <= 2; i++) for (int j = 1; j <= c; j++) if (vec2[i][j]) ans += vec1[i][j];
    cout << ans << "\n";
}
