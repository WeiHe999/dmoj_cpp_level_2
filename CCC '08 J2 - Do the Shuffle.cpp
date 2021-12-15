#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <char> vec1 = {'A', 'B', 'C', 'D', 'E'};
    int b, n;
    cin >> b >> n;
    while (b != 4)
    {
        for (int c = 0; c < n; c++)
        {
            if (b == 1)
            {
                vec1.emplace_back(vec1[0]);
                vec1.erase(vec1.begin());
            }
            if (b == 2)
            {
                vec1.insert(vec1.begin(), vec1.back());
                vec1.pop_back();
            }
            if (b == 3)
            {
                swap(vec1[0], vec1[1]);
            }
        }
        cin >> b >> n;
    }
    for (auto a : vec1) cout << a << " ";
}
