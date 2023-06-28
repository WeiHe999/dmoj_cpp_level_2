#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s1 = 0, s2 = 0, t = 0, ind = -1;
    cin >> n;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    for (int i = 1; i <= n; i++)
    {
        if (vec1[i] > 0)
        {
            s1 += vec1[i];
            if (s2 != 0 && s1 >= s2)
            {
                s1 -= s2;
                s2 = 0;
                t += 2 * (i - ind);
                ind = -1;
            }
        }
        else if (vec1[i] < 0)
        {
            s2 -= vec1[i];
            if (ind == -1)
            {
                if (s1 >= abs(vec1[i]))
                {
                    s2 = 0;
                    s1 += vec1[i];
                }
                else ind = i;
            }
        }
        t++;
    }
    cout << t << "\n";
}
