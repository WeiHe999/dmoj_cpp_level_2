#include <bits/stdc++.h>
using namespace std;

const long long MM = 1e9;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    vector <long long> vec1(n + 1);
    for (long long i = 0; i < n; i++) cin >> vec1[i];
    vector <vector <long long> > vec2(n + 1, vector <long long>(4));
    stack <pair <long long, long long> > s1, s2, s3, s4;
    s1.push({MM, -1});
    for (long long i = 0; i < n; i++)
    {
        while (s1.top().first <= vec1[i]) s1.pop();
        vec2[i][0] = s1.top().second + 1;
        s1.push({vec1[i], i});
    }
    s2.push({MM, n});
    for (long long i = n - 1; i >= 0; i--)
    {
        while (s2.top().first < vec1[i]) s2.pop();
        vec2[i][1] = s2.top().second - 1;
        s2.push({vec1[i], i});
    }
    s3.push({-1 * MM, -1});
    for (long long i = 0; i < n; i++)
    {
        while (s3.top().first >= vec1[i]) s3.pop();
        vec2[i][2] = s3.top().second + 1;
        s3.push({vec1[i], i});
    }
    s4.push({-1 * MM, n});
    for (long long i = n - 1; i >= 0; i--)
    {
        while (s4.top().first > vec1[i]) s4.pop();
        vec2[i][3] = s4.top().second - 1;
        s4.push({vec1[i], i});
    }
    for (long long i = 0; i < n; i++)
    {
        s += (long long)vec1[i] * (vec2[i][1] - i + 1) * (i - vec2[i][0] + 1) - (long long)vec1[i] * (vec2[i][3] - i + 1) * (i - vec2[i][2] + 1);
    }
    cout << s << "\n";
}
