#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string a;
    getline(cin, a);
    if (!next_permutation(a.begin(), a.end()))
    {
        cout << 0 << endl;
        return 0;
    }
    for (auto b : a) cout << b;
    cout << endl;
}
