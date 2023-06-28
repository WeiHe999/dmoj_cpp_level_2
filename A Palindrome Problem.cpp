#include <bits/stdc++.h>
using namespace std;



int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    long long n = str1.size(), s=0;
    vector<long long> va, vb, v1;
    for (long long i=0; i<n; i++)
    {
        if (str1[i]=='a') va.push_back(i);
        else vb.push_back(i);
    }
    if (n%2==0)
    {
        if (va.size()%2==1)
        {
            cout << -1 << endl;
            return 0;
        }
        for (long long i=0; i<va.size()/2; i++)
        {
            s += abs(n-1-va[i] - va[va.size()-1 - i]);
        }
    }
    else
    {
        if (va.size()%2==1) v1 = va;
        else v1 = vb;
        for (long long i=0; i<v1.size()/2; i++)
        {
            s += abs(n-1-v1[i] - v1[v1.size() -1 - i]);
        }
        s += abs(v1[v1.size()/2] - (n/2));
        
    }
    cout << s << endl;
    
    
}
