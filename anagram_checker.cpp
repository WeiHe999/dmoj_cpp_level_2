#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());
    if (str1 == str2)
    {
        cout << "Is an anagram." << endl;
    }
    else
    {
        cout << "Is not an anagram." << endl;
    }
}
