#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

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
    vector <pair <int, string> > vec1;
    string name;
    int score;
    for (int x = 0; x < n; x++)
    {
        cin >> name >> score;
        vec1.push_back({score, name});
    }
    sort(vec1.begin(), vec1.end());
    cout << vec1[n / 2].second << endl;
}
