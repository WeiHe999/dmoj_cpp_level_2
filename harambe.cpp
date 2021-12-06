#include <iostream>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    getline(cin, line);
    int c1 = 0;
    int c2 = 0;
    for (auto a : line)
    {
        if (islower(a)) c1++;
        if (isupper(a)) c2++;
    }
    if (c1 > c2)
    {
        for (auto &b : line)
        {
            b = tolower(b);
        }
    }
    if (c1 < c2)
    {
        for (auto &b : line)
        {
            b = toupper(b);
        }
    }
    cout << line << endl;
}
