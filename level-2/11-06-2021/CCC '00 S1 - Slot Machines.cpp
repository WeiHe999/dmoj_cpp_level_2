#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int q, a, b, c, count = 0, jar_n = 1;
    cin >> q >> a >> b >> c;
    vector <int> jars = {a, b, c};
    while (q != 0)
    {
        if (jar_n == 1)
        {
            if (jars[jar_n - 1] == 34)
            {
                jars[jar_n - 1] = 0;
                q += 29;
            }
            else
            {
                jars[jar_n - 1]++;
                q--;
            }
            jar_n = 2;
            count++;
        }
        else if (jar_n == 2)
        {
            if (jars[jar_n - 1] == 99)
            {
                jars[jar_n - 1] = 0;
                q += 59;
            }
            else
            {
                jars[jar_n - 1]++;
                q--;
            }
            jar_n = 3;
            count++;
        }
        else if (jar_n == 3)
        {
            if (jars[jar_n - 1] == 9)
            {
                jars[jar_n - 1] = 0;
                q--;
                q += 9;
            }
            else
            {
                jars[jar_n - 1]++;
                q--;
            }
            jar_n = 1;
            count++;
        }
    }
    cout << "Martha plays " << count << " times before going broke." << endl;
}
