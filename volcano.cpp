#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stdio.h>

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
      vv.push_back (stoi (word));
    }
  return vv;
}



int main()
{

  string line;
  getline(cin, line);
  vector <int> vec1 = split(line);
  int n = vec1[0];
  int q = vec1[1];
  vector <double> pos;
  for (int a = 0; a < n; a++)
  {
      getline(cin, line);
      vec1 = split(line);
      pos.push_back(sqrt(pow(vec1[0], 2) + pow(vec1[1], 2)));
  }
  sort(pos.begin(), pos.end());
  //print(pos);
  

  int arr[q];
  for(int i = 0; i < q; i++) scanf("%d", &arr[i]);
  
  for (int b = 0; b < q; b++)
  {
      int count = upper_bound (pos.begin(), pos.end(), double(arr[b])) - pos.begin();
      cout << count << "\n";
  }
  return 0;
}
