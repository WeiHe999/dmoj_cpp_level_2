#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, d;
    cin >> n >> k;
    vector <int> people;
    for (int x = 1; x <= n; x++) people.emplace_back(x);
    vector <int> temp;
    for (int a = 0; a < k; a++)
    {
        cin >> d;
        temp = {};
        for (int b = 0; b < people.size(); b++) if ((b + 1) % d != 0)
        {
            temp.push_back(people[b]);
        }
        people = temp;
    }
    for (auto c : people) cout << c << endl;
}
