#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
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
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++) s += vec1[k];
            for (int a = i; a <= j; a++)
            {
                if (vec1[a] * (j - i + 1) == s) 
                {
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
}
