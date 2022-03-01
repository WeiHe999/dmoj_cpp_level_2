#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string a;
    getline(cin, a);
    sort(a.begin(), a.end());
    cout << a << endl;
    while (next_permutation(a.begin(), a.end())) cout << a << endl;
}
