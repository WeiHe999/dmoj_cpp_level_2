#include <bits/stdc++.h>
using namespace std;

void calc(vector <int> &vec1, vector <int> &vec2, int i, int &s, int n)
{
    int tmp = (vec2[n] - (vec2[i] - vec2[i - vec2[n]]) + vec1[n] - (vec1[i - vec2[n]] - vec1[i - vec2[n] - vec1[n]]));
    s = min(tmp - min(vec2[i - vec2[n]] - vec2[i - vec2[n] - vec1[n]], vec1[i] - vec1[i - vec2[n]]), s);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, c, s = INT_MAX;
    string str1;
    cin >> str1;
    n = str1.size();
    vector <int> vec1(n + 1), vec2(n + 1), vec3(n + 1);
    for (int i = 1; i <= n; i++)
    {
        vec1[i] = vec1[i - 1];
        vec2[i] = vec2[i - 1];
        vec3[i] = vec3[i - 1];
        if (str1[i - 1] == 'A') vec1[i]++;
        if (str1[i - 1] == 'B') vec2[i]++;
        if (str1[i - 1] == 'C') vec3[i]++;
    }
    a = vec1[n];
    b = vec2[n];
    c = vec3[n];
    for (int i = 1; i <= n; i++)
    {
        if (i >= a + b)
        {
            calc(vec1, vec2, i, s, n);
            calc(vec2, vec1, i, s, n);
        }
        if (i >= a + c)
        {
            calc(vec1, vec3, i, s, n);
            calc(vec3, vec1, i, s, n);
        }
        if (i >= b + c)
        {
            calc(vec2, vec3, i, s, n);
            calc(vec3, vec2, i, s, n);
        }
    }
    cout << s << "\n";
}
