#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <vector <int> > vec1 = {{1, 2}, {3, 4}};
    string str1;
    cin >> str1;
    for (auto a : str1)
    {
        vector <vector <int> > vec2;
        if (a == 'H')
        {
            vec2.push_back({vec1[1][0], vec1[1][1]});
            vec2.push_back({vec1[0][0], vec1[0][1]});
            vec1 = vec2;
        }
        else
        {
            vec2.push_back({vec1[0][1], vec1[0][0]});
            vec2.push_back({vec1[1][1], vec1[1][0]});
            vec1 = vec2;
        }
    }
    for (auto b : vec1)
    {
        for (auto c : b) cout << c << " ";
        cout << endl;
    }
}
