#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
	int c, n;
	cin >> c >> n;
	vector <pair <int, int> > vec1;
	unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        int a;
        cin >> a;
        m1[a] = x;
    }
    for (auto b : m1) vec1.push_back({b.second, b.first});
    sort(vec1.begin(), vec1.end());
    cout << vec1.size() << endl;
    for (auto c : vec1) cout << c.second << " ";
    cout << endl;
}
