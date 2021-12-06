#include <bits/stdc++.h>
using namespace std;

bool check_pattern(string str2, int k)
{
    string first = str2.substr(0, k);
    for(int j=0; j<str2.size(); j+=k) 
    {
        //cout << "extracted="<<str2.substr(j, k) << ", first=" << first << endl;
        if(str2.substr(j, k)!=first) return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >>n;
    for (int i=0; i<n; i++)
    {
        string str1;
        int flag=0;
        cin >> str1;
        int len = str1.size();
        for(int j=1; j<=str1.size()/2; j++)
        {
            if(len%j==0) 
            {
                if (check_pattern(str1, j))
                {
                    cout << len/j << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag==0) cout << 1 << endl;
    }
    
}
