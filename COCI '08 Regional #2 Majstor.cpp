#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, n, s = 0, t = 0;
    string str1, a;
    cin >> r >> str1 >> n;
    vector <string> vec1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = 0; j < r; j++)
        {
            if (str1[j] == a[j]) s++;
            if (str1[j] == 'R' && a[j] == 'S') s += 2;
            if (str1[j] == 'P' && a[j] == 'R') s += 2;
            if (str1[j] == 'S' && a[j] == 'P') s += 2;
        }
        vec1.emplace_back(a);
    }
    for (int i = 0; i < r; i++)
    {
        int s1 = 0, s2 = 0, s3 = 0;
        for (int j = 0; j < n; j++)
        {
            if (vec1[j][i] == 'R')
            {
                s1++;
                s3 += 2;
            }
            else if (vec1[j][i] == 'S')
            {
                s2++;
                s1 += 2;
            }
            else
            {
                s3++;
                s2 += 2;
            }
        }
        t += max({s1, s2, s3});
    }
    cout << s << "\n" << t << "\n";
}
