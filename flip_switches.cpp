#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
  cin.sync_with_stdio (0);
  cin.tie (0);
  int n;
  cin >> n;
  cin.ignore();
  string line;
  getline(cin, line);
  int ind = 1;
  int s = 0;
  while (ind != line.size())
  {
      if (line[ind] != line[ind - 1])
      {
          s++;
      }
      ind++;
  }
  if (line.back() == '1')
  {
      cout << s + 1;
  }
  else
  {
      cout << s;
  }
  return 0;
}
