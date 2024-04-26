#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0;
    cin >> n;
    vector <pair<int, int> > vec1;
    for (int i = 0, a; i < 2 * n; i++) 
    {
        cin >> a;
        vec1.push_back({a, i});
    }
    sort(vec1.begin(), vec1.end());
  
    for (int i = 0; i < n; i++) 
    {
        if (vec1[i].first != vec1[i + n].first) 
        {
            s++;
        }
    }
    cout << s << "\n";
    for (int x = 0; x < n; x++) cout << vec1[x].second + 1 << " " << vec1[x+n].second + 1 << "\n";
}
