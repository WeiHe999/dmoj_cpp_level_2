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
    int mins;
    cin >> mins;
    int c;
    cin >> c;
    vector <int> vec1;
    for (int x = 0; x < c; x++)
    {
        int a;
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    int ind = 0;
    while (mins >= vec1[ind])
    {
        mins -= vec1[ind];
        ind++;
    }
    cout << ind;
}
