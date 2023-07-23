#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, s = 0, a, b;
    cin >> r >> c;
    vector <vector <char> > vec1(r, vector <char>(c + 1));
    vector <vector <int> > psa(r, vector <int>(c + 1));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> vec1[i][j];
    for (int i = 0; i < r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            psa[i][j] = psa[i][j - 1];
            if (vec1[i][j - 1] == 'X') psa[i][j]++;
        }
    }
    for (int s1 = 1; s1 <= c; s1++)
    {
        for (int s2 = s1; s2 <= c; s2++)
        {
            a = 0, b = 0;
            for (int i = 0; i < r; i++)
            {
                if (psa[i][s2] - psa[i][s1 - 1] == 0)
                {
                    a++;
                    if (a > b)
                    {
                        
                        b = a;
                    }
                }
                else a = 0;
            }
            if (b > 0) s = max(2 * b + 2 * (s2 - s1 + 1), s);
        }
    }
    cout << s - 1 << "\n";
}
