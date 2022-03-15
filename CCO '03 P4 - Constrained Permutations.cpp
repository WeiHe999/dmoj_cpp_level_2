#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a, b, s = 0;
    cin >> n >> k;
    vector <pair <int, int> > vec1;
    vector <int> permutation;
    for (int x = 0; x < k; x++)
    {
        cin >> a >> b;
        vec1.push_back({a, b});
    }
    for (int y = 1; y <= n; y++) permutation.emplace_back(y);
    do
    {
        bool flag1 = true;
        for (auto z : vec1)
        {
            bool flag2 = false;
            for (int c = 0; c < permutation.size(); c++)
            {
                if (permutation[c] == z.first) break;
                if (permutation[c] == z.second)
                {
                    flag2 = true;
                    break;
                }
            }
            if (flag2)
            {
                flag1 = false;
                break;
            }
        }
        if (flag1) s++;
    } while(next_permutation(permutation.begin(), permutation.end()));
    cout << s << endl;
}

