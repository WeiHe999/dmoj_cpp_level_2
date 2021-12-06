#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    unordered_map <int, int> working = {{0, false}, {1, false}, {2, false}, {3, false}, {4, false}, {5, false}, {6, false}, {7, false}, {8, false}, {9, false}};
    string t, all;
    getline(cin, t);
    getline(cin, all);
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    int s = stoi(t.substr(6, 2));
    int time1 = s + (60 * m) + (3600 * h);
    for (char c : all) working[c - '0'] = true;
    int best_h = 0, best_m = 0, best_s = 0, min = INT_MAX;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                if (working[i / 10] && working[i - i / 10 * 10] && working[j / 10] && working[j - j / 10 * 10] &&
                    working[k / 10] && working[k - k / 10 * 10] && abs((i * 3600 + j * 60 + k) - time1) < min)
                {
                    best_h = i, best_m = j, best_s = k, min = abs((i * 3600 + j * 60 + k) - time1);
                }
            }
        }
    }
    if (best_h <= 9) cout << "0" << best_h << ":";
    else cout << best_h << ":";
    if (best_m <= 9) cout << "0" << best_m << ":";
    else cout << best_m << ":";
    if (best_s <= 9) cout << "0" << best_s << endl;
    else cout << best_s << endl;
}
