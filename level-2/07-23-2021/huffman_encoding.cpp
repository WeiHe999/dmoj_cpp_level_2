#include <iostream>
#include <string>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string str1;
    getline(cin, str1);
    int s;
    cin >> s;
    string min_s = str1.substr(0, s);
    for (int x = 1; x < str1.length() - s; x++)
    {
        if (min_s.compare(str1.substr(x, s)) > 0)
        {
            min_s = str1.substr(x, s);
        }
    }
    cout << min_s;
}
