nclude <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <cmath>
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
    string line;
    getline(cin, line);
    vector <string> vec1 = split(line);
    stack <double> s1;
    double tmp1;
    double tmp2;
    for (auto a : vec1)
    {
        if (a == "+")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(tmp2 + tmp1);
        }
        else if (a == "-")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(tmp2 - tmp1);
        }
        else if (a == "*")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(tmp2 * tmp1);
        }
        else if (a == "/")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push((tmp2 / 1.0) / tmp1);
        }
        else if (a == "%")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            double current = 0.0;
            while (current + tmp1 <= tmp2)
            {
                current += tmp1;
            }
            current = tmp2 - current;
            s1.push(current);
        }
        else if (a == "^")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(pow(tmp2, tmp1));
        }
        else
        {
            s1.push(stoi(a));
        }
    }
    double ans = (s1.top() / 1.0);
    cout << fixed << setprecision(1) << ans << endl;
}
