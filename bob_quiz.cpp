#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n, m;
    cin >> n >> m; cin.ignore();
    string line;
    getline(cin, line);
    for (auto a : line)
    {
        if (a == 'o') m++;
        if (a == 'x')
        {
            if (m != 0) m--;
        }
    }
    cout << m << endl;
}
