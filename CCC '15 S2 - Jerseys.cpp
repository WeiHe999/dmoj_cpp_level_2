#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    int j, a;
    char c;
    cin >> j >> a;
    vector <int> vec1;
    for (int i = 0; i < j; i++)
    {
        cin >> c;
        vec1.emplace_back(c);
    }
    int ans = 0;
    char d;
    int e;
    for (int i = 0; i < a; i++)
    {
        cin >> d >> e;
        if (d == 'L')
        {
            if (vec1[e - 1] == 'L')
            {
                ans++;
                vec1[e - 1] = 'X';
            }
        }
        if (d == 'M')
        {
            if (vec1[e - 1] == 'L' || vec1[e - 1] == 'M')
            {
                ans++;
                vec1[e - 1] = 'X';
            }
        }
        if (d == 'S')
        {
            if (vec1[e - 1] == 'L' || vec1[e - 1] == 'M' || vec1[e - 1] == 'S')
            {
                ans++;
                vec1[e - 1] = 'X';
            }
        }
    }
    cout << ans << endl;
}
