include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string previous;
    string a;
    getline(cin, a);
    while (a != "99999")
    {
        if (a[0] - '0' + a[1] - '0' == 0)
        {
            cout << previous << " " << a.substr(2) << endl;
        }
        else if ((a[0] - '0' + a[1] - '0') % 2 == 0)
        {
            cout << "right " << a.substr(2) << endl;
            previous = "right";
        }
        else
        {
            cout << "left " << a.substr(2) << endl;
            previous = "left";
        }
        cin >> a;
    }
}
