#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
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
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n;
    cin >> n; cin.ignore();
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    vector <int> vec2;
    int current_cow;
    for (int x = 1; x < vec1[0]; x++)
    {
        vec2 = {};
        current_cow = x;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                vec2.emplace_back(current_cow);
                continue;
            }
            current_cow = vec1[i - 1] - current_cow;
            if (current_cow <= 0) break;
            if (find(vec2.begin(), vec2.end(), current_cow) != vec2.end()) break;
            vec2.emplace_back(current_cow);
            if (i == n - 1)
            {
                print(vec2);
                return 0;
            }
        }
    }
}
