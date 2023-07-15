#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > vec3(651, vector <int>(651)), psa(651, vector <int>(651));

int find(int a, int b, int c, int d)
{
    if (c < 0 || d < 0) return 0;
    int s = psa[c][d];
    if (a > 0) s -= psa[a - 1][d];
    if (b > 0) s -= psa[c][b - 1];
    if (a > 0 && b > 0) s += psa[a - 1][b - 1];
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n), vec2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec1[i] >> vec2[i];
        vec3[vec1[i]][vec2[i]]++;
    }
    for (int i = 0; i <= 650; i++)
    {
        for (int j = 0; j <= 650; j++)
        {
            psa[i][j] = vec3[i][j];
            if (i > 0) psa[i][j] += psa[i - 1][j];
            if (j > 0) psa[i][j] += psa[i][j - 1];
            if (i > 0 && j > 0) psa[i][j] -= psa[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << find(vec1[i] + 1, vec2[i] + 1, 650, 650) + 1 << " ";
        if (vec1[i] == 650 && vec2[i] == 650) cout << n - find(0, 0, vec1[i] - 1, vec2[i] - 1) - vec3[0][vec2[i]] - vec3[vec1[i]][0];
        else if (vec1[i] == 650) cout << n - find(0, 0, vec1[i] - 1, vec2[i] - 1) - vec3[0][vec2[i]];
        else if (vec2[i] == 650) cout << n - find(0, 0, vec1[i] - 1, vec2[i] - 1) - vec3[vec1[i]][0];
        else cout << n - find(0, 0, vec1[i] - 1, vec2[i] - 1);
        cout << "\n";
    }
}
