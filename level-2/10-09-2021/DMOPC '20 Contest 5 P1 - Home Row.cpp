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
    cin.sync_with_stdio (0); cin.tie (0);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int ind = 0;
    bool flag = false;
    while (ind < str1.size() && ind < str2.size())
    {
        if (str1[ind] == str2[ind]) ind++;
        else {flag = true; break;}
    }
    if (flag) cout << str1.size() + str2.size() - 2 * ind << endl;
    else
    {
        int a = str1.size(), b = str2.size();
        cout << abs(a - b) << endl;
    }
}
