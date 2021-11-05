#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int q, a;
    cin >> q;
    char op;
    vector <int> vec1;
    for (int x = 0; x < q; x++)
    {
        cin >> op >> a;
        if (op == 'F') vec1.insert(vec1.begin(), a);
        else if (op == 'E') vec1.insert(vec1.end(), a);
        else vec1.erase(find(vec1.begin(), vec1.end(), a));
    }
    for (auto b : vec1) cout << b << endl;
}
