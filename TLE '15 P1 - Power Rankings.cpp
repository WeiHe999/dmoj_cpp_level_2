#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, p, c;
    cin >> n >> p; cin.ignore();
    string name;
    vector <pair <int, string> > vec1;
    for (int x = 0; x < n; x++)
    {
        getline(cin, name);
        vec1.push_back({0, name});
    }
    for (int a = 0; a < p; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cin >> c;
            vec1[b].first += c;
        }
    }
    sort(vec1.rbegin(), vec1.rend());
    for (int d = 0; d < vec1.size(); d++) cout << d + 3 << ". " << vec1[d].second << endl;
}
