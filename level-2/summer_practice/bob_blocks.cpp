#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n, m;
    cin >> n >> m;
    vector <int> vec1;
    int maximum = -1 * INT_MAX;
    for (int x = 0; x < n; x++)
    {
        for (int a = 0; a < m; a++)
        {
            int b;
            cin >> b;
            vec1.emplace_back(b);
            if (b > maximum) maximum = b;
        }
    }
    int s = 0;
    for (auto a : vec1)
    {
        s += (maximum - a);
    }
    cout << s << endl;
}
