#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    vector <vector<char> > vec1;
    vector <char> tmp;
    for (int x = 0; x <= (2 * n); x++)
    {
        tmp.assign(n, '.');
        vec1.push_back(tmp);
    }
    int x = n;
    int y = 0;
    for (auto a : line)
    {
        if (a == '^')
        {
            vec1[x][y] = '/';
            x--;
            y++;
        }
        if (a == 'v')
        {
            x++;
            vec1[x][y] = '\\';
            y++;
        }
        if (a == '>')
        {
            vec1[x][y] = '_';
            y++;
        }
    }
    for (auto b : vec1)
    {
        if (b != tmp)
        {
            for (auto c : b)
            {
                cout << c;
            }
            cout << endl;
        }
    }
}
