#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int x, m;
    cin >> x;
    cin >> m;
    int exists = 0;
    for (int s = 2; s < m; s++)
    {
        if ((x * s) % m == 1)
        {
            cout << s << endl;
            exists = 1;
            break;
        }
    }
    if (exists == 0)
    {
        cout << "No such integer exists." << endl;
    }
}
