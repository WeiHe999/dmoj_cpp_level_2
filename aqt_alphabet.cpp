#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string str1;
    getline(cin, str1);
    string alphabet = "abcedfghijklmnopqrstuvwxyz";
    for (auto a : alphabet)
    {
        if (find(str1.begin(), str1.end(), a) == str1.end())
        {
            cout << a << endl;
            break;
        }
    }
}
