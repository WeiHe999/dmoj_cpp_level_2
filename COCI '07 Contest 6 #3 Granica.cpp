#include <bits/stdc++.h>
using namespace std;

bool check(int m, int n, vector <int> vec1)
{
   for (int i = 1; i < n; i++) if (vec1[i] % m != vec1[0] % m) return false;
   return true;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1(100);
    unordered_set<int> s1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec1[i] = a;
    }
    int r = abs(vec1[0] - vec1[1]);
    for (int d = 1; d * d <= r; d++)
    {
        if (r % d != 0 ) continue;
        int m1 = d, m2 = r / d;
        if (check(m1, n, vec1) && m1 != 1 ) s1.insert(m1);
        if (check(m2, n, vec1) && m2 != m1 ) s1.insert(m2);
    }
    int ind = 0;
    for (auto x: s1)
    {
        if (ind==s1.size()-1) cout << x;
        else cout << x << " ";
        ind ++;
    }
    cout << endl;
}
