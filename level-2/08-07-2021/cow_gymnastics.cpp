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
    cin.sync_with_stdio (0);
    cin.tie (0);
    int k, n;
    cin >> k >> n;
    cin.ignore();
    vector <vector<int> > vec2;
    vector <int> vec1;
    for (int x = 0; x < k; x++)
    {
        string line;
        getline(cin, line);
        vec1 = split(line);
        vec2.push_back(vec1);
    }
    int s1 = 0;
    int s2;
    for (int a = 0; a < n - 1; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            int cow_1 = vec2[0][a];
            int cow_2 = vec2[0][b];
            s2 = 0;
            for (int c = 1; c < k; c++)
            {
                int index_cow_1 = find(vec2[c].begin(), vec2[c].end(), cow_1) - vec2[c].begin();
                int index_cow_2 = find(vec2[c].begin(), vec2[c].end(), cow_2) - vec2[c].begin();
                if (index_cow_1 < index_cow_2) s2++;
            }
            if (s2 == k-1) s1++;
        }
    }
    cout << s1 << endl;
}
