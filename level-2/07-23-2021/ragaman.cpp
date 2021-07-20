#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int num;
    int length_b = b.length();
    if (a.length() != length_b)
    {
        cout << "N" << endl;
        return 0;
    }
    unordered_map <char, int> map1, map2;
    for (int x = 0; x < a.length(); x++)
    {
        if (map1.find(a[x]) == map1.end())
        {
            map1[a[x]] = 0;
        }
        map1[a[x]]++;
        if (map2.find(b[x]) == map2.end())
            {
                map2[b[x]] = 0;
            }
        map2[b[x]]++;
    }
    int difference = 0;
    for (auto a : map1)
    {
        if (map2.find(a.first) == map2.end())
        {
            difference += a.second;
        }
        else
        {
            difference += abs(a.second - map2[a.first]);
        }
    }
    if (map2.find('*') == map2.end())
    {
        if (difference == 0)
        {
            cout << "A" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    else
    {
        if (difference == map2['*'])
        {
            cout << "A" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}
