#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    vector <int> vec1, vec2;
    for (int i = 1; i <= min(9999, n); i++)
    {
        cout << i << " " << i << "\n" << flush;
        cin >> a >> b;
        if (a == b) return 0;
        vec1.emplace_back(a);
        vec2.emplace_back(b);
    }
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = i + 1; j < vec2.size(); j++)
        {
            if (vec1[i] == vec2[j])
            {
                cout << i + 1 << " " << j + 1 << "\n" << flush;
                return 0;
            }
        }
    }
    cout << "-1\n";
}
