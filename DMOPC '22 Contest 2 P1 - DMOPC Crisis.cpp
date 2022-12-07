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
    int n, m, r;
    cin >> n;
    m = n/4;
    r = n%4;
    string str4 = "__MM", str1="_", str2="__", str3="__M";
    string final_str = "";
    int cnt = 0;
    for (int i=0; i<m; i++)
    {
        final_str += str4;
        cnt +=2;
    }
    if (r==1) 
    {
        final_str += str1;
    }
    if (r==2) 
    {
        final_str += str2;
    }
    if (r==3) 
    {
        final_str += str3;
        cnt++;
    }
    cout << cnt << endl;
    cout << final_str << endl;
  

}
