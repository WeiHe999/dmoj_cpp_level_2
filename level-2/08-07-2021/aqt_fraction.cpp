#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
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
    int a;
    cin >> a;
    for (int x = 0; x < a; x++)
    {
        long long n, d;
        cin >> n >> d;
        long long b = __gcd(n, d);
        long long d1 = d / b;
        int s1 = 0;
        int s2 = 0;
        while (d1 % 2 == 0) 
        {
            d1 = d1 / 2;
            s1++;
        }
        while (d1 % 5 == 0) 
        {
            d1 = d1 / 5;
            s2++;
        }
        if (d1 != 1) cout << -1 << endl;
        else
        {
            if (s1 > s2) cout << s1 << endl;
            else cout << s2 << endl;
        }
    }
}
