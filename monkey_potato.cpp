#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
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
    int k, d;
    cin >> k >> d;
    cin.ignore();
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    sort(vec1.begin(), vec1.end());
    if (vec1.back() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int ind = 0;
        if (vec1[ind] == 0)
        {
            while (vec1[ind] < 1) ind++;
            if (k == 1) cout << vec1[ind] << endl;
            else
            {
                cout << vec1[ind];
                for (int a = 0; a < k - 2; a++) cout << 0;
                cout << vec1[ind] << endl;
            }
        }
        else
        {
            for (int a = 0; a < k; a++) cout << vec1[ind];
            cout << endl;
        }
    }
}
