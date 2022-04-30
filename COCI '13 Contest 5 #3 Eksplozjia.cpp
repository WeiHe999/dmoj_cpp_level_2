#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

string find_match(string s, string bomb, int k)
{
    string str1;
    int a = k;
    for (auto x : bomb)
    {
        if (s[a] != x) return str1;
        str1 += s[a];
        a++;
    }
    return str1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s, bomb, str1="";
    cin >> s >> bomb;
    int b = bomb.size();
    for (int i=0; i<s.size(); i++)
    {
        str1 += s[i];
        if (str1.size()>=b)
        {
            if (str1.substr(str1.size()-b)==bomb)
            {
                //explode
                for (int j=0; j<b; j++) str1.pop_back();
                //cout << "after bomb, str1=" << str1 << endl;
            }
        }
    }

  
    if (str1.size() != 0) cout << str1 << endl;
    else cout << "FRULA" << endl;
}
