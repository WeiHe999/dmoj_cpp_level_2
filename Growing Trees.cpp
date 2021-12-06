#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, s = -1;
    float c;
    cin >> n;
    vector <pair <int, int> > vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        vec1.push_back({a, b});
    }
    for (int a = 0; a < vec1.size(); a++)
    {
        for (int b = a + 1; b < vec1.size(); b++)
        {
            if (vec1[a].first > vec1[b].first)
            {
                if (vec1[b].second > vec1[a].second)
                {
                    c = (vec1[a].first - vec1[b].first) / ((vec1[b].second - vec1[a].second) * 1.0);
                    if (c == round(c))
                    {
                        if (s == -1 || (vec1[a].first - vec1[b].first) / (vec1[b].second - vec1[a].second) < s)
                        {
                            s = (vec1[a].first - vec1[b].first) / (vec1[b].second - vec1[a].second);
                        }
                    }
                }
            }
            else if (vec1[b].first > vec1[a].first)
            {
                if (vec1[a].second > vec1[b].second)
                {
                    c = (vec1[b].first - vec1[a].first) / ((vec1[a].second - vec1[b].second) * 1.0);
                    if (c == round(c))
                    {
                        if (s == -1 || (vec1[b].first - vec1[a].first) / (vec1[a].second - vec1[b].second) < s)
                        {
                            s = (vec1[b].first - vec1[a].first) / (vec1[a].second - vec1[b].second);
                        }
                    }
                }
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << s << endl;
}
