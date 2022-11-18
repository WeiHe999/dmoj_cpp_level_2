#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int w, n, sum = 0;
    cin >> w >> n;
    vector <int> vec1(n);
    for (int x = 0; x < n; x++) cin >> vec1[x];
    if (n <= 4)
    {
        int s = 0, sum = 0;
        for (int a = 0; a < n; a++)
        {
            sum += vec1[a];
            if (sum > w)
            {
                cout << s << "\n";
                return 0;
            }
            s++;
        }
        cout << n << "\n";
    }
    else
    {
        if (sum > w) cout << "0\n";
        else
        {
            for (int k = 0; k < 4; k++)
            {
                sum += vec1[k];
                if (sum > w)
                {
                    cout << k << "\n";
                    return 0;
                }
            }
            for (int k = 4; k < n; k++)
            {
                sum += vec1[k] - vec1[k - 4];
                if (sum > w)
                {
                    cout << k << "\n";
                    return 0;
                }
            }
            cout << n << "\n";
        }
    }
}
