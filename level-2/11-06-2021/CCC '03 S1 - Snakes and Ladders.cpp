#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int place = 1, x;
    while (place != 100)
    {
        cin >> x;
        if (!x) break;
        if (place + x <= 100) place += x;
        if (place == 9) place = 34;
        else if (place == 40) place = 64;
        else if (place == 67) place = 86;
        else if (place == 99) place = 77;
        else if (place == 90) place = 48;
        else if (place == 54) place = 19;
        cout << "You are now on square " << place << endl;
    }
    if (place == 100) cout << "You Win!" << endl;
    else cout << "You Quit!" << endl;
}
