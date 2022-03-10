#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    string b1, b2, b3, b4, a;
    cin >> n >> b1 >> b2 >> b3 >> b4;
    bool flag;
    vector <string> vec1 = {b1, b2, b3, b4};
    sort(vec1.begin(), vec1.end());
    vector <string> vec2 = vec1;
    for (int x = 0; x < n; x++)
    {
        vec2 = vec1;
        cin >> a;
        flag = false;
        do
        {
            flag = true;
            for (int y = 0; y < a.size(); y++)
            {
                if (vec2[y].find(a[y]) == -1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) break;
        
        } while (next_permutation(vec2.begin(), vec2.end()));
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
