#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0;
    cin >> n;
    for (int a = 1; a < n - 2; a++)
    {
        for (int b = a + 1; b < n - 1; b++)
        {
            for (int c = b + 1; c < n; c++)
            {
                s++;
            }
        }
    }
    cout << s << "\n";
}
