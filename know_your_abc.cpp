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
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    sort(vec1.begin(), vec1.end());
    cout << vec1[0] << " " << vec1[1] << " ";
    if (vec1[2] == vec1[0] + vec1[1]) cout << vec1[3] << endl;
    else cout << vec1[2] << endl;
}
