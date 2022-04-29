#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int s, r;
    cin >> s >> r;
    if (s * s > (3.14 * r * r)) cout << "SQUARE" << endl;
    else cout << "CIRCLE" << endl;
}
