#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

vector <string> split (string str1)
{
    vector <string> vv;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vv.emplace_back(word);
    return vv;
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int a, b, x = 1, m = 1, first, last;
    char move = 'd';
    cin >> a >> b;
    vector <vector <int> > spiral(12, vector <int> (12, 0));
    vector <pair <int, int> > p;
    spiral[5][5] = a;
    p.push_back({5, 5});
    vector <int> prev = {5, 5};
    for (int c = a + 1; c <= b; c++)
    {
        x--;
        if (move == 'd')
        {
            prev = {prev[0] + 1, prev[1]};
            spiral[prev[0]][prev[1]] = c;
            p.push_back({prev[0], prev[1]});
            if (x == 0)
            {
                x = m;
                move = 'r';
            }
        }
        else if (move == 'u')
        {
            prev = {prev[0] - 1, prev[1]};
            spiral[prev[0]][prev[1]] = c;
            p.push_back({prev[0], prev[1]});
            if (x == 0)
            {
                x = m;
                move = 'l';
            }
        }
        else if (move == 'r')
        {
            prev = {prev[0], prev[1] + 1};
            spiral[prev[0]][prev[1]] = c;
            p.push_back({prev[0], prev[1]});
            if (x == 0)
            {
                m++;
                x = m;
                move = 'u';
            }
        }
        else
        {
            prev = {prev[0], prev[1] - 1};
            spiral[prev[0]][prev[1]] = c;
            p.push_back({prev[0], prev[1]});
            if (x == 0)
            {
                m++;
                x = m;
                move = 'd';
            }
        }
    }
    sort(p.begin(), p.end());
    first = p[0].first;
    last = p.back().first;
    for (int i = first; i <= last; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (spiral[i][j] == 0 && spiral[i + 1][j] != 0)
            {
                cout << "   ";
            }
            if (spiral[i][j] != 0)
            {
                if (spiral[i][j] < 10) cout << " ";
                cout << spiral[i][j] << " ";
            }
        }
        cout << endl;
    }
}
