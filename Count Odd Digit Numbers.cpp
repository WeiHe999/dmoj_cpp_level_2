#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    string a = "9", b = "1";
    for (int x = 1; x < to_string(n).size(); x += 2)
    {
        s += stol(a) - stol(b) + 1;
        a += "99";
        b += "00";
    }
    if (to_string(n).size() % 2 == 1) s += n - stol(b) + 1;
    cout << s << endl;
}
