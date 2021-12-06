#include <bits/stdc++.h>
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
    cin >> n; cin.ignore();
    string name;
    int a;
    vector <pair <int, string> > vec1;
    for (int x = 0; x < n; x++)
    {
        getline(cin, name);
        cin >> a; cin.ignore();
        vec1.push_back({a, name});
    }
    int max = -1 * INT_MAX;
    string max_name;
    for (auto a : vec1)
    {
        if (a.first > max) {max = a.first; max_name = a.second;}
    }
    cout << max_name << endl;
}
