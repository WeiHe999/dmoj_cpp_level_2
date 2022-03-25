#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a;
    cin >> n >> q;
    string getorset, shape;
    vector <string> vec1(n, "none");
    for (int x = 0; x < q; x++)
    {
        cin >> getorset >> shape >> a;
        if (getorset == "set")
        {
            vec1[a - 1] = shape;
        }
        else
        {
            if (vec1[a - 1] == "none")
            {
                cout << 0 << endl;
                continue;
            }
            if (shape == vec1[a - 1]) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}
