#include <bits/stdc++.h>
using namespace std;

double find_median(vector<long long> scores)
{
  size_t size = scores.size();

  if (size == 0)
  {
    return 0; 
  }
  else
  {
    if (size % 2 == 0)
    {
      return (scores[size / 2 - 1] + scores[size / 2]) / 2.0;
    }
    else 
    {
      return scores[size / 2.0];
    }
  }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n;
    double min1, min2, max1, max2;
    cin >> n;
    vector <long long> vec1(n), v_front, v_back;
    for (long long i = 0; i < n; i++) 
    {
        cin >> vec1[i];
    }
    sort(vec1.begin(), vec1.end());
    for (long long i = 0; i < n; i++) 
    {
       if (i>0) v_back.push_back(vec1[i]);
       if (i<n-1) v_front.push_back(vec1[i]);
    }    
    
    min1 = double(vec1[1]),
    max1 = double(vec1[vec1.size() - 2]);
    min2 = (find_median(v_back) + vec1[0])/2.0;
    max2 = (find_median(v_front) + vec1.back())/2.0;
    
    cout << fixed << setprecision(2) << min(min1, min2) << " " << max(max1, max2) << "\n";
}
