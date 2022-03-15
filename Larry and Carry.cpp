#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> vec1)
{
    for (int x = 0; x < 9; x++)
    {
        bool flag = true;
        int sum = 0;
        for (auto y : vec1)
        {
            string str1 = to_string(y);
            reverse(str1.begin(), str1.end());
            if (x <= str1.size() - 1)
            {
                flag = false;
                if ((sum + str1[x] - '0') > 9)
                {
                    return true;
                }
                sum += str1[x] - '0';
            }
        }
        if (flag) break;
    }
    return false;
}

void combinations(int ind, vector <int> &vec1, vector <int> &vec2, int &max_k)
{
    if (vec2.size() > max_k)
    {
        if (!check(vec2))
        {
            max_k = vec2.size();
        }
    }
    if (vec2.size() >= vec1.size()) return;
    for (int x = ind + 1; x < vec1.size(); x++)
    {
        vector <int> vec4 = vec2;
        vec4.emplace_back(vec1[x]);
        combinations(x, vec1, vec4, max_k);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1, vec2;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    int max_k = 0;
    combinations(-1, vec1, vec2, max_k);
    cout << max_k << endl;
}

