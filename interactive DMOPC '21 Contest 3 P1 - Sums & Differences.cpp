#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, ans, a1, s = 0;
    cin >> n;
    bool flag = true;
    vector <long long> vec1(n);
    cout << "? " << 2 << " " << 1 << endl << flush;
    cin >> ans;
    a1 = ans;
    for (long long x = 3; x <= n; x++)
    {
        cout << "? " << 1 << " " << x << endl;
        cout << flush;
        cin >> ans;
        vec1[x - 1] = a1 + s - ans;
        s += vec1[x - 1];
    }
    cout << "? " << 1 << " " << 2 << endl << flush;
    cin >> ans;
    vec1[0] = (ans - s) / -2;
    vec1[1] = a1 + vec1[0];
    cout << "! ";
    for (long long a = 0; a < vec1.size(); a++)
    {
        if (a == vec1.size() - 1) cout << vec1[a];
        else cout << vec1[a] << " ";
    }
    cout << endl;
    return 0;
}
