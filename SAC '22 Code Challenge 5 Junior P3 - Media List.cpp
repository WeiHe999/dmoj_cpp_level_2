#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, b, c;
    cin >> n >> q;
    string word;
    vector <unordered_set <string> > vec1(n + 1);
    for (int x = 0; x < q; x++)
    {
        cin >> b >> c >> word;
        if (b == 1)
        {
            if (vec1[c].count(word)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else vec1[c].insert(word);
    }
}
