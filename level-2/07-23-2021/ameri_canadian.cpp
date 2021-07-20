#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string a;
    getline(cin, a);
    int b;
    while (a != "quit!")
    {
        if (a.length() > 4)
        {
            b = a.find("or");
            if (b == a.length() - 2)
            {
                if (a[b - 1] != 'a' && a[b - 1] != 'e' && a[b - 1] != 'i' && a[b - 1] != 'o' && a[b - 1] != 'u' && a[b - 1] != 'y')
                {
                    a.replace(a.find("or"), 3, "our");
                }
            }
        }
        cout << a << endl;
        getline(cin, a);
    }
}
