#include <bits/stdc++.h>

using namespace std;

int main() {

  vector<vector<int> > myvector={{1,2,3}, {4,5,6}, {7,8,9}};

  // step-1: reverse the vector
  reverse(myvector.begin(), myvector.end());

  // step-2: flip elements along diagonal
  int size = myvector.size();
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < i; ++j) {
      swap(myvector[i][j], myvector[j][i]);
    }
  }

  //print the rotated 2D vector
  for (int i = 0; i < myvector.size(); i++) {
    for (int j = 0; j < myvector[0].size(); j++) {
      cout << myvector[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
