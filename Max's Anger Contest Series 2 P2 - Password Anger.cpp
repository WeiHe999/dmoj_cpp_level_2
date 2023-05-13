#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, s = 0, tmp1, tmp2, tmp3, tmp4;
    cin >> n >> m;
    for (int a = 1; a <= 26; a++)
    {
        tmp1 = a;
        if (n == 1)
        {
            if (tmp1 == m)
            {
                s++;
                break;
            }
        }
        else
        {
            for (int b = 1; b <= 26; b++)
            {
                tmp2 = tmp1 * 13 + b;
                if (n == 2)
                {
                    if (tmp2 == m)
                    {
                        s++;
                        break;
                    }
                }
                else
                {
                    for (int c = 1; c <= 26; c++)
                    {
                        tmp3 = tmp2 * 13 + c;
                        if (n == 3)
                        {
                            if (tmp3 == m)
                            {
                                s++;
                                break;
                            }
                        }
                        else
                        {
                            for (int d = 1; d <= 26; d++)
                            {
                                tmp4 = tmp3 * 13 + d;
                                if (n == 4)
                                {
                                    if (tmp4 == m)
                                    {
                                        s++;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << s << "\n";
}
