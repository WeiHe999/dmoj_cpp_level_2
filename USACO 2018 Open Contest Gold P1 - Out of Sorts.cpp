#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, ans = 0;
    cin >> n;
    vector<int> vec1(n+1), vec1a(n+1), vec2(n+1), m1(n+1);
    vector<pair<int, int> > p1;
    for (int i = 1; i<=n; i++)
    {
        cin >> a;
        p1.push_back({a, i});
    }
    sort(p1.begin(), p1.end());
    for (int i = 0; i<n; i++)
    {
       m1[p1[i].second] = i+1;
    }
    
    for (int i = 1; i<=n; i++)
    {
        if (m1[i] > i)
        {
            vec2[m1[i] ] = 1;
        }
    } 
    // psa
    for (int i = 1; i<=n; i++) vec2[i] = vec2[i-1] + vec2[i];
    //count
    int num_right = 0;
    for (int i = 1; i<=n; i++)
    {
        if (m1[i] > i)
        {
            num_right ++;
            ans = max(ans, num_right - vec2[i]);
        }
    }
    if (ans==0) cout << 1 << endl;
    else cout << ans << endl;
    
    
}
