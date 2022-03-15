#include <bits/stdc++.h>
using namespace std;

void find_all(int x, int prod, int sum, int n, vector <int> vec1, vector <int> vec2, int &b)
{
    if (x == n)
    {
        if (sum > 0 && abs(prod - sum) < b) b = abs(prod - sum);
        return;
    }
    find_all(x + 1, prod, sum, n, vec1, vec2, b);
    find_all(x + 1, prod * vec1[x], sum + vec2[x], n, vec1, vec2, b);
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, b = INT_MAX, c, d;
    vector <int> vec1, vec2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> d;
        vec1.emplace_back(c);
        vec2.emplace_back(d);
    }
    find_all(0, 1, 0, n, vec1, vec2, b);
    cout << b << endl;
}
