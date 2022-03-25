#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string w;
    cin >> w;
    int s = 0;
    unordered_set <char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int x = 0; x < 5; x++)
    {
        if (vowels.count(w[x])) s++;
    }
    if (s > 1) cout << "good" << endl;
    else cout << "bad" << endl;
}
