#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, a, tmp;
    cin >> n;
    bool swap = false, stop = true;
    int swap_ind, stop_val;
    vector <pair <int, int> > sequence;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        if (x == 0) 
        {
            stop_val = a;
        }
        if (a != stop_val) 
        {
            stop = false;
        }
        sequence.push_back({x + 1, a});
        if (x + 1 == a)
        {
            if (swap)
            {
                swap = false;
                tmp = sequence[swap_ind].first;
                sequence[swap_ind] = {sequence[x].first, sequence[swap_ind].second};
                sequence[x] = {tmp, sequence[x].second};
            }
            else
            {
                swap = true;
                swap_ind = x;
            }
        }
    }
    if (stop)
    {
        cout << -1 << endl;
        return 0;
    }
    if (swap)
    {
        for (int b = 0; b < sequence.size(); b++)
        {
            if (b != swap_ind && sequence[b].first != sequence[swap_ind].second && sequence[b].second != sequence[swap_ind].first)
            {
                tmp = sequence[swap_ind].first;
                sequence[swap_ind] = {sequence[b].first, sequence[swap_ind].second};
                sequence[b] = {tmp, sequence[b].second};
                break;
            }
        }
    }
    for (auto c : sequence) cout << c.first << " ";
    cout << endl;
}
