#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string alpha, s;
    getline(cin, alpha);
    getline(cin, s);
    string hum = alpha;
    int num_hums = 1;
    int ind;
    while (true)
    {
        ind = 0;
        for (int i = 0; i < hum.size() && ind < s.size(); i++) if (hum[i] == s[ind]) ind++;
        if (ind == s.size())
        {
            cout << num_hums << endl;
            break;
        }
        num_hums++;
        hum += alpha;
    }
}
