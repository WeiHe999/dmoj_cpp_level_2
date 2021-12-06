#include <iostream>
#include <vector>
#include <sstream>
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
    string line;
    getline(cin, line);
    vector <int> vec1;
    vector <int> vec2;
    int ind;
    int count;
    while (line != "0")
    {
        vec2 = {};
        vec1 = split(line);
        vec1.assign(vec1.begin() + 1, vec1.end());
        for (int a = 1; a < vec1.size(); a++)
        {
            vec2.emplace_back(vec1[a] - vec1[a - 1]);
        }
        count = 0;
        for (int b = 0; b < vec2.size(); b++)
        {
            if (b != 0 && vec2[b] == vec2[0])
            {
                vector<int> v1;
                vector<int> v2;
                v1.assign(vec2.begin() + b, vec2.end());
                v2.assign(vec2.begin(), vec2.begin() + v1.size());
                if (v1 == v2) break;
            }
            count++;
        }
        cout << count << endl;
        getline(cin, line);
    }
}
