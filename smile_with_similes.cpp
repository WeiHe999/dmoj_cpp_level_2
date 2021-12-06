#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int x, y;
    cin >> x;
    cin >> y;
    cin.ignore();
    vector <string> vec1;
    vector <string> vec2;
    for (int a = 0; a < x; a++)
    {
        string line;
        getline(cin, line);
        vec1.emplace_back(line);
    }
    for (int b = 0; b < y; b++)
        {
            string line;
            getline(cin, line);
            vec2.emplace_back(line);
        }
    for (auto c : vec1)
        {
            for (auto d : vec2)
            {
                cout << c << " as " << d << endl;
            }
        }
}
