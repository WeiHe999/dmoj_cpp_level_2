#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    string a, must, be, milked, beside, b;
    cin >> n;
    unordered_map <string, vector <string> > m1;
    vector <string> vec1 = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(vec1.begin(), vec1.end());
    vector <vector <string> > vec2;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> must >> be >> milked >> beside >> b;
        m1[b].emplace_back(a);
    }
    bool flag;
    int k, v;
    do
    {
        flag = true;
        for (auto x: m1)
        {
            k = find(vec1.begin(), vec1.end(), x.first) - vec1.begin();
            for (auto y: x.second)
            {
                v = find(vec1.begin(), vec1.end(), y) - vec1.begin();
                if (abs(k - v) != 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) vec2.push_back(vec1); 
    } while (next_permutation(vec1.begin(), vec1.end()));
    for (auto y : *min_element(vec2.begin(), vec2.end())) cout << y << endl;
}
