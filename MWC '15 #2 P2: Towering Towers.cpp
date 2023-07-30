#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1);
    stack <pair <int, int> > s1;
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    for (int i = 1; i <= n; i++)
    {
        while (!s1.empty() && s1.top().first <= vec1[i]) s1.pop();
        if (s1.empty()) cout << i-1 << " ";
        else cout << i - s1.top().second << " ";
        s1.push({vec1[i], i});
    }
    cout << "\n";
}
