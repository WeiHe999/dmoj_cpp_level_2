#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string a, b, text;
    getline(cin, a);
    getline(cin, b);
    unordered_map <char, char> decoder;
    for (int x = 0; x < a.length(); x++)
    {
        decoder[b[x]] = a[x];
    }
    getline(cin, text);
    string str1 = "";
    for (auto c : text)
    {
        if (decoder.find(c) != decoder.end())
        {
            str1 += decoder[c];
        }
        else
        {
            str1 += '.';
        }
    }
    cout << str1;
}
