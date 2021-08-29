#include <iostream>
#include <climits>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n; cin.ignore();
    int s;
    int maximum = -1 * INT_MAX;
    for (int x = 0; x < n; x++)
    {
        string a;
        getline(cin, a);
        s = 0;
        for (auto b : a)
        {
            s += b - '0';
        }
        if (s > maximum) maximum = s;
    }
    cout << maximum << endl;
}
