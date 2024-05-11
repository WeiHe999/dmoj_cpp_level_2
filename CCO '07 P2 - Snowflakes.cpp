#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <vector <int> > vec1(n, vector <int>(6));
    for (int i = 0; i < n; i++) for (int j = 0; j < 6; j++) cin >> vec1[i][j];
    set <vector <int> > s1;
    for (auto x : vec1)
    {
        int smallest = INT_MAX;
        for (auto y : x) smallest = min(y, smallest);
        vector <vector <int> > vec2;
        for (int i = 0; i < 6; i++)
        {
            vec2.push_back(x);
            rotate(x.begin(), x.begin() + 1, x.end());
        }
        reverse(x.begin(), x.end());
        for (int i = 0; i < 6; i++)
        {
            vec2.push_back(x);
            rotate(x.begin(), x.begin() + 1, x.end());
        }
        vector <int> tmp = *min_element(vec2.begin(), vec2.end());
        if (s1.count(tmp))
        {
            cout << "Twin snowflakes found.\n";
            return 0;
        }
        s1.insert(tmp);
    }
    cout << "No two snowflakes are alike.\n";
}
