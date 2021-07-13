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
    vector <pair<int, int> > danger = {{0, -1}, {0, -2}, {0, -3}, {1, -3}, {2, -3}, {3, -3}, {3, -4}, {3, -5},
      {4, -5}, {5, -5}, {5, -4}, {5, -3}, {6, -3}, {7, -3}, {7, -4}, {7, -5}, {7, -6}, {7, -7},
      {6, -7}, {5, -7}, {4, -7}, {3, -7}, {2, -7}, {1, -7}, {0, -7}, {-1, -7}, {-1, -6}, {-1, -5}};
    string line;
    pair<int, int> pos = {-1, -5};
    int check;
    vector <string> vec1;
    while (true)
    {
      getline(cin, line);
      check = 0;
      vec1 = split(line);
      if (vec1[0] == "l")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.first -= 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "r")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.first += 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "u")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.second += 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "d")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.second -= 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "q")
      {
          break;
      }
   }
}
