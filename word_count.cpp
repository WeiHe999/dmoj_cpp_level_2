#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    string line;
    vector <string> vec1;
    int s1;
    int s2;
    for (int x = 0; x < 5; x++)
    {
        getline(cin, line);
        vec1 = split(line);
        s2 = 0;
        for (auto w : vec1)
        {
            s1 = 0;
            for (int a = 0; a < w.length(); a++)
            {
                if (isalpha(w[a]))
                {
                    s1++;
                }
                else
                {
                    break;
                }
            }
            if (s1 > 3)
            {
                s2++;
            }
        }
        cout << s2 << endl;
    }
}
