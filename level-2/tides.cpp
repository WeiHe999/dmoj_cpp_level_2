#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi (word));
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
  int s = min_element(vec1.begin(), vec1.end()) - vec1.begin();
  int l = max_element(vec1.begin(), vec1.end()) - vec1.begin();
  int a = 0;
  if (l > s)
  {
      for (int x = s + 1; x <= l; x++)
      {
          if (vec1[x] < vec1[x - 1])
          {
              cout << "unknown" << endl;
              a = 1;
              break;
          }
      }
      if (a == 0)
      {
          cout << vec1[l] - vec1[s] << endl;
          a = 1;
      }
  }
  if (a == 0)
  {
      cout << "unknown" << endl;
  }
  return 0;
}
