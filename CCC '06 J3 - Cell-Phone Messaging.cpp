#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x;
    getline(cin, x);
    vector <string> vec1;
    while (x != "halt")
    {
        vec1.emplace_back(x);
        getline(cin, x);
    }
    unordered_map <char, string> values = {{'a', "2"}, {'b', "22"}, {'c', "222"}, {'d', "3"}, {'e', "33"},
    {'f', "333"}, {'g', "4"}, {'h', "44"}, {'i', "444"}, {'j', "5"}, {'k', "55"}, {'l', "555"},
    {'m', "6"}, {'n', "66"}, {'o', "666"}, {'p', "7"}, {'q', "77"},
    {'r', "777"}, {'s', "7777"}, {'t', "8"}, {'u', "88"}, {'v', "888"},
    {'w', "9"}, {'x', "99"}, {'y', "999"}, {'z', "9999"}};
    for (auto i : vec1)
    {
        int count = 0;
        for (int a = 0; a < i.length(); a++)
        {
            if (a == 0) count += values[i[a]].size();
            else if ((values[i[a]])[0] == (values[i[a - 1]])[0]) count += 2 + values[i[a]].size();
            else count += values[i[a]].size();
        }
        cout << count << endl;
    }
}
