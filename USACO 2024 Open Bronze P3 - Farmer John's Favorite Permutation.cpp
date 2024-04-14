#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n;
        cin >> n;
        vector <int> vec1(n - 1);
        for (int i = 0, a; i < n - 1; i++)
        {
            cin >> a;
            vec1[i] = a;
        }
        vector <bool> vec2(n + 1);
        for (auto x : vec1) vec2[x] = 1;
        vector <int> vec3;
        for (int i = 1; i <= n; i++) if (!vec2[i]) vec3.push_back(i);
        int s = 0;
        for (auto x : vec1) if (x == 1) s++;
        if (vec3.size() > 2 || vec1.back() != 1 || (vec3.size() == 2 && s != 2))
        {
            cout << -1 << "\n";
            continue;
        }
        vector <int> vec4(n);
        if (vec3.size() == 1)
        {
            vec4[0] = 1;
            vec4[n - 1] = vec3[0];
        }
        else
        {
            vec4[0] = vec3[0];
            vec4[n - 1] = vec3[1];
        }
        int l = 0, r = n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (vec4[l] > vec4[r])
            {
                l++;
                vec4[l] = vec1[i];
            }
            else
            {
                r--;
                vec4[r] = vec1[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i) cout << " ";
            cout << vec4[i];
        }
        cout << "\n";
    }
}
