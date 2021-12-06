#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    unordered_map <char, int> map1 = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10},
    {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23},
    {'Y', 24}, {'Z', 25}};
    string key, line;
    getline(cin, key);
    getline(cin, line);
    string str1;
    for (int x = 0; x < line.length(); x++)
    {
        if (isalpha(line[x]))
        {
            str1 += line[x];
        }
    }
    int ind;
    for (int a = 0; a < key.length(); a++)
    {
        ind = a;
        while (ind < str1.length())
        {
            if (int(str1[ind]) + map1[key[a]] <= 90)
            {
                str1[ind] = char(int(str1[ind]) + map1[key[a]]);
            }
            else
            {
                str1[ind] = char(64 + (map1[key[a]] - (90 - int(str1[ind]))));
            }
            ind += key.length();
        }
    }
    cout << str1 << endl;
}
