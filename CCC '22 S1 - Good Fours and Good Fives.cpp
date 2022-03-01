#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, cnt = 0;
    cin >> n;
    for (int x = 0; x <= (n / 5); x++)
    {
        if ((n - (x * 5)) % 4 == 0) cnt++;
    }
    cout << cnt << endl;
}
