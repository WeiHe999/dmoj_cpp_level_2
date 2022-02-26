#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> psa = {0};
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        psa.emplace_back(psa[x] + a);
    }
    for (int y = 1; y < psa.size(); y++)
    {
        if (psa[y] == psa.back() - psa[y])
        {
            cout << y << endl;
            return 0;
        }
    }
    cout << "Andrew is sad." << endl;
}

f
