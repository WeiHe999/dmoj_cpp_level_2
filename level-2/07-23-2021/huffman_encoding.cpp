#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    vector <string> vec1;
    unordered_map <string, string> decoder;
    for (int x = 0; x < n; x++)
    {
        string line;
        getline(cin, line);
        vec1 = split(line);
        decoder[vec1[1]] = vec1[0];
    }
    string text;
    string str1 = "";
    getline(cin, text);
    while (text != "")
    {
        for (auto x : decoder)
        {
            if (text.find(x.first) == 0)
            {
                text = text.substr(x.first.length(), text.length() - x.first.length());
                str1 += x.second;
            }
        }
    }
    cout << str1;
}
