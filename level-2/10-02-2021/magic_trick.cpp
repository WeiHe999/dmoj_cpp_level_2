#include <bits/stdc++.h>
using namespace std;

vector <int> split (string str1)
{
    vector <int> vec1;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vec1.emplace_back((stoi(word)));
    return vec1;
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, test;
    string b;
    vector <int> order;
    for (int x = 0; x < 5; x++)
    {
        cin >> n; cin.ignore();
        getline(cin, b);
        order = split(b);
        test = 0;
        vector <int> options;
        for (int j = n; j > 0; j--) options.emplace_back(j);
        vector <int> vec1;
        for (auto x : order)
        {
            if (x < 0 || x >= options.size())
            {
                cout << "IMPOSSIBLE" << endl;
                test = 1;
                break;
            }
            vec1.emplace_back(options[x]);
            options.erase(options.begin() + x);
        }
        if (test == 0)
        {
            for (auto a : vec1) cout << a << " ";
            cout << endl;
        }
    }
}
