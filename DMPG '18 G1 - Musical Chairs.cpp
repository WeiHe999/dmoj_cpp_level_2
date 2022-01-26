#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    vector <pair <int, int> > vec1;
    cin >> n >> k;
    int a;
    for (int i = 1; i <= k; i++) {
        cin >> a;
        vec1.push_back({a, 0});
    }
    for (int i = 1; i <= k + 1; i++) {
        cin >> a;
        vec1.push_back({a, i});
    }
    sort(vec1.begin(), vec1.end(), [](pair <int, int> a, pair <int, int> b) {if (a.first == b.first) {return a > b;} else {return b > a;}});
    stack <pair <int, int> > s1;
    for (pair <int, int> b : vec1) {
        if (!s1.empty())
        {
            if (s1.top().second == 0 || b.second != 0) 
            {
                s1.push(b);
            }
            else 
            {
                s1.pop();
            }
        }
        else 
        {
            s1.push(b);
        }
    }
    
    int c = 0;
    while (!s1.empty() && s1.top().second != 0)
    {
        c = s1.top().second;
        s1.pop();
    }
    cout << c << endl;
}
