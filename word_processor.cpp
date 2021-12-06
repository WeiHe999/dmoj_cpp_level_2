#include <iostream>
#include <vector>
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
    int n, k;
    cin >> n >> k; cin.ignore();
    string line;
    getline(cin, line);
    vector <string> words = split(line);
    int length = 0;
    for (int a = 0; a < words.size(); a++)
    {
        string word = words[a];
        if (a == 0)
        {
            cout << word;
            length = word.length();
        }
        else
        {
            if (length + word.length() > k)
            {
                cout << endl << word; length = word.length();
            }
            else
            {
                cout << " " << word;
                length += word.length();
            }
        }
    }
    cout << endl;
}
