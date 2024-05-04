#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <long long> vec1(32), vec2(300005);
    long long n, k, s = 0;
    cin >> n >> k;
    string str1;
    for (int i = 0; i < n; i++)
    {
        cin >> str1;
        vec2[i] = str1.size();
        s += vec1[vec2[i]];
        if (i >= k) vec1[vec2[i - k]]--;
        vec1[vec2[i]]++;
    }
    cout << s << "\n";
}
