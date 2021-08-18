#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n;
    cin >> n;
    vector <int> presents;
    for (int x = 0; x < n; x++)
    {
        int present;
        cin >> present;
        presents.emplace_back(present);
    }
    sort(presents.begin(), presents.end());
    int tmp = presents[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (presents[i] >= tmp)
        {
            tmp += presents[i];
            count++;
        }
    }
	cout << count << endl;
}
