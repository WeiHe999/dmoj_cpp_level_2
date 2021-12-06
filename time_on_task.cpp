#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int mins;
    cin >> mins;
    int c;
    cin >> c;
    vector <int> vec1;
    for (int x = 0; x < c; x++)
    {
        int a;
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    int ind = 0;
    while (mins >= vec1[ind])
    {
        mins -= vec1[ind];
        ind++;
    }
    cout << ind;
}
