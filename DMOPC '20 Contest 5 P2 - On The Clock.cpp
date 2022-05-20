#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int x1, y1, f, x2, y2;
    cin >> x1 >> y1;
    string str1=to_string(x1)+"*"+to_string(y1);
    f = __gcd(x1, y1);
    //cout << "f=" << f << endl;
    x1 = x1/f;
    y1 = y1/f;
    set<pair<int, int> > s1, s2;
    if (x1==1 && y1==1)
    {
      s1.insert({1, 1});  
    }
    else
    {
        for (int i=1; i<x1; i++)
        {
            y2 = ceil((y1 * 1.0 / x1) * i);
            s1.insert({i, y2});
            s1.insert({i+1, y2});
        }
        for (int i=1; i<y1; i++)
        {
            x2 = ceil((x1 * 1.0 / y1) * i);
            s1.insert({x2, i});
            s1.insert({x2, i+1});
        } 
    }
 
    for (int k=1; k<=f; k++)
    {
        for (auto x: s1)
        {
            s2.insert({x.first+ (k-1)*x1, x.second+(k-1)*y1});
        }
        
    }
    cout << s2.size() << endl;
    for (auto x: s2)
    {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
    
}
