#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, l;
    cin >> n >> l; cin.ignore();
    string s, s2;
    vector <string> vec1;
    for (int x = 0; x < n; x++)
    {
        getline(cin, s);
        s2 = s;
        reverse(s2.begin(), s2.end());
        if (s.compare(s2) < 0) vec1.emplace_back(s);
        else vec1.emplace_back(s2);
    }
    sort(vec1.begin(), vec1.end());
    for (auto a : vec1) cout << a;
    cout << endl;
}
