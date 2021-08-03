#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
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
    int q, n;
    cin >> q;
    cin >> n;
    cin.ignore();
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    vector <int> vec1 = split(str1);
    vector <int> vec2 = split(str2);
    int s = 0;
    if (q == 1)
    {
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        int min_e1;
        int min_e2;
        for (int x = 0; x < n; x++)
        {
            min_e1 = vec1[x];
            min_e2 = vec2[x];
            if (min_e1 < min_e2) s += min_e2;
            else s += min_e1;
        }
    }
    if (q == 2)
    {
        sort(vec1.rbegin(), vec1.rend());
        sort(vec2.begin(), vec2.end());
        int max_e1;
        int max_e2;
        for (int x = 0; x < n; x++)
        {
            max_e1 = vec1[x];
            max_e2 = vec2[x];
            if (max_e1 > max_e2) s += max_e1;
            else s += max_e2;
        }
    }
    cout << s << endl;
}
