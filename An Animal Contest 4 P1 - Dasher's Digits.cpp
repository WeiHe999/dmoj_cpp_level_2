#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, b;
    cin >> n >> m; cin.ignore();
    string a, str1, str2, str3, str4;
    getline(cin, a);
    vector <int > v1;
    for (int x = 0; x < m; x++)
    {
        cin >> b;
        v1.push_back(b);
    }
    vector <vector<int> > vec1;
    int max_value = -1, sep_pos = -1, ind = 0;
    for (int x = 0; x < n; x++)
    {
        if (a[x]=='0') 
        {
            if(v1[ind] >= max_value)
            {
                max_value = v1[ind];
                sep_pos = x;
            }
            ind ++;
        }
    }
    
    str1 = a.substr(0, sep_pos);
    str3 = "";
    for (int i=0; i<str1.size(); i++)
    {
        if (str1[i]!='0') str3+=str1[i];
    }
    
    str2 = a.substr(sep_pos +1);
    str4 = "";
    for (int i=0; i<str2.size(); i++)
    {
        if (str2[i]!='0') str4+=str2[i];
    }

    cout << str4 + str3 << endl;
}
