#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> vec1, int num, vector <int> &vec2, int k)
{
    int ind = 1;
    for (int i = 1; i <= k; i++)
    {
        bool flag = false;
        for (int j = 1; j < vec1.size(); j++)
        {
            if (j < ind) continue;
            if (vec1[j] - vec1[ind] > num)
            {
                vec2.emplace_back(vec1[j - 1]);
                flag = true;
                for (int a = j - 1; a < vec1.size(); a++)
                {
                    if (vec1[a] - vec1[j - 1] > num)
                    {
                        ind = a;
                        break;
                    }
                }
                break;
            }
        }
        if (!flag) 
        {
           vec2.emplace_back(vec1.back());
           flag = true;
           ind = vec1.size() - 1;
        }
    }
    if (vec1.back() - vec2.back() > num) return false;
    for (int i = 1; i <= k - vec2.size(); i++) vec2.emplace_back(vec1.back());
    return true;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vec2;
    int n, k;
    cin >> n;
    while (n != 0)
    {
        cin >> k;
        vector <int> vec1(n + 1), vec2, final_vector;
        for (int i = 1; i <= n; i++) cin >> vec1[i];
        int l = 0, r = vec1[n] - vec1[1], ans;
        while (l <= r)
        {
            vec2 = {};
            int m = (l + r) / 2;
            if (check(vec1, m, vec2, k))
            {
                r = m - 1;
                ans = m;
                final_vector = vec2;
            }
            else l = m + 1;
        }
        for (auto x : final_vector) cout << x << " ";
        cout << "\n" << ans << "\n\n";
        cin >> n;
    }
}
