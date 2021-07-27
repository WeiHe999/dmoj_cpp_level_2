#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    getline(cin, line);
    string str1;
    for (int i = 0; i < line.length(); i++)
    {
        if ((line[i] == 'A' && line[i + 1] != 'A') || (line[i] != 'A' && line[i + 1] == 'A'))
        {
            str1 += line[i];
        }
        else
        {
            str1 += line[i];
            str1 += " ";
        }
    }
    cout << str1 << endl;
}
