#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template < typename T > void
print (T t)
{
for (const auto & e:t)
    cout << e << " ";
  cout << endl;
}

vector < int >
split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi (word));
    }
  return vv;
}

int
main ()
{
  cin.sync_with_stdio (0);
  cin.tie (0);


  string line;
  getline (cin, line);
  vector < int >rc;
  rc = split(line);
  int num_rows = rc[0];
  vector < int >v_x;
  vector < int >v_y;
  for (int n = 0; n < num_rows; n++)
    {
      getline (cin, line);
      int found = line.find ("X");

      if (found != std::string::npos)
	{
	  v_x.push_back(n + 1);
	  int cnt = 0;
	  for(char& c : line) {
            if (c=='X') v_y.push_back(cnt+1);
            cnt++;
            }
	}
    }



  int q;
  cin >> q;
  cin.ignore();
  for (int m = 0; m < q; m++)
    {
      getline(cin, line);
      rc = split(line);
      int x1 = rc[1];
      int y1 = rc[0];
      if ((find(v_x.begin(), v_x.end(), x1) != v_x.end()) |
	  (find(v_y.begin(), v_y.end(), y1) != v_y.end())) cout << "Y\n";
      else cout << "N\n";
    }




  return 0;
}
