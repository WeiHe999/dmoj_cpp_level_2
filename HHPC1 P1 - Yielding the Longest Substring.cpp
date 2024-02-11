#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        int n, s = 0;
        string str1;
        cin >> n >> str1;
        vector<pair<int, int> > v1;
        int max1 = -1, c = 1;
        int prev = str1[0] - 'a';
        for (int i=1; i<n; i++)
        {
            if ((str1[i] - 'a') == prev)
            {
                c++;
            }
            else
            {
                v1.push_back({prev, c});
                max1 = max(max1, c);
                prev = str1[i] - 'a';
                c = 1;
            }
            
        }
        v1.push_back({prev, c});
        max1 = max(max1, c);
      
        for (int i = 0; i<v1.size(); i++)
        {
            if (i>0 && i<v1.size()-1 && v1[i].second==1 && v1[i-1].first==v1[i+1].first)
            {
                max1 = max(max1, v1[i-1].second+v1[i+1].second);
            }
        }
        cout << min(n, max1+1) << endl;
        
        
   
    }
}
