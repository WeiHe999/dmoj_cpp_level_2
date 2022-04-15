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
    long long n, m, a;
    cin >> n >> m;
    vector <vector <long long> > vec1;
    vector <long long> tmp;
    for (long long x = 0; x < n; x++)
    {
        tmp = {};
        for (long long y = 0; y < m; y++)
        {
            cin >> a;
            tmp.emplace_back(a);
        }
        vec1.push_back(tmp);
    }
    for (long long b = 0; b < vec1.size(); b++)
    {
        for (long long c = 0; c < vec1[0].size(); c++)
        {
            
            long long up, right, down, left, minimum, maximum;
            if (b == 0) up = 0;
            else up = vec1[b - 1][c];
            if (c == 0) left = 0;
            else left = vec1[b][c - 1];
            minimum = max(up, left);
            if (b == vec1.size() - 1 || vec1[b + 1][c] == 0) down = 1000000000000000000;
            else down = vec1[b + 1][c];
            if (c == vec1[0].size() - 1 || vec1[b][c + 1] == 0) right = 1000000000000000000;
            else right = vec1[b][c + 1];
            maximum = min(down, right);
            // cout << b << " " << c << "    " << minimum << " " << maximum << endl;            
            
            
            if (vec1[b][c] == 0)
            {
                if (maximum - minimum > 1)
                {
                    // cout << "fill " << b << " " << c << ": " << minimum + 1 << endl;
                    vec1[b][c] = minimum + 1;
                }
                else
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
            else
            {
                if (vec1[b][c]<=minimum || vec1[b][c]>=maximum)
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    for (auto d : vec1)
    {
        vector <long long>  vec2 = d;
        sort(vec2.begin(), vec2.end());
        if (vec2!=d) 
         {
             cout << -1 << endl;
             return 0;
         }
        for (auto e : d)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}
