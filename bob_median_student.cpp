#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    vector <pair <int, string> > vec1;
    string name;
    int score;
    for (int x = 0; x < n; x++)
    {
        cin >> name >> score;
        vec1.push_back({score, name});
    }
    sort(vec1.begin(), vec1.end());
    cout << vec1[n / 2].second << endl;
}
